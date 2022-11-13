#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <mqueue.h>
#include <sys/stat.h>

#include <core/defines.h>
#include <core/data.h>

#include "defines.h"
#include "localstorage.h"
#include "sharedstorage.h"

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
            std::vector<core::Employee> employees = loadData(DATA_FILE_PATH);
            printf("[main.cpp] `onHandleMessage()` - number of employee is loaded: %ld\n", employees.size());

            core::SharedBuf* buffer = new core::SharedBuf;
            buffer->count = employees.size();
            for (int i = 0; i < buffer->count; ++i)
            {
                core::SharedBuf::Entry& entry = buffer->entries[i];
                const core::Employee& e = employees[i];
                entry.id = e.id;
                entry.average = (e.assembly + e.cpp + e.js + e.qml + e.opengl) / 5.0f;
                strncpy(entry.name, e.name, CORE_MAX_NAME_LENGTH);
            }
            SharedStorage& sharedStorage = SharedStorage::getInstance();
            sharedStorage.shareData(*buffer);
            delete buffer;

            printf("shared ok\n");

            // @TODO: notify shared data is updated

            break;
        }
        default:
        {
            fprintf(stderr, "[main.cpp] `onHandleMessage()` - type( %d ) is invalid\n", msg.type);
            break;
        }
    }
}
