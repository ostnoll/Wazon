#include "client.h"
#include "ui_client.h"

//Переменная DBM
extern DBManager *DBM;

//Конструктор
Client::Client(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    this->setWindowTitle("Новый клиент");

    QRegularExpression regex("[A-Za-zА-Яа-я ]+");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->Nameline->setValidator(validator);
    ui->Phoneline->installEventFilter(this);
}

//Деструктор
Client::~Client()
{
    delete ui;
}

//Перенос номера телефона
bool Client::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->Phoneline && event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton)
        {
            ui->Phoneline->setCursorPosition(3);
            return true;
        }
    }
    return QDialog::eventFilter(obj, event);
}

//Кнопка ОК и создания нового клиента
void Client::on_OK_btn_clicked()
{
    {
        QString name = ui->Nameline->text();
        QString phone = ui->Phoneline->text();
        QString pickup = ui->Pickapline->currentText();
        QString address = ui->Addressline->text();

        if (name.isEmpty() || phone.size() < 16 || pickup.isEmpty())
        {
            highlightEmptyFields();
            QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все обязательные поля.");
            return;
        }

        if (DBM->insertClient(name, phone, pickup, address, 0.0, 0.0, 0.0))
        {
            Widget *mainWidget = qobject_cast<Widget *>(this->parentWidget());
            if (mainWidget)
            {
                mainWidget->updateClientTable();
            }
            accept();
        }
        else
        {
            QMessageBox::critical(this, "Ошибка", "Не удалось добавить клиента.");
        }
    }
}

//Проверка пустых полей клиента
void Client::highlightEmptyFields()
{
    QList<QLineEdit*> fields = {ui->Nameline};

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
        if(ui->Phoneline->text().size()<16)
        {
            ui->Phoneline->setStyleSheet("QLineEdit { border: 2px solid red; }");
        }
        else
        {
            ui->Phoneline->setStyleSheet("");
        }
        if(ui->Pickapline->currentIndex() == 0)
        {
            ui->Pickapline->setStyleSheet("QComboBox { border: 2px solid red; }");
        }
        else
        {
            ui->Pickapline->setStyleSheet("");
        }
    }
}

//Кнопка отмены
void Client::on_Cancal_btn_clicked()
{
    reject();
}
