#include <stdio.h>
#include <core/employeeproxy.h>

int main()
{
    printf("sandbox\n");

    core::EmployeeProxy& proxy = core::EmployeeProxy::getInstance();
    proxy.requestRefreshData();

    return 0;
}
