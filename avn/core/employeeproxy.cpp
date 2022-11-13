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
    {
        mq_attr attr = {
            .mq_flags = 0,
            .mq_maxmsg = CORE_MQ_MAX_MSG,
            .mq_msgsize = sizeof(core::MsgBuf),
            .mq_curmsgs = 0,
            .__pad = {}
        };

        m_qd = mq_open(CORE_MQ_PATH_SERVICE, O_WRONLY | O_CREAT, CORE_MQ_PERMS, &attr);
        PASSERT_ERRNO(m_qd != (mqd_t)-1 && "`EmployeeProxy()`");
    }

    EmployeeProxy::~EmployeeProxy()
    {
        mq_close(m_qd);
    }

    void EmployeeProxy::requestRefreshData()
    {
        const unsigned int k_prio = 0;
        MsgBuf msg = { .type = MsgType::k_msgTypeRefreshData, .msg = {} };
        int success = mq_send(m_qd, (char*)&msg, sizeof(MsgBuf), k_prio);
        PASSERT_ERRNO(success != -1 && "`requestRefreshData()`");
        printf("requestRefreshData ok\n");
        fflush(stdout);
    }

}
