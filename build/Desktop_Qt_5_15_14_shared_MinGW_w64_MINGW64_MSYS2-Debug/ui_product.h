/********************************************************************************
** Form generated from reading UI file 'product.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCT_H
#define UI_PRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
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

class Ui_Product
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *Pricelabel;
    QLineEdit *Priceline;
    QLabel *Weightlabel;
    QLineEdit *Weightline;
    QLabel *Quantitylabel;
    QLineEdit *Quantityline;
    QLabel *Sizelabel;
    QComboBox *SizeBox;
    QLabel *Platformlabel;
    QComboBox *PlatformBox;
    QLabel *Articlelabel;
    QLineEdit *Articleline;
    QLabel *Clientlabel;
    QLineEdit *Clientline;
    QLabel *DeliveryDatelabel;
    QCalendarWidget *DeliveryDateWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *OK_btn;
    QPushButton *Cancal_btn;

    void setupUi(QDialog *Product)
    {
        if (Product->objectName().isEmpty())
            Product->setObjectName(QString::fromUtf8("Product"));
        Product->resize(420, 425);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Product->sizePolicy().hasHeightForWidth());
        Product->setSizePolicy(sizePolicy);
        Product->setMinimumSize(QSize(420, 425));
        verticalLayout = new QVBoxLayout(Product);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        Pricelabel = new QLabel(Product);
        Pricelabel->setObjectName(QString::fromUtf8("Pricelabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, Pricelabel);

        Priceline = new QLineEdit(Product);
        Priceline->setObjectName(QString::fromUtf8("Priceline"));
        QFont font;
        font.setBold(true);
        Priceline->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, Priceline);

        Weightlabel = new QLabel(Product);
        Weightlabel->setObjectName(QString::fromUtf8("Weightlabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, Weightlabel);

        Weightline = new QLineEdit(Product);
        Weightline->setObjectName(QString::fromUtf8("Weightline"));
        Weightline->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, Weightline);

        Quantitylabel = new QLabel(Product);
        Quantitylabel->setObjectName(QString::fromUtf8("Quantitylabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, Quantitylabel);

        Quantityline = new QLineEdit(Product);
        Quantityline->setObjectName(QString::fromUtf8("Quantityline"));
        Quantityline->setFont(font);

        formLayout->setWidget(3, QFormLayout::FieldRole, Quantityline);

        Sizelabel = new QLabel(Product);
        Sizelabel->setObjectName(QString::fromUtf8("Sizelabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, Sizelabel);

        SizeBox = new QComboBox(Product);
        SizeBox->addItem(QString());
        SizeBox->addItem(QString());
        SizeBox->addItem(QString());
        SizeBox->addItem(QString());
        SizeBox->addItem(QString());
        SizeBox->setObjectName(QString::fromUtf8("SizeBox"));
        SizeBox->setFont(font);

        formLayout->setWidget(4, QFormLayout::FieldRole, SizeBox);

        Platformlabel = new QLabel(Product);
        Platformlabel->setObjectName(QString::fromUtf8("Platformlabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, Platformlabel);

        PlatformBox = new QComboBox(Product);
        PlatformBox->addItem(QString());
        PlatformBox->addItem(QString());
        PlatformBox->addItem(QString());
        PlatformBox->setObjectName(QString::fromUtf8("PlatformBox"));
        PlatformBox->setFont(font);

        formLayout->setWidget(5, QFormLayout::FieldRole, PlatformBox);

        Articlelabel = new QLabel(Product);
        Articlelabel->setObjectName(QString::fromUtf8("Articlelabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, Articlelabel);

        Articleline = new QLineEdit(Product);
        Articleline->setObjectName(QString::fromUtf8("Articleline"));
        Articleline->setFont(font);

        formLayout->setWidget(6, QFormLayout::FieldRole, Articleline);

        Clientlabel = new QLabel(Product);
        Clientlabel->setObjectName(QString::fromUtf8("Clientlabel"));
        Clientlabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, Clientlabel);

        Clientline = new QLineEdit(Product);
        Clientline->setObjectName(QString::fromUtf8("Clientline"));
        Clientline->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, Clientline);

        DeliveryDatelabel = new QLabel(Product);
        DeliveryDatelabel->setObjectName(QString::fromUtf8("DeliveryDatelabel"));

        formLayout->setWidget(7, QFormLayout::LabelRole, DeliveryDatelabel);

        DeliveryDateWidget = new QCalendarWidget(Product);
        DeliveryDateWidget->setObjectName(QString::fromUtf8("DeliveryDateWidget"));
        DeliveryDateWidget->setFont(font);
        DeliveryDateWidget->setGridVisible(false);
        DeliveryDateWidget->setSelectionMode(QCalendarWidget::SelectionMode::SingleSelection);
        DeliveryDateWidget->setHorizontalHeaderFormat(QCalendarWidget::HorizontalHeaderFormat::ShortDayNames);
        DeliveryDateWidget->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);
        DeliveryDateWidget->setNavigationBarVisible(true);
        DeliveryDateWidget->setDateEditEnabled(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, DeliveryDateWidget);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OK_btn = new QPushButton(Product);
        OK_btn->setObjectName(QString::fromUtf8("OK_btn"));

        horizontalLayout->addWidget(OK_btn);

        Cancal_btn = new QPushButton(Product);
        Cancal_btn->setObjectName(QString::fromUtf8("Cancal_btn"));

        horizontalLayout->addWidget(Cancal_btn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Product);

        QMetaObject::connectSlotsByName(Product);
    } // setupUi

    void retranslateUi(QDialog *Product)
    {
        Product->setWindowTitle(QCoreApplication::translate("Product", "Dialog", nullptr));
        Pricelabel->setText(QCoreApplication::translate("Product", "\320\246\320\265\320\275\320\260 ", nullptr));
        Weightlabel->setText(QCoreApplication::translate("Product", "\320\222\320\265\321\201", nullptr));
        Quantitylabel->setText(QCoreApplication::translate("Product", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        Sizelabel->setText(QCoreApplication::translate("Product", "\320\240\320\260\320\267\320\274\320\265\321\200", nullptr));
        SizeBox->setItemText(0, QCoreApplication::translate("Product", "\320\235\320\265\321\202", nullptr));
        SizeBox->setItemText(1, QCoreApplication::translate("Product", "XS", nullptr));
        SizeBox->setItemText(2, QCoreApplication::translate("Product", "S", nullptr));
        SizeBox->setItemText(3, QCoreApplication::translate("Product", "M", nullptr));
        SizeBox->setItemText(4, QCoreApplication::translate("Product", "L", nullptr));

        Platformlabel->setText(QCoreApplication::translate("Product", "\320\237\320\273\320\260\321\202\321\204\320\276\321\200\320\274\320\260", nullptr));
        PlatformBox->setItemText(0, QCoreApplication::translate("Product", "\320\235\320\265\321\202", nullptr));
        PlatformBox->setItemText(1, QCoreApplication::translate("Product", "Wildberries", nullptr));
        PlatformBox->setItemText(2, QCoreApplication::translate("Product", "Ozon", nullptr));

        Articlelabel->setText(QCoreApplication::translate("Product", "\320\220\321\200\321\202\320\270\320\272\321\203\320\273", nullptr));
        Clientlabel->setText(QCoreApplication::translate("Product", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        DeliveryDatelabel->setText(QCoreApplication::translate("Product", "\320\224\320\260\321\202\320\260 \320\264\320\276\321\201\321\202\320\260\320\262\320\272\320\270", nullptr));
        OK_btn->setText(QCoreApplication::translate("Product", "\320\236\320\232", nullptr));
        Cancal_btn->setText(QCoreApplication::translate("Product", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Product: public Ui_Product {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCT_H
