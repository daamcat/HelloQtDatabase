#include "databasemanager.h"
#include "mysqltablemodel.h"

#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>
#include <QSqlError>

DatabaseManager::DatabaseManager(const QString &tableName) :
    m_tableName(tableName)
{

}

DatabaseManager::~DatabaseManager()
{
    qDebug()<<"DatabaseManager destructor is called.";
}

QString DatabaseManager::getTableName()
{
    return m_tableName;
}

MySqlTableModel* DatabaseManager::getTableModel(const QString &tablename)
{
    QString databaseName = QString(SOURCE_DIR) + "/testData/sampleDatabase.sqlite";
    QSqlDatabase databaseConnection = QSqlDatabase::addDatabase("QSQLITE");
    databaseConnection.setDatabaseName(databaseName);
    if (databaseConnection.open() == false)
    {
        qDebug()<<"Connection to database failed.";
    }

    MySqlTableModel *tableModel = new MySqlTableModel(nullptr,databaseConnection);
    tableModel->setTable(tablename);
    tableModel->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);
    tableModel->setHeaderData(0, Qt::Horizontal, "Description");
    tableModel->setHeaderData(1, Qt::Horizontal, "Price");
    tableModel->setHeaderData(2, Qt::Horizontal, "Date");
    tableModel->setHeaderData(3, Qt::Horizontal, "Withdrawal");
    tableModel->setHeaderData(4, Qt::Horizontal, "Tag");
    tableModel->select();
    return tableModel;
}
