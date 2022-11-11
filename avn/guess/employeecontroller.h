#pragma once

#include <QObject>

class EmployeeController : public QObject
{
    Q_OBJECT

public:
    explicit EmployeeController(QObject* parent = nullptr);
};
