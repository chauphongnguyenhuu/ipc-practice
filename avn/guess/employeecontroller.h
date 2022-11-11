#pragma once

#include <QObject>

class EmployeeListModel;

class EmployeeController : public QObject
{
    Q_OBJECT

public:
    explicit EmployeeController(QObject* parent = nullptr);

public slots:
    void refresh(EmployeeListModel* model);
};
