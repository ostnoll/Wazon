#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTableWidget>
#include <QLineEdit>
#include <QCompleter>
#include <QMessageBox>
#include <QRegularExpression>
#include <QValidator>
#include <QDate>
#include "product.h"
#include "dbmanager.h"
#include "client.h"
#include "courier.h"
#include "order.h"
#include "ui_widget.h"
#include <QPrinter>
#include <QPainter>
#include <QTableWidget>
#include <QTextDocument>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui {
class Wazon;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void updateClientTable();
    void updateCourierTable();
    void updateProductTable();

private slots:
    void on_Client_Courier_btn_clicked();
    void on_NewClient_btn_clicked();
    void on_NewCourier_btn_clicked();
    void on_NewOrder_btn_clicked();
    void on_ActivOrd_History_btn_clicked();
    void on_OverdueBox_stateChanged(int arg1);
    void on_ClientTable_itemSelectionChanged();
    void on_NewRoute_btn_clicked();

private:
    Ui::Wazon *ui;
};
#endif // WIDGET_H
