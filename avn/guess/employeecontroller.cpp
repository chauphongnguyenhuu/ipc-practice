#include "employeecontroller.h"

#include <QList>
#include <QDebug>

#include "employeelistmodel.h"

EmployeeController::EmployeeController(QObject* parent/* = nullptr*/)
    : QObject(parent)
{
}

void EmployeeController::refresh(EmployeeListModel* model)
{
    qDebug("[EmployeeController] `refresh()`");

    QList<EmployeeListModel::Entry> entries;
    EmployeeListModel::Entry e;
    for (int i = 0; i < 20; ++i)
    {
        e.id = i;
        e.average = 1.1f * i;
        e.name = QString("Name %1").arg(i);
        entries.append(e);
    }

    model->populate(entries);
}
