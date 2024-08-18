#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QString>
#include <QDebug>
#include <QObject>
#include "widget.h"

class DBManager : public QObject
{
    Q_OBJECT
public:
    DBManager(const QString &dbName);
    ~DBManager();
    bool open();
    void close();
    bool createTable(const QString &tableName, const QString &tableSchema);
    bool insertClient(const QString &name, const QString &phone, const QString &pickup, const QString &address, double totalSum, double totalWeight, double totalVolume);
    bool insertCourier(const QString &name, const QString &phone, const QString &transport, const QString &transportNum, unsigned int loadCapacity);
    bool insertProduct(const QString &client, const QString &price, const QString &weight, const QString &quantity, const QString &size,\
                                  const QString &platform, const QString &article, const QString &creationDate, const QString &deliveryDate, const int &commission, const QString &clientID);

    QSqlQuery queryAllClients() const;
    QSqlQuery queryAllCouriers() const;
    QSqlQuery queryAllProducts() const;
    void fillClientTable(QTableWidget *table) const;
    void fillCourierTable(QTableWidget *table) const;
    void fillProductTable(QTableWidget *table, bool highlightExpired) const;
    void fillHistoryTable(QTableWidget *historyTable) const;

    void highlightClientOrders(QTableWidget *table, const QString &selectedClient) const;
    QVector<int> searchClientByName(const QString &name) const;
    QVector<int> searchClientByPhone(const QString &phone) const;
    QString getClientInfo(int clientId, bool searchByPhone) const;
    QString getClientIdFromInfo(const QString &clientInfo) const;
    QString getClientIdFromPhone(const QString &phone) const;
    QList<QPair<int, QString> > getCouriersList() const;
    QList<QVariantMap> getProductsSortedByDeliveryDate();
    QString getClientPickup(int clientId);
    int getCourierLoadCapacity(int courierId);

    void removeProductsFromTable(const QList<int> &productIDs);
    void moveProductToHistory(int productID);

private:
    QString m_dbName;
    QSqlDatabase m_db;

    bool compareDates(const QString &date1, const QString &date2) const;
    int getClientIdForProduct(int productId) const;
    QString getClientIdFromProductInfo(const QString &productInfo) const;
    void resetTableBackground(QTableWidget *table) const;
    bool updateClientTotals(const QString &clientID, const QString &additionalPrice, const QString &additionalWeight, const QString &additionalSize);

signals:
    void productsTableUpdated();
    void clientTableUpdated();

};

extern DBManager *DBM;  // Объявление глобальной переменной

#endif // DBMANAGER_H
