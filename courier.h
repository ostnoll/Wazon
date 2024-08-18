#ifndef COURIER_H
#define COURIER_H

#include <QDialog>
#include <QMouseEvent>
#include "dbmanager.h"

namespace Ui {
class Courier;
}

class Courier : public QDialog
{
    Q_OBJECT

public:
    explicit Courier(QWidget *parent = nullptr);
    ~Courier();

private slots:
    void on_OK_btn_clicked();
    void on_Cancel_btn_clicked();

private:
    Ui::Courier *ui;
    bool eventFilter(QObject *obj, QEvent *event);
    void highlightEmptyFields();
};

#endif // COURIER_H
