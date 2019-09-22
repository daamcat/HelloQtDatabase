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
    Q_PROPERTY(QSqlTableModel *tableModel // type: QSqlTableModel. name: tableModel
               READ tableModel // Required
               )

public:
    explicit BackEnd(QObject *parent = nullptr);
    QString userName();
    void setUserName(const QString& userName);

    QString tableName();
    MySqlTableModel* tableModel();

signals:
    void signalUserNameChanged();

private:
    QString m_userName;

    DatabaseManager m_databaseManager;

};

#endif // BACKEND_H
