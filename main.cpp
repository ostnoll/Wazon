#include <QApplication>
#include "widget.h"
#include "dbmanager.h"

DBManager *DBM = nullptr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Инициализация глобальной переменной
    DBM = new DBManager("database.sqlite");

    if (!DBM->open())
    {
        qDebug() << "БД не открыта";
        return -1;
    } else {
        qDebug() << "БД открыта";
    }

    // Создание таблицы клиентов
    if (!DBM->createTable("clients", "id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, phone TEXT, pickup TEXT, address TEXT, totalSum REAL, totalWeight REAL, totalVolume REAL"))
    {
        qDebug() << "Не удалось создать таблицу клиентов";
    }
    else
    {
        qDebug() << "Таблица клиентов успешно создана";
    }

    // Создание таблицы курьеров
    if (!DBM->createTable("couriers", "id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, phone TEXT, transport TEXT, transportNum TEXT, loadCapacity REAL"))
    {
        qDebug() << "Не удалось создать таблицу курьеров";
    }
    else
    {
        qDebug() << "Таблица курьеров успешно создана";
    }

    // Создание таблицы товаров
    if (!DBM->createTable("products", "id INTEGER PRIMARY KEY AUTOINCREMENT, client TEXT, price TEXT, weight TEXT, quantity TEXT, size TEXT, platform TEXT, article TEXT, creationDate TEXT, deliveryDate TEXT, commission TEXT, clientID INTEGER"))
    {
        qDebug() << "Не удалось создать таблицу товаров";
    }
    else
    {
        qDebug() << "Таблица товаров успешно создана";
    }

    // Создание таблицы истории товаров
    if (!DBM->createTable("history", "id INTEGER PRIMARY KEY AUTOINCREMENT, client TEXT, price TEXT, weight TEXT, quantity TEXT, size TEXT, platform TEXT, article TEXT, creationDate TEXT, deliveryDate TEXT, commission TEXT, clientID INTEGER"))
    {
        qDebug() << "Не удалось создать таблицу истории товаров";
    }
    else
    {
        qDebug() << "Таблица истории товаров успешно создана";
    }

    Widget w;
    w.setWindowTitle("Wazon");
    w.setWindowIcon(QIcon(":/logo.png"));
    w.show();

    int result = a.exec();

    delete DBM;  // Освобождение памяти
    return result;
}
