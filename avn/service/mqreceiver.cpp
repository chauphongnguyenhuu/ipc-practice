#include "mqreceiver.h"

#include <string.h>
#include <vector>
#include <core/defines.h>
#include <core/data.h>
#include <core/baseproxy.h>

#include "defines.h"
#include "localstorage.h"
#include "sharedstorage.h"

MqReceiver::MqReceiver()
    : core::BaseMqReceiver(CORE_MQ_PATH_SERVICE)
    , m_deploy(new core::BaseProxy(CORE_MQ_PATH_GUESS))
{
}

void MqReceiver::onHandleMessage(const core::MsgBuf& buf)
{
    printf("[mqreceiver.cpp][MqReceiver] `onHandleMessage()` - type( %d )\n", buf.type);

    switch (buf.type)
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

            core::MsgBuf response = { .type = core::k_msgTypeSharedDataIsUpToDate, .msg = {} };
            m_deploy->send(response);

            break;
        }
        default:
        {
            fprintf(stderr, "[main.cpp] `onHandleMessage()` - type( %d ) is invalid\n", buf.type);
            break;
        }
    }
}
