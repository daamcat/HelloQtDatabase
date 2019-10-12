#include "mysqltablemodel.h"

#include <QSqlRecord>

MySqlTableModel::MySqlTableModel(QObject * parent, QSqlDatabase db) :
    QSqlTableModel (parent,db)
{

}


QHash<int, QByteArray> MySqlTableModel::roleNames() const
{
    // Trying to make a list of roles at initialization and passing it whenever roleNames() is called,
    // was not successful! Hence, we generate this list every time roleNames() is called.
    QHash<int, QByteArray> roles;
    // A "database record" or "record" is a row in a table in database. QSqlRecord represents a record.
    // A "field" is a column in database table.
    for (int i = 0; i < this->record().count(); i++)
    {
        QString columnHeader = this->record().fieldName(i);
        if (columnHeader == "Price")
        {
            columnHeader = "price";
        }

        roles.insert(Qt::UserRole + i + 1 , columnHeader.toUtf8());
    }
    return roles;
}


QVariant MySqlTableModel::data ( const QModelIndex & index, int role ) const
{
    QVariant value;
    if (index.isValid())
    {
        if (role < Qt::ItemDataRole::UserRole)
        {
            value = QSqlQueryModel::data(index,role);
        }
        else
        {
            int columnIndex = role - Qt::ItemDataRole::UserRole - 1;
            QModelIndex modelIndex = this->index(index.row(), columnIndex);
            value = QSqlQueryModel::data(modelIndex,Qt::ItemDataRole::DisplayRole);
        }
    }
    return value;
}

bool MySqlTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() == true && role == Qt::ItemDataRole::EditRole)
    {
        bool success = setData(index, value.toString(),Qt::ItemDataRole::EditRole);
        if (success)
        {
            emit dataChanged(index, index, { Qt::EditRole, Qt::DisplayRole });
        }
    }
    else
    {
        return false;
    }
}

