#ifndef ORDER_H
#define ORDER_H

#include <QDialog>
#include "dbmanager.h"

namespace Ui {
class Order;
}

class Order : public QDialog
{
    Q_OBJECT

public:
    explicit Order(QWidget *parent = nullptr);
    ~Order();
    int getSelectCourierID();

private slots:
    void on_CourierBox_currentIndexChanged(int index);
    void on_FillOrder_btn_clicked();
    void on_Cancel_btn_clicked();
    void on_OK_btn_clicked();

private:
    Ui::Order *ui;
    bool isDiscountApplicable(const QVariantMap &clientData) const;
    void exportTableToPDF(QTableWidget *table);
};

#endif // ORDER_H
