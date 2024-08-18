/********************************************************************************
** Form generated from reading UI file 'order.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDER_H
#define UI_ORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Order
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *Courierlabel;
    QComboBox *CourierBox;
    QPushButton *FillOrder_btn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QTableWidget *OrderTable;
    QHBoxLayout *horizontalLayout;
    QLabel *LoadCapacitylabel;
    QSpacerItem *horizontalSpacer_4;
    QLabel *Commissionlabel;
    QSpacerItem *horizontalSpacer_5;
    QLabel *Pricelabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *OK_btn;
    QPushButton *Cancel_btn;

    void setupUi(QDialog *Order)
    {
        if (Order->objectName().isEmpty())
            Order->setObjectName(QString::fromUtf8("Order"));
        Order->resize(760, 510);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Order->sizePolicy().hasHeightForWidth());
        Order->setSizePolicy(sizePolicy);
        Order->setMinimumSize(QSize(760, 510));
        verticalLayout = new QVBoxLayout(Order);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        Courierlabel = new QLabel(Order);
        Courierlabel->setObjectName(QString::fromUtf8("Courierlabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Courierlabel->sizePolicy().hasHeightForWidth());
        Courierlabel->setSizePolicy(sizePolicy1);
        Courierlabel->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(Courierlabel);

        CourierBox = new QComboBox(Order);
        CourierBox->setObjectName(QString::fromUtf8("CourierBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CourierBox->sizePolicy().hasHeightForWidth());
        CourierBox->setSizePolicy(sizePolicy2);
        CourierBox->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(CourierBox);

        FillOrder_btn = new QPushButton(Order);
        FillOrder_btn->setObjectName(QString::fromUtf8("FillOrder_btn"));
        FillOrder_btn->setEnabled(false);
        FillOrder_btn->setMinimumSize(QSize(125, 25));

        horizontalLayout_2->addWidget(FillOrder_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        OrderTable = new QTableWidget(Order);
        OrderTable->setObjectName(QString::fromUtf8("OrderTable"));
        OrderTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout->addWidget(OrderTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LoadCapacitylabel = new QLabel(Order);
        LoadCapacitylabel->setObjectName(QString::fromUtf8("LoadCapacitylabel"));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        LoadCapacitylabel->setFont(font);

        horizontalLayout->addWidget(LoadCapacitylabel);

        horizontalSpacer_4 = new QSpacerItem(15, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        Commissionlabel = new QLabel(Order);
        Commissionlabel->setObjectName(QString::fromUtf8("Commissionlabel"));
        Commissionlabel->setFont(font);

        horizontalLayout->addWidget(Commissionlabel);

        horizontalSpacer_5 = new QSpacerItem(15, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        Pricelabel = new QLabel(Order);
        Pricelabel->setObjectName(QString::fromUtf8("Pricelabel"));
        Pricelabel->setFont(font);

        horizontalLayout->addWidget(Pricelabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OK_btn = new QPushButton(Order);
        OK_btn->setObjectName(QString::fromUtf8("OK_btn"));
        OK_btn->setEnabled(false);

        horizontalLayout->addWidget(OK_btn);

        Cancel_btn = new QPushButton(Order);
        Cancel_btn->setObjectName(QString::fromUtf8("Cancel_btn"));

        horizontalLayout->addWidget(Cancel_btn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Order);

        QMetaObject::connectSlotsByName(Order);
    } // setupUi

    void retranslateUi(QDialog *Order)
    {
        Order->setWindowTitle(QCoreApplication::translate("Order", "Dialog", nullptr));
        Courierlabel->setText(QCoreApplication::translate("Order", "\320\232\321\203\321\200\321\214\320\265\321\200", nullptr));
        FillOrder_btn->setText(QCoreApplication::translate("Order", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        LoadCapacitylabel->setText(QCoreApplication::translate("Order", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\260:", nullptr));
        Commissionlabel->setText(QCoreApplication::translate("Order", "\320\236\320\261\321\211\320\260\321\217 \320\272\320\276\320\274\320\274\320\270\321\201\321\201\320\270\321\217:", nullptr));
        Pricelabel->setText(QCoreApplication::translate("Order", "\320\241\321\203\320\274\320\274\320\260 \320\277\320\273\320\260\321\202\320\265\320\266\320\260:", nullptr));
        OK_btn->setText(QCoreApplication::translate("Order", "\320\236\320\232", nullptr));
        Cancel_btn->setText(QCoreApplication::translate("Order", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Order: public Ui_Order {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDER_H
