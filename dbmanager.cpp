#include "dbmanager.h"

//Создание БД
DBManager::DBManager(const QString &dbName) : m_dbName(dbName)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE", "unique_connection_name");
    m_db.setDatabaseName(m_dbName);
}

//Деструктор
DBManager::~DBManager()
{
    close();
}

//Открытие БД
bool DBManager::open()
{
    if (!m_db.open())
    {
        qWarning() << "Не удалось открыть базу данных:" << m_db.lastError().text();
        return false;
    }
    return true;
}

//Закрытие БД
void DBManager::close()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

//Создание таблицы
bool DBManager::createTable(const QString &tableName, const QString &tableSchema)
{
    QSqlQuery query(m_db);
    QString createTableQuery = QString("CREATE TABLE IF NOT EXISTS %1 (%2)").arg(tableName).arg(tableSchema);
    return query.exec(createTableQuery);
}

//Добавление нового клиента
bool DBManager::insertClient(const QString &name, const QString &phone, const QString &pickup, const QString &address, double totalSum, double totalWeight, double totalVolume)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO clients (name, phone, pickup, address, totalSum, totalWeight, totalVolume) VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(phone);
    query.addBindValue(pickup);
    query.addBindValue(address);
    query.addBindValue(totalSum);
    query.addBindValue(totalWeight);
    query.addBindValue(totalVolume);
    if (!query.exec())
    {
        qWarning() << "Клиент не добавлен:" << query.lastError().text();
        return false;
    }
    else
    {
        qDebug() << "Клиент успошно добавлен";
    }

    return true;
}

//Добавление нового курьера
bool DBManager::insertCourier(const QString &name, const QString &phone, const QString &transport, const QString &transportNum, unsigned int loadCapacity)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO couriers (name, phone, transport, transportNum, loadCapacity) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(phone);
    query.addBindValue(transport);
    query.addBindValue(transportNum);
    query.addBindValue(loadCapacity);

    if (!query.exec())
    {
        qWarning() << "Курьер не добавлен:" << query.lastError().text();
        return false;
    }
    else
    {
        qDebug() << "Курьер успошно добавлен";
    }
    return true;
}

//Добавление нового товара
bool DBManager::insertProduct(const QString &client, const QString &price, const QString &weight, const QString &quantity, const QString &size,\
                              const QString &platform, const QString &article, const QString &creationDate, const QString &deliveryDate, const int &commission, const QString &clientID)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO products (client, price, weight, quantity, size, platform, article, creationDate, deliveryDate, commission, clientID) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(client);
    query.addBindValue(price);
    query.addBindValue(weight);
    query.addBindValue(quantity);
    query.addBindValue(size);
    query.addBindValue(platform);
    query.addBindValue(article);
    query.addBindValue(creationDate);
    query.addBindValue(deliveryDate);
    query.addBindValue(commission);
    query.addBindValue(clientID);

    if (!updateClientTotals(clientID, price, weight, size))
    {
        return false;
    }
    if (!query.exec())
    {
        qWarning() << "Товар не добавлен:" << query.lastError().text();
        return false;
    }
    else
    {
        qDebug() << "Товар успешно добавлен";
    }
    return true;
}

//Обновление статистики клиента
bool DBManager::updateClientTotals(const QString &clientID, const QString &additionalPrice, const QString &additionalWeight, const QString &additionalSize)
{
    QSqlQuery query(m_db);

    int intSize = 0;

    if (additionalSize == "XS")
    {
        intSize = 1;
    }
    else if (additionalSize == "S")
    {
        intSize = 2;
    }
    else if (additionalSize == "M")
    {
        intSize = 4;
    }
    else if (additionalSize == "L")
    {
        intSize = 8;
    }

    query.prepare("SELECT totalSum, totalWeight, totalVolume FROM clients WHERE id = ?");
    query.addBindValue(clientID);

    if (!query.exec() || !query.next())
    {
        qWarning() << "Не удалось получить текущие значения клиента:" << query.lastError().text();
        return false;
    }

    int currentPrice = query.value("totalSum").toInt();
    double currentWeight = query.value("totalWeight").toDouble();
    int currentVolume = query.value("totalVolume").toInt();

    int updatedPrice = currentPrice + additionalPrice.toInt();
    double updatedWeight = currentWeight + additionalWeight.toDouble();
    int updatedVolume = currentVolume + intSize;

    query.prepare("UPDATE clients SET totalSum = ?, totalWeight = ?, totalVolume = ? WHERE id = ?");
    query.addBindValue(updatedPrice);
    query.addBindValue(updatedWeight);
    query.addBindValue(updatedVolume);
    query.addBindValue(clientID);

    if (!query.exec())
    {
        qWarning() << "Не удалось обновить данные клиента:" << query.lastError().text();
        return false;
    }

    emit clientTableUpdated();

    return true;
}

