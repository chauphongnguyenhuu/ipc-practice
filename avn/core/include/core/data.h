#pragma once

#include "defines.h"

namespace core {

    struct Employee
    {
        int id;
        float average;
        char name[CORE_MAX_NAME_LENGTH];
    };

}
