#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H


#include <QSqlDatabase> // Forward declaration is impossible, since we call the class constructor with creating an object of the class.
#include <QStringList>

class MySqlTableModel;

class DatabaseManager
{
public:
    DatabaseManager();

    QString getTableName();
    MySqlTableModel* getTableModel();

private:
    QSqlDatabase m_databaseConnection;
    QStringList m_tableNames;
    MySqlTableModel *m_tableModel;


};

#endif // DATABASEMANAGER_H
