#include "order.h"
#include "ui_order.h"

extern DBManager *DBM;

// Конструктор
Order::Order(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Order)
{
    ui->setupUi(this);
    this->setWindowTitle("Формирование маршрута");

    ui->LoadCapacitylabel->setVisible(false);
    ui->Commissionlabel->setVisible(false);
    ui->Pricelabel->setVisible(false);

    ui->CourierBox->addItem("Нет", -1);

    QList<QPair<int, QString>> couriers = DBM->getCouriersList();
    for (const QPair<int, QString>& courier : couriers)
    {
        ui->CourierBox->addItem(courier.second, courier.first);
    }
}

//Деструктор
Order::~Order()
{
    delete ui;
}

//Возвращение ID выбранного курьера
int Order::getSelectCourierID()
{
    return ui->CourierBox->currentData().toInt();
}

//Разблокирование кнопки заполнения курьера
void Order::on_CourierBox_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->FillOrder_btn->setEnabled(false);
    }
    else
    {
        ui->FillOrder_btn->setEnabled(true);
    }
}

//Заполнение курьера
void Order::on_FillOrder_btn_clicked()
{
    QList<QVariantMap> products = DBM->getProductsSortedByDeliveryDate();

    ui->OrderTable->setColumnCount(5);

    QStringList headers;
    headers << "ПВЗ" << "Клиент" << "Дата доставки" << "Артикул" << "Сумма платежа";
    ui->OrderTable->setHorizontalHeaderLabels(headers);

    int courierLoadCapacity = DBM->getCourierLoadCapacity(getSelectCourierID());
    int productWeightSum = 0;
    int commissionSum = 0;
    int priceSum = 0;
    int rowCount = 0;
    QSet<int> addedProductIds;

    // Сначала добавляем все просроченные заказы
    for (int row = 0; row < products.size() && productWeightSum < courierLoadCapacity; ++row)
    {
        QVariantMap product = products[row];
        int productWeight = product["weight"].toInt() * product["quantity"].toInt();
        int productCommission = product["commission"].toInt();
        int productPrice = product["price"].toInt() * product["quantity"].toInt();

        if (productWeightSum + productWeight <= courierLoadCapacity && !addedProductIds.contains(product["id"].toInt()))
        {
            ui->OrderTable->insertRow(rowCount);

            QTableWidgetItem* pickupItem = new QTableWidgetItem(product["pickup"].toString());
            pickupItem->setData(Qt::UserRole, product["id"].toInt());
            ui->OrderTable->setItem(rowCount, 0, pickupItem);
            ui->OrderTable->setItem(rowCount, 1, new QTableWidgetItem(product["client"].toString()));
            ui->OrderTable->setItem(rowCount, 2, new QTableWidgetItem(product["deliveryDate"].toString()));
            ui->OrderTable->setItem(rowCount, 3, new QTableWidgetItem(product["article"].toString()));
            int totalCommission = (product["price"].toInt() * product["quantity"].toInt()) + product["commission"].toInt();
            ui->OrderTable->setItem(rowCount, 4, new QTableWidgetItem(QString::number(totalCommission)));


            ui->OrderTable->setColumnWidth(0,120);
            ui->OrderTable->setColumnWidth(1,300);
            ui->OrderTable->setColumnWidth(2,100);
            ui->OrderTable->setColumnWidth(3,100);
            ui->OrderTable->setColumnWidth(4,100);
            ui->OrderTable->horizontalHeader()->setStretchLastSection(true);

            productWeightSum += productWeight;
            commissionSum += productCommission;
            priceSum += productPrice;
            rowCount++;
            addedProductIds.insert(product["id"].toInt()); // Добавляем ID товара в множество
        }
        else
        {
            break;
        }
    }

    // Теперь добавляем оставшиеся заказы, учитывая ограничение по грузоподъемности
    for (int row = 0; row < products.size(); ++row)
    {
        QVariantMap product = products[row];
        int productWeight = product["weight"].toInt() * product["quantity"].toInt();
        int productCommission = product["commission"].toInt();
        int productPrice = product["price"].toInt() * product["quantity"].toInt();

        // Пропускаем уже добавленные просроченные заказы и проверяем на превышение грузоподъемности
        if (!addedProductIds.contains(product["id"].toInt()) &&
            productWeightSum + productWeight <= courierLoadCapacity)
        {
            ui->OrderTable->insertRow(rowCount);

            ui->OrderTable->setItem(rowCount, 0, new QTableWidgetItem(product["pickup"].toString()));
            ui->OrderTable->setItem(rowCount, 1, new QTableWidgetItem(product["client"].toString()));
            ui->OrderTable->setItem(rowCount, 2, new QTableWidgetItem(product["deliveryDate"].toString()));
            ui->OrderTable->setItem(rowCount, 3, new QTableWidgetItem(product["article"].toString()));
            int totalCommission = (product["price"].toInt() * product["quantity"].toInt()) + product["commission"].toInt();
            ui->OrderTable->setItem(rowCount, 4, new QTableWidgetItem(QString::number(totalCommission)));

            ui->OrderTable->setColumnWidth(0,120);
            ui->OrderTable->setColumnWidth(1,300);
            ui->OrderTable->setColumnWidth(2,100);
            ui->OrderTable->setColumnWidth(3,100);
            ui->OrderTable->setColumnWidth(4,100);
            ui->OrderTable->horizontalHeader()->setStretchLastSection(true);

            productWeightSum += productWeight;
            commissionSum += productCommission;
            priceSum += productPrice;
            rowCount++;
        }
        else
        {
            break;
        }
    }

    priceSum+=commissionSum;

    ui->LoadCapacitylabel->setVisible(true);
    ui->LoadCapacitylabel->setText(QString("Текущая загрузка:    %2 \\ %1")
                                       .arg(productWeightSum)
                                       .arg(courierLoadCapacity));

    ui->Commissionlabel->setVisible(true);
    ui->Commissionlabel->setText(QString("Общая комиссия:    %1 руб.")
                                       .arg(commissionSum));

    ui->Pricelabel->setVisible(true);
    ui->Pricelabel->setText(QString("Общая сумма:    %1 руб.")
                                .arg(priceSum));
    ui->OK_btn->setEnabled(true);
}

