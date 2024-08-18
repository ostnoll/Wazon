#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Wazon)
{
    ui->setupUi(this);
    connect(DBM, &DBManager::productsTableUpdated, this, &Widget::updateProductTable);
    connect(DBM,&DBManager::clientTableUpdated,this,&Widget::updateClientTable);

    // Создание таблицы клиентов
    ui->ClientTable->setColumnWidth(0,200);
    ui->ClientTable->setColumnWidth(1,100);
    ui->ClientTable->setColumnWidth(2,115);
    ui->ClientTable->setColumnWidth(3,140);
    ui->ClientTable->setColumnWidth(4,50);
    ui->ClientTable->setColumnWidth(5,50);
    ui->ClientTable->setColumnWidth(6,50);
    ui->ClientTable->horizontalHeader()->setStretchLastSection(true);
    ui->ClientTable->setSortingEnabled(true);

    // Создание таблицы курьеров
    ui->CourierTable->setColumnWidth(0,200);
    ui->CourierTable->setColumnWidth(1,100);
    ui->CourierTable->setColumnWidth(2,115);
    ui->CourierTable->setColumnWidth(3,120);
    ui->CourierTable->setColumnWidth(4,50);
    ui->CourierTable->horizontalHeader()->setStretchLastSection(true);
    ui->CourierTable->setSortingEnabled(true);

    ui->ClientBox->setCurrentIndex(0);
    ui->OrderBox->setCurrentIndex(0);

    // Создание таблицы товаров
    ui->ProductTable->setColumnWidth(0,240);
    ui->ProductTable->setColumnWidth(1,50);
    ui->ProductTable->setColumnWidth(2,50);
    ui->ProductTable->setColumnWidth(3,50);
    ui->ProductTable->setColumnWidth(4,50);
    ui->ProductTable->setColumnWidth(5,75);
    ui->ProductTable->setColumnWidth(6,90);
    ui->ProductTable->setColumnWidth(7,70);
    ui->ProductTable->setColumnWidth(8,70);
    ui->ProductTable->horizontalHeader()->setStretchLastSection(true);
    ui->ProductTable->setSortingEnabled(true);

    DBM->fillClientTable(ui->ClientTable);
    DBM->fillCourierTable(ui->CourierTable);
    DBM->fillProductTable(ui->ProductTable, false);
    DBM->fillHistoryTable(ui->HistoryTable);
}

//Деструктор
Widget::~Widget()
{
    delete ui;
}

//Переключение Клиента - Курьера
void Widget::on_Client_Courier_btn_clicked()
{
    if(ui->ClientBox->currentIndex()==0)
    {
        ui->ClientBox->setCurrentIndex(1);
        ui->Client_Courier_btn->setText("Клиенты");
    }
    else
    {
        ui->ClientBox->setCurrentIndex(0);
        ui->Client_Courier_btn->setText("Курьеры");
    }
}

//Переключение Активных - Истории заказов
void Widget::on_ActivOrd_History_btn_clicked()
{
    if(ui->OrderBox->currentIndex()==0)
    {
        ui->OrderBox->setCurrentIndex(1);
        ui->ActivOrd_History_btn->setText("Активные");
    }
    else
    {
        ui->OrderBox->setCurrentIndex(0);
        ui->ActivOrd_History_btn->setText("История");
    }
}

//Вызов диалога нового клиента
void Widget::on_NewClient_btn_clicked()
{
    ui->ClientBox->setCurrentIndex(0);
    Client dialog(this);
    dialog.exec();
}

//Вызов диалога нового курьера
void Widget::on_NewCourier_btn_clicked()
{
    ui->ClientBox->setCurrentIndex(1);
    ui->Client_Courier_btn->setText("Клиенты");
    Courier dialog(this);
    dialog.exec();
}

//Вызов диалога нового товара
void Widget::on_NewOrder_btn_clicked()
{
    ui->ClientBox->setCurrentIndex(0);
    Product dialog(this);
    dialog.exec();
}

//Вызов диалога нового маршрута
void Widget::on_NewRoute_btn_clicked()
{
    Order dialog(this);
    dialog.exec();
}

// Обновление таблицы курьеров
void Widget::updateCourierTable()
{
    DBM->fillCourierTable(ui->CourierTable);
}

// Обновление таблицы товаров
void Widget::updateProductTable()
{
    DBM->fillProductTable(ui->ProductTable, false);
    DBM->fillHistoryTable(ui->HistoryTable);
}

// Обновление таблицы товаров
void Widget::updateClientTable()
{
    DBM->fillClientTable(ui->ClientTable);
}

//Чекбокс для выделения просроченных заказов
void Widget::on_OverdueBox_stateChanged(int arg1)
{
    DBM->fillProductTable(ui->ProductTable, arg1 == Qt::Checked);
}

//Выделение товаров клиента
void Widget::on_ClientTable_itemSelectionChanged()
{
    QList<QTableWidgetSelectionRange> selectedRanges = ui->ClientTable->selectedRanges();
    if (!selectedRanges.isEmpty())
    {
        int selectedRow = selectedRanges.first().topRow();
        QTableWidgetItem *clientPhoneItem = ui->ClientTable->item(selectedRow, 1); // Предполагается, что телефон клиента находится во втором столбце
        if (clientPhoneItem)
        {
            QString clientPhone = clientPhoneItem->text();
            qDebug() << "Selected client phone:" << clientPhone;
            QString clientId = DBM->getClientIdFromPhone(clientPhone);

            if (!clientId.isEmpty())
            {
                qDebug() << "Client ID:" << clientId;
                DBM->highlightClientOrders(ui->ProductTable, clientId);
            }
            else
            {
                qWarning() << "Client ID not found for phone:" << clientPhone;
            }
        }
        else
        {
            qWarning() << "Client phone item not found in row:" << selectedRow;
        }
    }
    else
    {
        qWarning() << "No rows selected in ClientTable";
    }
}









