#ifndef PRODUCT_H
#define PRODUCT_H

#include <QDialog>
#include "dbmanager.h"

namespace Ui {
class Product;
}

class Product : public QDialog
{
    Q_OBJECT

public:
    explicit Product(QWidget *parent = nullptr);
    ~Product();

private slots:
    void on_Clientline_textChanged(const QString &text);
    void on_Cancal_btn_clicked();
    void on_OK_btn_clicked();
    void on_DeliveryDateWidget_selectionChanged();

private:
    Ui::Product *ui;
    void highlightEmptyFields();
    QString convertDateFormat(const QDate &date);
    bool isDateSelected;
};

#endif // PRODUCT_H
