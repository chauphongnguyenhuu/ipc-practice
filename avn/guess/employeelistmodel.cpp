#include "employeelistmodel.h"

EmployeeListModel::EmployeeListModel(QObject* parent/* = nullptr*/)
    : QAbstractListModel(parent)
{
    Entry e;
    for (int i = 0; i < 20; ++i)
    {
        e.id = i;
        e.average = 1.1f * i;
        e.name = QString("Name %1").arg(i);
        m_entries.append(e);
    }
}

void EmployeeListModel::populate(const QList<Entry>& entries)
{
    beginResetModel();
    m_entries.clear();

    for (auto it = entries.cbegin(), end = entries.cend(); it != end; ++it)
        m_entries.append(*it);

    endResetModel();
}

int EmployeeListModel::rowCount(const QModelIndex&/* parent = QModelIndex()*/) const
{
    return m_entries.count();
}

QVariant EmployeeListModel::data(const QModelIndex& index, int role/* = Qt::DisplayRole*/) const
{
    if (!index.isValid())
        return QVariant();

    switch (role)
    {
    case IdRole:
        return m_entries[index.row()].id;
    case AverageRole:
        return m_entries[index.row()].average;
    case NameRole:
        return m_entries[index.row()].name;
    default:
        // @TODO: log warning here
        return QVariant();
    }
}

QHash<int, QByteArray> EmployeeListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[AverageRole] = "average";
    roles[NameRole] = "name";
    return roles;
}
