#include "localstorage.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <core/data.h>

std::vector<core::Employee> loadData(const char* filePath)
{
    printf("[localstorage.cpp] `loadData()` - filePath( %s )\n", filePath);

    std::vector<core::Employee> employees;

    FILE* fp = fopen(filePath, "r");
    if (!fp)
    {
        fprintf(stderr, "Could not open file( %s )", filePath);
        exit(EXIT_FAILURE);
    }

    int count;
    fscanf(fp, "%d\n", &count);

    employees.reserve(count);

    core::Employee e;
    for (int i = 0; i < count; ++i)
    {
        fscanf(fp, "%d\n", &e.id);

        fgets(e.name, CORE_MAX_NAME_LENGTH, fp);
        int lastIndex = strlen(e.name) - 1;
        if (lastIndex >= 0 && e.name[lastIndex] == '\n')
            e.name[lastIndex] = '\0';

        fscanf(fp, "%d %d %d %d %d\n", &e.assembly, &e.cpp, &e.js, &e.qml, &e.opengl);

        employees.push_back(e);
    }

    fclose(fp);

    return employees;
}

void saveData(const std::vector<core::Employee>& data)
{
    (void)data;
}
