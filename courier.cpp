#include "courier.h"
#include "ui_courier.h"

//Переменная DBM
extern DBManager *DBM;

//Конструктор
Courier::Courier(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Courier)
{
    ui->setupUi(this);
    this->setWindowTitle("Новый курьер");

    QRegularExpression regex1("[A-Za-zА-Яа-я ]+");
    QRegularExpression regex2("[А-Я]{1}[0-9]{3}[А-Я]{2} [0-9]{2}");
    QRegularExpression regex3("[0-9 ]+");

    QRegularExpressionValidator *validator1 = new QRegularExpressionValidator(regex1, this);
    QRegularExpressionValidator *validator2 = new QRegularExpressionValidator(regex2, this);
    QRegularExpressionValidator *validator3 = new QRegularExpressionValidator(regex3, this);

    ui->Nameline->setValidator(validator1);
    ui->TransportNumline->setValidator(validator2);
    ui->Loadcapacityline->setValidator(validator3);
    ui->Phoneline->installEventFilter(this);
    ui->TransportNumline->installEventFilter(this);
}

//Деструктор
Courier::~Courier()
{
    delete ui;
}

//Перенос курсора номера телефона и машины
bool Courier::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton)
        {
            if (obj == ui->Phoneline)
            {
                ui->Phoneline->setCursorPosition(3);
                return true;
            }
            else if (obj == ui->TransportNumline)
            {
                ui->TransportNumline->setCursorPosition(0);
                return true;
            }
        }
    }
    return QDialog::eventFilter(obj, event);
}

//Кнопка ОК и создания нового курьера
void Courier::on_OK_btn_clicked()
{
    bool ok;
    QString name = ui->Nameline->text();
    QString phone = ui->Phoneline->text();
    QString transport = ui->Transportline->text();
    QString transportNum = ui->TransportNumline->text();
    QString loadcapacity = ui->Loadcapacityline->text();

    if (name.isEmpty() || phone.size() < 16 || transport.isEmpty() || transportNum.size() < 9 || loadcapacity.isEmpty())
    {
        highlightEmptyFields();
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все обязательные поля.");
        return;
    }

    if (DBM->insertCourier(ui->Nameline->text(), ui->Phoneline->text(), ui->Transportline->text(), ui->TransportNumline->text(), ui->Loadcapacityline->text().toUInt(&ok)))
    {
        Widget *mainWidget = qobject_cast<Widget *>(this->parentWidget());
        if (mainWidget)
        {
            mainWidget->updateCourierTable();
        }
    }
    accept();
}

//Проверка пустых полей курьера
void Courier::highlightEmptyFields()
{
    QList<QLineEdit*> fields = {ui->Nameline, ui->Transportline, ui->Loadcapacityline};

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
        if(ui->TransportNumline->text().size()<9)
        {
            ui->TransportNumline->setStyleSheet("QLineEdit { border: 2px solid red; }");
        }
        else
        {
            ui->TransportNumline->setStyleSheet("");
        }
    }
}

//Кнопка отмены
void Courier::on_Cancel_btn_clicked()
{
    reject();
}