//Кнопка отмены
void Order::on_Cancel_btn_clicked()
{
    reject();
}

//Подтверждение загрузки курьера
void Order::on_OK_btn_clicked()
{
    QList<int> productIDsToRemove;

    for (int row = 0; row < ui->OrderTable->rowCount(); ++row)
    {
        int productID = ui->OrderTable->item(row, 0)->data(Qt::UserRole).toInt();
        productIDsToRemove.append(productID);
    }

    for (int productID : productIDsToRemove)
    {
        DBM->moveProductToHistory(productID);
    }

    DBM->removeProductsFromTable(productIDsToRemove);
    exportTableToPDF(ui->OrderTable);

    this->accept();
}

//Экспорт PDF
void Order::exportTableToPDF(QTableWidget* table)
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить PDF", "", "*.pdf");
    if (fileName.isEmpty()) return;

    if (QFileInfo(fileName).suffix().isEmpty()) {
        fileName.append(".pdf");
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QPainter painter(&printer);

    int y = 0;
    int rowHeight = 30;
    int columnCount = table->columnCount();
    int rowCount = table->rowCount();

    QPageLayout layout = printer.pageLayout();
    QRect pageRect = layout.paintRectPixels(printer.resolution());

    QVector<int> columnWidths = {70, 210, 70, 80, 70};
    int columnSpacing = 10;

    int x = 0;
    for (int col = 0; col < columnCount; ++col)
    {
        QRect rect(x, y, columnWidths[col], rowHeight);
        painter.drawText(rect, Qt::AlignLeft, table->horizontalHeaderItem(col)->text());
        x += columnWidths[col] + columnSpacing;
    }
    y += rowHeight;

    for (int row = 0; row < rowCount; ++row)
    {
        if (y + rowHeight > pageRect.height())
        {
            printer.newPage();
            y = 0;

            x = 0;
            for (int col = 0; col < columnCount; ++col)
            {
                QRect rect(x, y, columnWidths[col], rowHeight);
                painter.drawText(rect, Qt::AlignLeft, table->horizontalHeaderItem(col)->text());
                x += columnWidths[col] + columnSpacing;
            }
            y += rowHeight;
        }

        x = 0;
        for (int col = 0; col < columnCount; ++col)
        {
            QRect rect(x, y, columnWidths[col], rowHeight);
            painter.drawText(rect, Qt::AlignLeft, table->item(row, col)->text());
            x += columnWidths[col] + columnSpacing;
        }

        y += rowHeight;
    }

    painter.end();
}






