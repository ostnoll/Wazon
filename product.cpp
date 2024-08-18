#include "product.h"
#include "ui_product.h"

extern DBManager *DBM;

//Конструктор
Product::Product(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Product)
    , isDateSelected(false)
{
    ui->setupUi(this);
    this->setWindowTitle("Новый заказ");
    ui->Clientline->setPlaceholderText("Поиск клиентов...");
    QRegularExpression regex1("[0-9 .]+");
    QRegularExpressionValidator *validator1 = new QRegularExpressionValidator(regex1, this);
    ui->Priceline->setValidator(validator1);
    ui->Weightline->setValidator(validator1);
    ui->Quantityline->setValidator(validator1);
    ui->Articleline->setValidator(validator1);
    QCompleter *completer = new QCompleter(this);
    completer->setCompletionMode(QCompleter::InlineCompletion);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->Clientline->setCompleter(completer);
    ui->Clientline->setFocus();
}

//Деструктор
Product::~Product()
{
    delete ui;
}

//Автозаполнение в зависимости от ввода пользователя
void Product::on_Clientline_textChanged(const QString &text)
{
    QStringList items;
    QSet<QString> uniqueItems;

    bool searchByPhone = text.startsWith("+");

    if (searchByPhone)
    {
        // Поиск по телефону
        QVector<int> keysByPhone = DBM->searchClientByPhone(text);
        for (int key : keysByPhone)
        {
            uniqueItems.insert(DBM->getClientInfo(key, true));
        }
    }
    else
    {
        // Поиск по имени
        QVector<int> keysByName = DBM->searchClientByName(text);
        for (int key : keysByName)
        {
            uniqueItems.insert(DBM->getClientInfo(key, false));
        }

        // Поиск по телефону, чтобы добавить возможные совпадения, если есть
        QVector<int> keysByPhone = DBM->searchClientByPhone(text);
        for (int key : keysByPhone)
        {
            uniqueItems.insert(DBM->getClientInfo(key, true));
        }
    }

    items << uniqueItems.values();

    QCompleter *completer = ui->Clientline->completer();
    QStringListModel *model = new QStringListModel(items, completer);
    completer->setModel(model);
}

//Кнопка отмены
void Product::on_Cancal_btn_clicked()
{
    reject();
}

//Кнопка ОК и создания нового товара
void Product::on_OK_btn_clicked()
{
    {
        QString client = ui->Clientline->text();
        QString price = ui->Priceline->text();
        QString weight = ui->Weightline->text();
        QString quantity = ui->Quantityline->text();
        QString size = ui->SizeBox->currentText();
        QString platform = ui->PlatformBox->currentText();
        QString article = ui->Articleline->text();
        QString creatonDate = convertDateFormat(ui->DeliveryDateWidget->selectedDate().currentDate());
        QString deliveryDate = convertDateFormat(ui->DeliveryDateWidget->selectedDate());

        int intSize = 0;

        if (size == "XS")
        {
            intSize = 1;
        }
        else if (size == "S")
        {
            intSize = 2;
        }
        else if (size == "M")
        {
            intSize = 4;
        }
        else if (size == "L")
        {
            intSize = 8;
        }
        else
        {
            intSize = 0;
        }

        int commission = (price.toInt()*0.13+weight.toInt()*0.4+intSize*0.25)*quantity.toInt();

        if (client.isEmpty() || price.isEmpty() || weight.isEmpty() || quantity.isEmpty() || article.isEmpty() ||
            ui->SizeBox->currentIndex() == 0 || ui->PlatformBox->currentIndex() == 0 || !isDateSelected)
        {
            highlightEmptyFields();
            QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все обязательные поля.");
            return;
        }

        if (!ui->DeliveryDateWidget->selectedDate().isValid())
        {
            QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите дату доставки.");
            return;
        }

        if (DBM->insertProduct(client, price, weight, quantity, size, platform, article, creatonDate, deliveryDate, commission, DBM->getClientIdFromInfo(client)))
        {
            Widget *mainWidget = qobject_cast<Widget *>(this->parentWidget());
            if (mainWidget)
            {
                mainWidget->updateProductTable();
            }

            accept();
        }
        else
        {
            QMessageBox::critical(this, "Ошибка", "Не удалось добавить клиента.");
        }
    }
}

//Проверка пустых полей товара
void Product::highlightEmptyFields()
{
    QList<QLineEdit*> fields = {ui->Clientline, ui->Priceline, ui->Weightline, ui->Quantityline, ui->Articleline};

    for (QLineEdit *field : fields)
    {
        if (field->text().isEmpty())
        {
            field->setStyleSheet("QLineEdit { border: 2px solid red; }");
        }
        else
        {
            field->setStyleSheet("");
        }
        if(ui->SizeBox->currentIndex() == 0)
        {
            ui->SizeBox->setStyleSheet("QComboBox { border: 2px solid red; }");
        }
        else
        {
            ui->SizeBox->setStyleSheet("");
        }
        if(ui->PlatformBox->currentIndex() == 0)
        {
            ui->PlatformBox->setStyleSheet("QComboBox { border: 2px solid red; }");
        }
        else
        {
            ui->PlatformBox->setStyleSheet("");
        }
        if(isDateSelected)
        {
            ui->DeliveryDateWidget->setStyleSheet("QComboBox { border: 2px solid red; }");
        }
        else
        {
            ui->DeliveryDateWidget->setStyleSheet("");
        }
    }
}

//Конвертер формата даты
QString Product::convertDateFormat(const QDate &date)
{
    QString outputFormat = "dd.MM.yyyy";
    QString formattedDate = date.toString(outputFormat);

    return formattedDate;
}

//Проверка на установку даты доставки
void Product::on_DeliveryDateWidget_selectionChanged()
{
    isDateSelected = true;
}

