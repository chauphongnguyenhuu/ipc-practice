#include "include/core/basemqreceiver.h"

#include <fcntl.h>
#include <sys/stat.h>

#include "include/core/defines.h"
#include "include/core/data.h"

namespace core {

    BaseMqReceiver::BaseMqReceiver(const char* mqPath)
        : m_mqPath(mqPath)
    {
        mq_attr attr;
        attr.mq_flags = 0;
        attr.mq_maxmsg = CORE_MQ_MAX_MSG;
        attr.mq_msgsize = sizeof(core::MsgBuf);
        attr.mq_curmsgs = 0;

        m_qd = mq_open(mqPath, O_RDONLY | O_CREAT, CORE_MQ_PERMS, &attr);
        PASSERT_ERRNO(m_qd != -1 && "`main()`");
    }

    void BaseMqReceiver::runMessageLoop()
    {
        core::MsgBuf buf;
        while (1)
        {
            ssize_t bytes = mq_receive(m_qd, (char*)&buf, sizeof(core::MsgBuf), NULL);
            if (bytes < 0)
                continue;

            onHandleMessage(buf);
        }
    }

}
