#pragma once

#include <sys/mman.h>

namespace core { struct SharedBuf; }

class SharedStorage
{
public:
    static SharedStorage& getInstance();

private:
    SharedStorage();

public:
    void shareData(const core::SharedBuf& buffer);

    SharedStorage(const SharedStorage&) = delete;
    SharedStorage& operator=(const SharedStorage&) = delete;

private:
    int 	m_fd{ -1 };
    void* 	m_address{ MAP_FAILED };
};

