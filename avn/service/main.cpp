#include <iostream>
#include <core/data.h>

#include "defines.h"
#include "fileutils.h"

int main()
{
    std::vector<core::Employee> employees = loadData(DATA_FILE_PATH);

    return 0;
}
