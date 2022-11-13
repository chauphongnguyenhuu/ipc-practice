#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mqueue.h>
#include <sys/stat.h>

#include <core/defines.h>
#include <core/data.h>

#include "defines.h"
#include "localstorage.h"

void onHandleMessage(const core::MsgBuf& msg);

int main()
{
    printf("sevice\n");

    mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = CORE_MQ_MAX_MSG;
    attr.mq_msgsize = sizeof(core::MsgBuf);
    attr.mq_curmsgs = 0;

    mqd_t qd = mq_open(CORE_MQ_PATH_SERVICE, O_RDONLY | O_CREAT, CORE_MQ_PERMS, &attr);
    PASSERT_ERRNO(qd != -1 && "`main()`");

    core::MsgBuf msg;
    while (1)
    {
        ssize_t bytes = mq_receive(qd, (char*)&msg, sizeof(core::MsgBuf), NULL);
        if (bytes < 0)
            continue;

        onHandleMessage(msg);
    }

    return 0;
}

void onHandleMessage(const core::MsgBuf& msg)
{
    printf("[main.cpp] `onHandleMessage()` - type( %d )\n", msg.type);

    switch (msg.type)
    {
        case core::MsgType::k_msgTypeRefreshData:
        {
            std::vector<core::Employee> data = loadData(DATA_FILE_PATH);
            printf("[main.cpp] `onHandleMessage()` - number of employee is loaded: %ld\n", data.size());
            break;
        }
        default:
        {
            fprintf(stderr, "[main.cpp] `onHandleMessage()` - type( %d ) is invalid\n", msg.type);
            break;
        }
    }
}
