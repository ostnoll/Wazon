#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QMouseEvent>
#include "dbmanager.h"

namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void on_OK_btn_clicked();
    void on_Cancal_btn_clicked();

private:
    Ui::Client *ui;
    bool eventFilter(QObject *obj, QEvent *event);
    void highlightEmptyFields();
};

#endif // CLIENT_H
