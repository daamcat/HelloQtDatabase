#include "backend.h"


BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
    m_databaseManager = DatabaseManager();


}

QString BackEnd::userName()
{
    return m_userName;
}

void BackEnd::setUserName(const QString &name)
{
    m_userName = name + " from C++";
    emit signalUserNameChanged();
}

QString BackEnd::tableName()
{
    return m_databaseManager.getTableName();
}

MySqlTableModel* BackEnd::tableModel()
{
    return m_databaseManager.getTableModel();
}

