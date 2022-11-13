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
        k_msgTypeRefreshData = 10
    };

    struct MsgBuf
    {
        MsgType type;
        char	msg[CORE_MQ_MSG_SIZE];
    };

}