//Заполнение таблицы клиентов
void DBManager::fillClientTable(QTableWidget *table) const
{
    QSqlQuery query = queryAllClients();
    int columnCount = query.record().count();

    table->setColumnCount(columnCount - 1);
    QStringList headers;
    headers << "Имя"
            << "Номер\nтелефона"
            << "Ближайший\nПВЗ"
            << "Адресс"
            << "Сумма\nпокупок"
            << "Вес\nпокупок"
            << "Объем\nпокупок";
    table->setHorizontalHeaderLabels(headers);
    for (int col = 1; col < columnCount; ++col)
    {
        headers << query.record().fieldName(col);
    }
    table->setHorizontalHeaderLabels(headers);
    table->setRowCount(0);

    int row = 0;
    while (query.next())
    {
        table->insertRow(row);
        for (int col = 1; col < columnCount; ++col)
        {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            table->setItem(row, col - 1, item);
        }
        ++row;
    }
}

//Заполнение таблицы курьеров
void DBManager::fillCourierTable(QTableWidget *table) const
{
    QSqlQuery query = queryAllCouriers();
    int columnCount = query.record().count();

    table->setColumnCount(columnCount - 1);
    QStringList headers;
    headers << "Имя"
            << "Номер\nтелефона"
            << "Транспорт"
            << "Номер\nмашины"
            << "Грузоподъемность\n(кг)";
    for (int col = 1; col < columnCount; ++col)
    {
        headers << query.record().fieldName(col);
    }
    table->setHorizontalHeaderLabels(headers);

    table->setRowCount(0);

    int row = 0;
    while (query.next())
    {
        table->insertRow(row);
        for (int col = 1; col < columnCount; ++col)
        {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            table->setItem(row, col - 1, item);
        }
        ++row;
    }
}

//Заполнение таблицы товаров с возможностью выделения просроченных заказов
void DBManager::fillProductTable(QTableWidget *table, bool highlightExpired) const
{
    table->setSortingEnabled(false);
    table->clearContents();
    table->setRowCount(0);

    QSqlQuery query = queryAllProducts();
    int columnCount = query.record().count()-1;

    table->setColumnCount(columnCount - 1);
    QStringList headers;
    headers << "Клиент"
            << "Цена"
            << "Вес"
            << "Кол-во"
            << "Размер"
            << "Платформа"
            << "Артикул"
            << "Дата\nсоздания"
            << "Дата\nдоставки"
            << "Комиссия";
    table->setHorizontalHeaderLabels(headers);

    QString currentDateStr = QDate::currentDate().toString("dd.MM.yyyy");
    int row = 0;
    while (query.next())
    {
        table->insertRow(row);
        for (int col = 1; col < columnCount; ++col)
        {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            table->setItem(row, col - 1, item);
        }

        // Проверка на просроченность и установка цвета
        if (highlightExpired)
        {
            QTableWidgetItem *deliveryDateItem = table->item(row, columnCount - 3);
            if (deliveryDateItem)
            {
                QString deliveryDateStr = deliveryDateItem->text();
                if (compareDates(deliveryDateStr, currentDateStr))
                {
                    for (int col = 0; col < columnCount - 1; ++col)
                    {
                        table->item(row, col)->setBackground(QColor(255, 200, 200)); // Красный цвет для просроченных заказов
                    }
                }
            }
        }

        ++row;
    }

    table->setSortingEnabled(true); // Включить сортировку после обновления данных
}

