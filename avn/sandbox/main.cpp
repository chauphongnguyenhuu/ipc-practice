#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#include <core/defines.h>
#include <core/data.h>

int main()
{
    printf("sandbox\n");

    int fd = shm_open(CORE_SHARED_MEMORY_PATH, O_RDONLY, CORE_SHARED_MEMORY_PERMS);
    PASSERT_ERRNO(fd != -1 && "`SharedStorage()`");

    void* address = mmap(NULL, CORE_SHARED_MEMORY_SIZE, PROT_READ, MAP_SHARED, fd, 0);
    PASSERT_ERRNO(address != MAP_FAILED);

    core::SharedBuf buffer;
    memcpy((char*)&buffer, address, sizeof(core::SharedBuf));

    printf("buffer.count( %d )\n", buffer.count);

    for (int i = 0; i < buffer.count; ++i)
        printf("%s\n", buffer.entries[i].name);

    return 0;
}
