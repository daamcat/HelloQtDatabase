#include "databasemanager.h"
#include "mysqltablemodel.h"

#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QStringList>


DatabaseManager::DatabaseManager()
{

    QString databaseName = "C:/Users/diana/OneDrive/Dokumente/QtProjects/HelloQtDatabase/HelloQtDatabase/testData/sampleDatabase.sqlite";
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(databaseName);
    if (database.open() == true)
    {
        m_tableNames = database.tables();

        m_tableModel = new MySqlTableModel(nullptr,database);
        m_tableModel->setTable("costs");
        m_tableModel->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);
        m_tableModel->setHeaderData(0, Qt::Horizontal, "Description");
        m_tableModel->setHeaderData(1, Qt::Horizontal, "Price");
        m_tableModel->setHeaderData(2, Qt::Horizontal, "Date");
        m_tableModel->setHeaderData(3, Qt::Horizontal, "Withdrawal");
        m_tableModel->setHeaderData(4, Qt::Horizontal, "Tag");
        m_tableModel->select();
    }
    else
    {
        qDebug()<<"Connection to database failed.";
    }
    database.close();


}

QString DatabaseManager::getTableName()
{
    if (m_tableNames.size()>0)
    {
        return m_tableNames.at(0);
    }
    else
    {
        return QString("");
    }
}

MySqlTableModel* DatabaseManager::getTableModel()
{
    return m_tableModel;
}
