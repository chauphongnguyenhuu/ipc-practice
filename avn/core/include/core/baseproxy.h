#pragma once

#include <mqueue.h>

namespace core {

    class MsgBuf;

    class BaseProxy
    {
    public:
        BaseProxy(const char* mqPath);
        virtual ~BaseProxy();

        void send(const MsgBuf& buf);

    private:
        mqd_t m_qd{ -1 };
    };

}