//Обновление таблицы истории
void DBManager::fillHistoryTable(QTableWidget *historyTable) const
{
    historyTable->setSortingEnabled(false);
    historyTable->clearContents();
    historyTable->setRowCount(0);

    QSqlQuery query(m_db);
    query.prepare("SELECT client, price, weight, quantity, size, platform, article, creationDate, deliveryDate, commission "
                  "FROM history");

    if (query.exec())
    {
        int columnCount = query.record().count();
        historyTable->setColumnCount(columnCount);

        QStringList headers;
        headers << "Клиент"
                << "Цена"
                << "Вес"
                << "Кол-во"
                << "Размер"
                << "Платформа"
                << "Артикул"
                << "Дата\nсоздания"
                << "Дата\nдоставки"
                << "Комиссия";
        historyTable->setHorizontalHeaderLabels(headers);

        int row = 0;
        while (query.next())
        {
            historyTable->insertRow(row);
            for (int col = 0; col < columnCount; ++col)
            {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                item->setBackground(QColor("#d0d0d0"));
                item->setForeground(QColor("#4d4d4d"));
                historyTable->setItem(row, col, item);
            }
            ++row;
        }

        historyTable->setColumnWidth(0, 240);
        historyTable->setColumnWidth(1, 50);
        historyTable->setColumnWidth(2, 50);
        historyTable->setColumnWidth(3, 50);
        historyTable->setColumnWidth(4, 50);
        historyTable->setColumnWidth(5, 75);
        historyTable->setColumnWidth(6, 90);
        historyTable->setColumnWidth(7, 70);
        historyTable->setColumnWidth(8, 70);
        historyTable->setColumnWidth(9, 70);
        historyTable->horizontalHeader()->setStretchLastSection(true);
        historyTable->setSortingEnabled(true);
        historyTable->horizontalHeader()->setStyleSheet("background-color: #c0c0c0; color: #000000;");
    }
    else
    {
        qWarning() << "Failed to update history table:" << query.lastError().text();
    }

    historyTable->setSortingEnabled(true); // Включить сортировку после обновления данных
}

//Выделение закозов клиента при нажатии на него
void DBManager::highlightClientOrders(QTableWidget *table, const QString &selectedClientID) const
{
    resetTableBackground(table);

    int rowCount = table->rowCount();
    int columnCount = table->columnCount();

    for (int row = 0; row < rowCount; ++row)
    {

        QTableWidgetItem *item = table->item(row, 0);
        if (!item) continue;

        QString productInfo = item->text();
        int clientId = getClientIdFromInfo(productInfo).toInt();

        if (clientId == selectedClientID.toInt())
        {
            QString creationDate = table->item(row, 8)->text();
            QString currentDate = QDate::currentDate().toString("dd.MM.yyyy");

            for (int col = 0; col < columnCount; ++col)
            {
                QTableWidgetItem *item = table->item(row, col);
                if (!item) continue;


                if (compareDates(creationDate, currentDate))
                {
                    item->setBackground(QColor(255, 165, 0));
                }
                else
                {
                    item->setBackground(QColor(173, 216, 230));
                }
            }
        }
    }
}

//Обновление выделения таблицы
void DBManager::resetTableBackground(QTableWidget *table) const
{
    int rowCount = table->rowCount();
    int columnCount = table->columnCount();

    for (int row = 0; row < rowCount; ++row)
    {
        for (int col = 0; col < columnCount; ++col)
        {
            QTableWidgetItem *item = table->item(row, col);
            if (item)
            {
                item->setBackground(QColor(255, 255, 255));
            }
        }
    }
}

//Возврат ID клиента из информации о нем для продукта
QString DBManager::getClientIdFromProductInfo(const QString &productInfo) const
{
    QStringList parts = productInfo.split("    ");
    if (parts.isEmpty()) {
        qWarning() << "Invalid product info format.";
        return QString();
    }

    QString productName = parts.at(0).trimmed();

    QSqlQuery query(m_db);
    query.prepare("SELECT clientID FROM products WHERE article = ?");
    query.addBindValue(productName);

    if (!query.exec()) {
        qWarning() << "Failed to execute query to get client ID for product:" << query.lastError().text();
        return QString();
    }

    if (query.next()) {
        return query.value(0).toString();
    }

    return QString();
}

