#include "include/core/baseproxy.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "include/core/defines.h"
#include "include/core/data.h"

namespace core {

    BaseProxy::BaseProxy(const char* mqPath)
    {
        mq_attr attr = {
            .mq_flags = 0,
            .mq_maxmsg = CORE_MQ_MAX_MSG,
            .mq_msgsize = sizeof(core::MsgBuf),
            .mq_curmsgs = 0,
            .__pad = {}
        };

        m_qd = mq_open(mqPath, O_WRONLY | O_CREAT, CORE_MQ_PERMS, &attr);
        PASSERT_ERRNO(m_qd != (mqd_t)-1 && "`BaseProxy()`");
    }

    BaseProxy::~BaseProxy()
    {
        mq_close(m_qd);
    }

    void BaseProxy::send(const MsgBuf& buf)
    {
        const unsigned int k_prio = 0;
        int success = mq_send(m_qd, (char*)&buf, sizeof(MsgBuf), k_prio);
        PASSERT_ERRNO(success != -1 && "`requestRefreshData()`");
    }

}
