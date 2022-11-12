#pragma once

#include "defines.h"

namespace core {

    struct Employee
    {
        int id;
        int assembly;
        int cpp;
        int js;
        int qml;
        int opengl;
        char name[CORE_MAX_NAME_LENGTH];
    };

}