//Вернуть всех клиентов в БД
QSqlQuery DBManager::queryAllClients() const
{
    QSqlQuery query(m_db);
    query.exec("SELECT * FROM clients");
    return query;
}

//Вернуть всех курьеров в БД
QSqlQuery DBManager::queryAllCouriers() const
{
    QSqlQuery query(m_db);
    query.exec("SELECT * FROM couriers");
    return query;
}

//Вернуть весь товар в БД
QSqlQuery DBManager::queryAllProducts() const
{
    QSqlQuery query(m_db);
    query.exec("SELECT * FROM products");
    return query;
}

//Поиск клиентов по имени для создания заказа
QVector<int> DBManager::searchClientByName(const QString &name) const
{
    QVector<int> clientIds;
    QSqlQuery query(m_db);
    query.prepare("SELECT id FROM clients WHERE name LIKE ?");
    query.addBindValue("%" + name + "%");
    if (query.exec()) {
        while (query.next()) {
            clientIds.append(query.value(0).toInt());
        }
    }
    return clientIds;
}

//Поиск клиентов по номеру телефона для создания заказа
QVector<int> DBManager::searchClientByPhone(const QString &phone) const
{
    QVector<int> clientIds;
    QString sanitizedPhone = phone;
    sanitizedPhone.remove(QRegExp("\\s|\\D"));

    QSqlQuery query(m_db);
    query.prepare("SELECT id FROM clients WHERE REPLACE(REPLACE(phone, ' ', ''), '+', '') LIKE ?");
    query.addBindValue("%" + sanitizedPhone + "%");

    if (query.exec())
    {
        while (query.next())
        {
            clientIds.append(query.value(0).toInt());
        }
    } else
    {
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    return clientIds;
}


//Возвращение строки найденного клиента
QString DBManager::getClientInfo(int clientId, bool searchByPhone) const
{
    QSqlQuery query(m_db);

    query.prepare("SELECT phone, name FROM clients WHERE id = ?");
    query.addBindValue(clientId);

    if (query.exec() && query.next())
    {
        if (searchByPhone)
        {
            return query.value(0).toString() + "    " + query.value(1).toString();
        }
        else
        {
            return query.value(1).toString() + "    " + query.value(0).toString();
        }
    }
    return QString();
}

// Возвращение ID клиента из строки с информацией
QString DBManager::getClientIdFromInfo(const QString &clientInfo) const
{
    QStringList parts = clientInfo.split("    ");
    if (parts.size() != 2) {
        qWarning() << "Invalid client info format.";
        return QString();
    }

    QString name = parts.at(0).trimmed();
    QString phone = parts.at(1).trimmed();

    // Поиск клиента по имени
    QVector<int> idsByName = searchClientByName(name);
    if (!idsByName.isEmpty()) {
        return QString::number(idsByName.first());
    }

    // Поиск клиента по номеру телефона
    QVector<int> idsByPhone = searchClientByPhone(phone);
    if (!idsByPhone.isEmpty()) {
        return QString::number(idsByPhone.first());
    }

    // Клиент не найден
    return QString();
}

// Возвращение ID клиента из телефона
QString DBManager::getClientIdFromPhone(const QString &phone) const
{
    QSqlQuery query(m_db);
    query.prepare("SELECT id FROM clients WHERE phone = ?");
    query.addBindValue(phone);

    if (!query.exec())
    {
        qWarning() << "Не удалось получить ID клиента:" << query.lastError().text();
        return QString();
    }

    if (query.next())
    {
        return query.value(0).toString();
    }

    return QString();
}


//Проверка на просроченный заказ
bool DBManager::compareDates(const QString &date1, const QString &date2) const
{
    QString format = "dd.MM.yyyy";

    if (date1.isEmpty() || date2.isEmpty()) {
        qWarning() << "Empty date string";
        return false;
    }

    QDate qdate1 = QDate::fromString(date1, format);
    QDate qdate2 = QDate::fromString(date2, format);

    if (!qdate1.isValid() || !qdate2.isValid()) {
        qWarning() << "Invalid date format in date1:" << date1 << "or date2:" << date2;
        return false;
    }

    return qdate1 < qdate2;
}


//Заполнение поля с курьерами при создании маршрута
QList<QPair<int, QString>> DBManager::getCouriersList() const
{
    QList<QPair<int, QString>> couriers;
    QSqlQuery query("SELECT id, name FROM couriers", m_db);

    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        couriers.append(qMakePair(id, name));
    }

    return couriers;
}

