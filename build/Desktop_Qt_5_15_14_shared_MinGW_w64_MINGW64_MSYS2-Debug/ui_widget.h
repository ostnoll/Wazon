/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wazon
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *OrderBox;
    QWidget *page_1;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *ProductTable;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *HistoryTable;
    QStackedWidget *ClientBox;
    QWidget *page_3;
    QVBoxLayout *verticalLayout;
    QTableWidget *ClientTable;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *CourierTable;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ActivOrd_History_btn;
    QPushButton *Client_Courier_btn;
    QCheckBox *OverdueBox;
    QSpacerItem *horizontalSpacer_1;
    QPushButton *NewClient_btn;
    QPushButton *NewCourier_btn;
    QPushButton *NewOrder_btn;
    QPushButton *NewRoute_btn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Wazon)
    {
        if (Wazon->objectName().isEmpty())
            Wazon->setObjectName(QString::fromUtf8("Wazon"));
        Wazon->resize(1690, 600);
        Wazon->setMinimumSize(QSize(1690, 600));
        verticalLayout_3 = new QVBoxLayout(Wazon);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        OrderBox = new QStackedWidget(Wazon);
        OrderBox->setObjectName(QString::fromUtf8("OrderBox"));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        verticalLayout_2 = new QVBoxLayout(page_1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ProductTable = new QTableWidget(page_1);
        if (ProductTable->columnCount() < 8)
            ProductTable->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        ProductTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        ProductTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ProductTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        ProductTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        ProductTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        ProductTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        ProductTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        ProductTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        ProductTable->setObjectName(QString::fromUtf8("ProductTable"));
        ProductTable->setMinimumSize(QSize(800, 0));
        ProductTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout_2->addWidget(ProductTable);

        OrderBox->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_5 = new QVBoxLayout(page_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        HistoryTable = new QTableWidget(page_2);
        HistoryTable->setObjectName(QString::fromUtf8("HistoryTable"));
        HistoryTable->setMinimumSize(QSize(900, 0));
        HistoryTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout_5->addWidget(HistoryTable);

        OrderBox->addWidget(page_2);

        horizontalLayout_2->addWidget(OrderBox);

        ClientBox = new QStackedWidget(Wazon);
        ClientBox->setObjectName(QString::fromUtf8("ClientBox"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout = new QVBoxLayout(page_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ClientTable = new QTableWidget(page_3);
        if (ClientTable->columnCount() < 7)
            ClientTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        ClientTable->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        ClientTable->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        ClientTable->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        ClientTable->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        ClientTable->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        ClientTable->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        ClientTable->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        ClientTable->setObjectName(QString::fromUtf8("ClientTable"));
        ClientTable->setEnabled(true);
        ClientTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        ClientTable->setShowGrid(true);

        verticalLayout->addWidget(ClientTable);

        ClientBox->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        verticalLayout_4 = new QVBoxLayout(page_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        CourierTable = new QTableWidget(page_4);
        if (CourierTable->columnCount() < 5)
            CourierTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        CourierTable->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        CourierTable->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        CourierTable->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        CourierTable->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        CourierTable->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        CourierTable->setObjectName(QString::fromUtf8("CourierTable"));
        CourierTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout_4->addWidget(CourierTable);

        ClientBox->addWidget(page_4);

        horizontalLayout_2->addWidget(ClientBox);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(8, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ActivOrd_History_btn = new QPushButton(Wazon);
        ActivOrd_History_btn->setObjectName(QString::fromUtf8("ActivOrd_History_btn"));
        ActivOrd_History_btn->setMinimumSize(QSize(120, 50));

        horizontalLayout->addWidget(ActivOrd_History_btn);

        Client_Courier_btn = new QPushButton(Wazon);
        Client_Courier_btn->setObjectName(QString::fromUtf8("Client_Courier_btn"));
        Client_Courier_btn->setMinimumSize(QSize(120, 50));

        horizontalLayout->addWidget(Client_Courier_btn);

        OverdueBox = new QCheckBox(Wazon);
        OverdueBox->setObjectName(QString::fromUtf8("OverdueBox"));

        horizontalLayout->addWidget(OverdueBox);

        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_1);

        NewClient_btn = new QPushButton(Wazon);
        NewClient_btn->setObjectName(QString::fromUtf8("NewClient_btn"));
        NewClient_btn->setMinimumSize(QSize(55, 50));
        NewClient_btn->setMaximumSize(QSize(75, 16777215));

        horizontalLayout->addWidget(NewClient_btn);

        NewCourier_btn = new QPushButton(Wazon);
        NewCourier_btn->setObjectName(QString::fromUtf8("NewCourier_btn"));
        NewCourier_btn->setMinimumSize(QSize(55, 50));
        NewCourier_btn->setMaximumSize(QSize(75, 16777215));

        horizontalLayout->addWidget(NewCourier_btn);

        NewOrder_btn = new QPushButton(Wazon);
        NewOrder_btn->setObjectName(QString::fromUtf8("NewOrder_btn"));
        NewOrder_btn->setMinimumSize(QSize(120, 50));

        horizontalLayout->addWidget(NewOrder_btn);

        NewRoute_btn = new QPushButton(Wazon);
        NewRoute_btn->setObjectName(QString::fromUtf8("NewRoute_btn"));
        NewRoute_btn->setMinimumSize(QSize(120, 50));

        horizontalLayout->addWidget(NewRoute_btn);

        horizontalSpacer_2 = new QSpacerItem(8, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(Wazon);

        OrderBox->setCurrentIndex(1);
        ClientBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Wazon);
    } // setupUi

    void retranslateUi(QWidget *Wazon)
    {
        Wazon->setWindowTitle(QCoreApplication::translate("Wazon", "Widget", nullptr));
        QTableWidgetItem *___qtablewidgetitem = ProductTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Wazon", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = ProductTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Wazon", "\320\246\320\265\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = ProductTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Wazon", "\320\222\320\265\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = ProductTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Wazon", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = ProductTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Wazon", "\320\240\320\260\320\267\320\274\320\265\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = ProductTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Wazon", "\320\237\320\273\320\260\321\202\321\204\320\276\321\200\320\274\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = ProductTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Wazon", "\320\220\321\200\321\202\320\270\320\272\321\203\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = ProductTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Wazon", "\320\241\321\200\320\276\320\272 \320\264\320\276\321\201\321\202\320\260\320\262\320\272\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = ClientTable->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Wazon", "\320\244\320\230\320\236", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = ClientTable->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Wazon", "\320\235\320\276\320\274\320\265\321\200\n"
" \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = ClientTable->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Wazon", "\320\221\320\273\320\270\320\266\320\260\320\271\321\210\320\270\320\271\n"
" \320\237\320\222\320\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = ClientTable->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Wazon", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = ClientTable->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Wazon", "\320\241\321\203\320\274\320\274\320\260\n"
" \320\277\320\276\320\272\321\203\320\277\320\276\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = ClientTable->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Wazon", "\320\222\320\265\321\201 \n"
"\320\277\320\276\320\272\321\203\320\277\320\276\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = ClientTable->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Wazon", "\320\236\320\261\321\212\320\265\320\274\n"
" \320\277\320\276\320\272\321\203\320\277\320\276\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = CourierTable->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Wazon", "\320\244\320\230\320\236", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = CourierTable->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Wazon", "\320\235\320\276\320\274\320\265\321\200\n"
" \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = CourierTable->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("Wazon", "\320\242\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\320\276\320\265 \n"
"\321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = CourierTable->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("Wazon", "\320\235\320\276\320\274\320\265\321\200\n"
" \320\274\320\260\321\210\320\270\320\275\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = CourierTable->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("Wazon", "\320\223\321\200\321\203\320\267\320\276\320\277\320\276\320\264\321\212\320\265\320\274\320\275\320\276\321\201\321\202\321\214", nullptr));
        ActivOrd_History_btn->setText(QCoreApplication::translate("Wazon", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217", nullptr));
        Client_Courier_btn->setText(QCoreApplication::translate("Wazon", "\320\232\321\203\321\200\321\214\320\265\321\200\321\213", nullptr));
        OverdueBox->setText(QCoreApplication::translate("Wazon", "\320\237\321\200\320\276\321\201\321\200\320\276\321\207\320\265\320\275\320\275\321\213\320\265", nullptr));
        NewClient_btn->setText(QCoreApplication::translate("Wazon", "\320\235\320\276\320\262\321\213\320\271\n"
"\320\272\320\273\320\270\320\265\320\275\321\202", nullptr));
        NewCourier_btn->setText(QCoreApplication::translate("Wazon", "\320\235\320\276\320\262\321\213\320\271\n"
"\320\272\321\203\321\200\321\214\320\265\321\200", nullptr));
        NewOrder_btn->setText(QCoreApplication::translate("Wazon", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214\n"
"\320\267\320\260\320\272\320\260\320\267", nullptr));
        NewRoute_btn->setText(QCoreApplication::translate("Wazon", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214\n"
"\320\274\320\260\321\200\321\210\321\200\321\203\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wazon: public Ui_Wazon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
