#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#include <core/defines.h>
#include <core/data.h>
#include <core/basemqreceiver.h>

class R : public core::BaseMqReceiver
{
public:
    R()
        : core::BaseMqReceiver(CORE_MQ_PATH_GUESS)
    {
    }

    void onHandleMessage(const core::MsgBuf& buf) override
    {
        printf("[main.cpp][R] `onHandleMessage()` - type( %d )\n", buf.type);

        switch (buf.type)
        {
            case core::k_msgTypeSharedDataIsUpToDate:
            {
                int fd = shm_open(CORE_SHARED_MEMORY_PATH, O_RDONLY, CORE_SHARED_MEMORY_PERMS);
                PASSERT_ERRNO(fd != -1 && "`SharedStorage()`");

                void* address = mmap(NULL, CORE_SHARED_MEMORY_SIZE, PROT_READ, MAP_SHARED, fd, 0);
                PASSERT_ERRNO(address != MAP_FAILED);

                core::SharedBuf buffer;
                memcpy((char*)&buffer, address, sizeof(core::SharedBuf));

                printf("buffer.count( %d )\n", buffer.count);

                for (int i = 0; i < buffer.count; ++i)
                    printf("%s\n", buffer.entries[i].name);

                break;
            }
            default:
            {
                fprintf(stderr, "[main.cpp] `onHandleMessage()` - type( %d ) is invalid\n", buf.type);
                break;
            }
        }
    }
};

int main()
{
    printf("sandbox\n");

    R* r = new R;
    r->runMessageLoop();
    delete r;

    return 0;
}