//Сортировка товаров по дате доставки
QList<QVariantMap> DBManager::getProductsSortedByDeliveryDate()
{
    QList<QVariantMap> sortedProducts;
    QSqlQuery query(m_db);

    query.prepare("SELECT id, article, client, deliveryDate, price, weight, quantity, size, commission, clientID "
                  "FROM products "
                  "ORDER BY SUBSTR(deliveryDate, 7, 4) || SUBSTR(deliveryDate, 4, 2) || SUBSTR(deliveryDate, 1, 2) ASC");

    if (query.exec())
    {
        while (query.next())
        {
            QVariantMap productData;
            int clientId = query.value("clientID").toInt();  // Получаем ID клиента

            productData["id"] = query.value("id").toInt();
            productData["article"] = query.value("article").toString();
            productData["client"] = query.value("client").toString();
            productData["deliveryDate"] = query.value("deliveryDate").toString();
            productData["price"] = query.value("price").toString();
            productData["weight"] = query.value("weight").toString();
            productData["quantity"] = query.value("quantity").toString();
            productData["size"] = query.value("size").toString();
            productData["commission"] = query.value("commission").toString();
            productData["clientID"] = clientId;

            qDebug() << "ID:" << query.value("id").toInt()
                     << "Article:" << query.value("article").toString()
                     << "Client:" << query.value("client").toString()
                     << "Delivery Date:" << query.value("deliveryDate").toString()
                     << "Price:" << query.value("price").toString()
                     << "Weight:" << query.value("weight").toString()
                     << "Quantity:" << query.value("quantity").toString()
                     << "Size:" << query.value("size").toString()
                     << "Commission:" << query.value("commission").toString()
                     << "Client ID:" << clientId;

            QString pickup = getClientPickup(clientId);
            productData["pickup"] = pickup;

            sortedProducts.append(productData);
        }
    }
    else
    {
        qWarning() << "Failed to execute query to get sorted products:" << query.lastError().text();
    }

    return sortedProducts;
}

//Вернкть ПВЗ клиента
QString DBManager::getClientPickup(int clientId)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT pickup FROM clients WHERE id = ?");
    query.addBindValue(clientId);

    if (query.exec() && query.next())
    {
        return query.value(0).toString();
    }
    else
    {
        qWarning() << "Failed to retrieve pickup point for client ID" << clientId << ":" << query.lastError().text();
        return QString();
    }
}

//Вернуть грузоподъемность курьера
int DBManager::getCourierLoadCapacity(int courierId)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT loadcapacity FROM couriers WHERE id = ?");
    query.addBindValue(courierId);

    if (query.exec() && query.next())
    {
        return query.value(0).toInt();
    }
    else
    {
        qWarning() << "Failed to retrieve load capacity for courier ID" << courierId << ":" << query.lastError().text();
        return -1;
    }
}

//Уделение товаров взятых в работу из актуального списка
void DBManager::removeProductsFromTable(const QList<int>& productIDs)
{
    QSqlQuery query(m_db);

    for (int productID : productIDs)
    {
        query.prepare("DELETE FROM products WHERE id = ?");
        query.addBindValue(productID);

        if (!query.exec())
        {
            qWarning() << "Failed to remove product with ID" << productID << ":" << query.lastError().text();
        }
    }
    emit productsTableUpdated();
}

//Перемещение товаров звятых в работу в историю
void DBManager::moveProductToHistory(int productID)
{
    QSqlQuery query(m_db);

    query.prepare("INSERT INTO history SELECT * FROM products WHERE id = ?");
    query.addBindValue(productID);

    if (!query.exec())
    {
        qWarning() << "Failed to move product with ID" << productID << "to history:" << query.lastError().text();
    }
}






