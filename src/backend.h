#ifndef BACKEND_H
#define BACKEND_H

/*
Ref:
[1] Integrating QML and C++
https://doc.qt.io/qt-5/qtqml-cppintegration-topic.html

*/


#include<QObject>
#include<QString>

#include "databasemanager.h"
#include "mysqltablemodel.h"


class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName // type: QString. name: userName
               READ userName // Required
               WRITE setUserName // Functional
               NOTIFY signalUserNameChanged // Optional. Specifies signal name emitted with property change.
               )

    Q_PROPERTY(QString tableName // type: QString. name: tableName
               READ tableName // Required
               )
public:
    explicit BackEnd(QObject *parent = nullptr);
    QString userName();
    QString tableName();
    void setUserName(const QString& userName);
    void setTableName(const QString& tableName);

signals:
    void signalUserNameChanged();

private:
    QString m_userName;
    QString m_tableName;

    DatabaseManager m_databaseManager;

};

#endif // BACKEND_H
