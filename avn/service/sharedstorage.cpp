#include "sharedstorage.h"

#include <assert.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include <core/defines.h>
#include <core/data.h>

SharedStorage& SharedStorage::getInstance()
{
    static SharedStorage instance;
    return instance;
}

SharedStorage::SharedStorage()
{
    m_fd = shm_open(CORE_SHARED_MEMORY_PATH, O_RDWR | O_CREAT, CORE_SHARED_MEMORY_PERMS);
    PASSERT_ERRNO(m_fd != -1 && "`SharedStorage()`");

    ftruncate(m_fd, CORE_SHARED_MEMORY_SIZE);

    m_address = mmap(NULL, CORE_SHARED_MEMORY_SIZE, PROT_WRITE, MAP_SHARED, m_fd, 0);
    PASSERT_ERRNO(m_address != MAP_FAILED && "`SharedStorage()`");
}

void SharedStorage::shareData(const core::SharedBuf& buffer)
{
    printf("[sharedstorage.cpp][SharedStorage] `shareData()`\n");
    assert(m_address != MAP_FAILED && "`shareData()`");
    memcpy(m_address, &buffer, sizeof(core::SharedBuf));
}
