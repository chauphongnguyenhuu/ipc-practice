#pragma once

#include <mqueue.h>

namespace core {

    class EmployeeProxy
    {
    public:
        static EmployeeProxy& getInstance();

    private:
        EmployeeProxy();
        ~EmployeeProxy();

    public:
        void requestRefreshData();

        EmployeeProxy(const EmployeeProxy&) = delete;
        EmployeeProxy& operator=(const EmployeeProxy&) = delete;

    private:
        mqd_t m_qd{ -1 };
    };

}
