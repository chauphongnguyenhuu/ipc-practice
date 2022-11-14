#include "include/core/employeeproxy.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "include/core/defines.h"
#include "include/core/data.h"

namespace core {

    EmployeeProxy& EmployeeProxy::getInstance()
    {
        static EmployeeProxy instance;
        return instance;
    }

    EmployeeProxy::EmployeeProxy()
        : BaseProxy(CORE_MQ_PATH_SERVICE)
    {
    }

    void EmployeeProxy::requestRefreshData()
    {
        MsgBuf buf = { .type = MsgType::k_msgTypeRefreshData, .msg = {} };
        send(buf);
    }

}
