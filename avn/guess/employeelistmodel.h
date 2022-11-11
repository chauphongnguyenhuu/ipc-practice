#pragma once

#include <QAbstractListModel>
#include <QString>
#include <QList>

class EmployeeListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    struct Entry
    {
        int id;
        float average;
        QString name;
    };

    enum Role
    {
        IdRole = Qt::UserRole + 1,
        AverageRole,
        NameRole
    };

public:
    explicit EmployeeListModel(QObject* parent = nullptr);

    void populate(const QList<Entry>& entries);

    int 					rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant 				data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> 	roleNames() const override;

private:
    QList<Entry> m_entries;
};
