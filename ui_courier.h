/********************************************************************************
** Form generated from reading UI file 'courier.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURIER_H
#define UI_COURIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Courier
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *Namelabel;
    QLineEdit *Nameline;
    QLabel *Phonelabel;
    QLineEdit *Phoneline;
    QLabel *Transportlabel;
    QLineEdit *Transportline;
    QLabel *TransportNumlabel;
    QLineEdit *TransportNumline;
    QLabel *Loadcapacitylabel;
    QLineEdit *Loadcapacityline;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *OK_btn;
    QPushButton *Cancel_btn;

    void setupUi(QDialog *Courier)
    {
        if (Courier->objectName().isEmpty())
            Courier->setObjectName(QString::fromUtf8("Courier"));
        Courier->resize(420, 196);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Courier->sizePolicy().hasHeightForWidth());
        Courier->setSizePolicy(sizePolicy);
        Courier->setMinimumSize(QSize(420, 196));
        verticalLayout = new QVBoxLayout(Courier);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        Namelabel = new QLabel(Courier);
        Namelabel->setObjectName(QString::fromUtf8("Namelabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, Namelabel);

        Nameline = new QLineEdit(Courier);
        Nameline->setObjectName(QString::fromUtf8("Nameline"));
        QFont font;
        font.setBold(true);
        Nameline->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, Nameline);

        Phonelabel = new QLabel(Courier);
        Phonelabel->setObjectName(QString::fromUtf8("Phonelabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Phonelabel);

        Phoneline = new QLineEdit(Courier);
        Phoneline->setObjectName(QString::fromUtf8("Phoneline"));
        Phoneline->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, Phoneline);

        Transportlabel = new QLabel(Courier);
        Transportlabel->setObjectName(QString::fromUtf8("Transportlabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, Transportlabel);

        Transportline = new QLineEdit(Courier);
        Transportline->setObjectName(QString::fromUtf8("Transportline"));
        Transportline->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, Transportline);

        TransportNumlabel = new QLabel(Courier);
        TransportNumlabel->setObjectName(QString::fromUtf8("TransportNumlabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, TransportNumlabel);

        TransportNumline = new QLineEdit(Courier);
        TransportNumline->setObjectName(QString::fromUtf8("TransportNumline"));
        TransportNumline->setFont(font);

        formLayout->setWidget(3, QFormLayout::FieldRole, TransportNumline);

        Loadcapacitylabel = new QLabel(Courier);
        Loadcapacitylabel->setObjectName(QString::fromUtf8("Loadcapacitylabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, Loadcapacitylabel);

        Loadcapacityline = new QLineEdit(Courier);
        Loadcapacityline->setObjectName(QString::fromUtf8("Loadcapacityline"));
        Loadcapacityline->setFont(font);

        formLayout->setWidget(4, QFormLayout::FieldRole, Loadcapacityline);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OK_btn = new QPushButton(Courier);
        OK_btn->setObjectName(QString::fromUtf8("OK_btn"));

        horizontalLayout->addWidget(OK_btn);

        Cancel_btn = new QPushButton(Courier);
        Cancel_btn->setObjectName(QString::fromUtf8("Cancel_btn"));

        horizontalLayout->addWidget(Cancel_btn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Courier);

        QMetaObject::connectSlotsByName(Courier);
    } // setupUi

    void retranslateUi(QDialog *Courier)
    {
        Courier->setWindowTitle(QCoreApplication::translate("Courier", "Dialog", nullptr));
        Namelabel->setText(QCoreApplication::translate("Courier", "\320\244\320\230\320\236", nullptr));
        Phonelabel->setText(QCoreApplication::translate("Courier", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        Phoneline->setInputMask(QCoreApplication::translate("Courier", "+7 000 000 00 00", nullptr));
        Phoneline->setText(QCoreApplication::translate("Courier", "+7    ", nullptr));
        Transportlabel->setText(QCoreApplication::translate("Courier", "\320\242\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\320\276\320\265 \321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\276", nullptr));
        TransportNumlabel->setText(QCoreApplication::translate("Courier", "\320\235\320\276\320\274\320\265\321\200 \320\274\320\260\321\210\320\270\320\275\321\213", nullptr));
        TransportNumline->setInputMask(QString());
        Loadcapacitylabel->setText(QCoreApplication::translate("Courier", "\320\223\321\200\321\203\320\267\320\276\320\277\320\276\320\264\321\212\320\265\320\274\320\275\320\276\321\201\321\202\321\214", nullptr));
        OK_btn->setText(QCoreApplication::translate("Courier", "\320\236\320\232", nullptr));
        Cancel_btn->setText(QCoreApplication::translate("Courier", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Courier: public Ui_Courier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURIER_H
