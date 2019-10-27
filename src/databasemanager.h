#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H


#include <QSqlDatabase> // Forward declaration is impossible, since we call the class constructor with creating an object of the class.
#include <QStringList>

class MySqlTableModel;

class DatabaseManager
{
public:
    DatabaseManager(const QString &tableName);
    ~DatabaseManager();

    QString getTableName();
    static MySqlTableModel* getTableModel(const QString &tableName);

private:
    QString m_tableName;

};

#endif // DATABASEMANAGER_H
