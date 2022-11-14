#pragma once

#include "defines.h"

namespace core {

    struct Employee
    {
        int 	id;
        int 	assembly;
        int 	cpp;
        int 	js;
        int 	qml;
        int 	opengl;
        char 	name[CORE_MAX_NAME_LENGTH];
    };

    enum MsgType
    {
        k_msgTypeRefreshData,
        k_msgTypeSharedDataIsUpToDate
    };

    struct MsgBuf
    {
        MsgType type;
        char	msg[CORE_MQ_MSG_SIZE];
    };

    struct SharedBuf
    {
        struct Entry
        {
            int 	id;
            float 	average;
            char 	name[CORE_MAX_NAME_LENGTH];
        };

        int 	count;
        Entry 	entries[CORE_MAX_ENTRIES];
    };

    static_assert(sizeof(SharedBuf) <= CORE_SHARED_MEMORY_SIZE, "size of SharedBuf is too large");
}
