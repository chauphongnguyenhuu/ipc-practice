#pragma once

#include <mqueue.h>

#include "baseproxy.h"

namespace core {

    class EmployeeProxy : public BaseProxy
    {
    public:
        static EmployeeProxy& getInstance();

    private:
        EmployeeProxy();

    public:
        void requestRefreshData();

        EmployeeProxy(const EmployeeProxy&) = delete;
        EmployeeProxy& operator=(const EmployeeProxy&) = delete;
    };

}
