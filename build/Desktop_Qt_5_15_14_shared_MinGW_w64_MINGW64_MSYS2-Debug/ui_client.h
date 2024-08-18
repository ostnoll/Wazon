/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *Namelabel;
    QLineEdit *Nameline;
    QLabel *Phonelabel;
    QLineEdit *Phoneline;
    QLabel *Pickaplabel;
    QLabel *Addresslabel;
    QLineEdit *Addressline;
    QComboBox *Pickapline;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *OK_btn;
    QPushButton *Cancal_btn;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(420, 166);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Client->sizePolicy().hasHeightForWidth());
        Client->setSizePolicy(sizePolicy);
        Client->setMinimumSize(QSize(420, 166));
        verticalLayout = new QVBoxLayout(Client);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        Namelabel = new QLabel(Client);
        Namelabel->setObjectName(QString::fromUtf8("Namelabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Namelabel);

        Nameline = new QLineEdit(Client);
        Nameline->setObjectName(QString::fromUtf8("Nameline"));
        QFont font;
        font.setBold(true);
        Nameline->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, Nameline);

        Phonelabel = new QLabel(Client);
        Phonelabel->setObjectName(QString::fromUtf8("Phonelabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Phonelabel);

        Phoneline = new QLineEdit(Client);
        Phoneline->setObjectName(QString::fromUtf8("Phoneline"));
        Phoneline->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, Phoneline);

        Pickaplabel = new QLabel(Client);
        Pickaplabel->setObjectName(QString::fromUtf8("Pickaplabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, Pickaplabel);

        Addresslabel = new QLabel(Client);
        Addresslabel->setObjectName(QString::fromUtf8("Addresslabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, Addresslabel);

        Addressline = new QLineEdit(Client);
        Addressline->setObjectName(QString::fromUtf8("Addressline"));
        Addressline->setFont(font);

        formLayout->setWidget(3, QFormLayout::FieldRole, Addressline);

        Pickapline = new QComboBox(Client);
        Pickapline->addItem(QString());
        Pickapline->addItem(QString());
        Pickapline->addItem(QString());
        Pickapline->addItem(QString());
        Pickapline->addItem(QString());
        Pickapline->addItem(QString());
        Pickapline->addItem(QString());
        Pickapline->setObjectName(QString::fromUtf8("Pickapline"));

        formLayout->setWidget(2, QFormLayout::FieldRole, Pickapline);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OK_btn = new QPushButton(Client);
        OK_btn->setObjectName(QString::fromUtf8("OK_btn"));

        horizontalLayout->addWidget(OK_btn);

        Cancal_btn = new QPushButton(Client);
        Cancal_btn->setObjectName(QString::fromUtf8("Cancal_btn"));

        horizontalLayout->addWidget(Cancal_btn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Dialog", nullptr));
        Namelabel->setText(QCoreApplication::translate("Client", "\320\244\320\230\320\236", nullptr));
        Phonelabel->setText(QCoreApplication::translate("Client", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        Phoneline->setInputMask(QCoreApplication::translate("Client", "+7 000 000 00 00", nullptr));
        Phoneline->setText(QCoreApplication::translate("Client", "+7    ", nullptr));
        Pickaplabel->setText(QCoreApplication::translate("Client", "\320\221\320\273\320\270\320\266\320\260\320\271\321\210\320\270\320\271 \320\237\320\222\320\227", nullptr));
        Addresslabel->setText(QCoreApplication::translate("Client", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        Pickapline->setItemText(0, QCoreApplication::translate("Client", "\320\235\320\265\321\202", nullptr));
        Pickapline->setItemText(1, QCoreApplication::translate("Client", "\320\233\320\265\320\275\320\270\320\275\321\201\320\272\320\270\320\271, 63 ", nullptr));
        Pickapline->setItemText(2, QCoreApplication::translate("Client", "\320\247\320\265\320\273\321\216\321\201\320\272\320\270\320\275\321\206\320\265\320\262, 151", nullptr));
        Pickapline->setItemText(3, QCoreApplication::translate("Client", "\320\230\320\273\321\214\320\270\321\207\320\260, 99\320\221", nullptr));
        Pickapline->setItemText(4, QCoreApplication::translate("Client", "\320\220\321\200\321\202\321\221\320\274\320\260, 147\320\220", nullptr));
        Pickapline->setItemText(5, QCoreApplication::translate("Client", "\320\232\320\276\320\274\320\274\321\203\320\275\320\260\321\200\320\276\320\262, 34 ", nullptr));
        Pickapline->setItemText(6, QCoreApplication::translate("Client", "\320\236\321\201\321\202\321\200\320\276\320\262\321\201\320\272\320\276\320\263\320\276, 12", nullptr));

        OK_btn->setText(QCoreApplication::translate("Client", "\320\236\320\232", nullptr));
        Cancal_btn->setText(QCoreApplication::translate("Client", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
