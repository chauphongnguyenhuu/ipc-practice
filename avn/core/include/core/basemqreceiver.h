#pragma once

#include <mqueue.h>
#include <string>

namespace core {

    struct MsgBuf;

    class BaseMqReceiver
    {
    public:
        BaseMqReceiver(const char* mqPath);
        virtual ~BaseMqReceiver() = default;

        void runMessageLoop();

    protected:
        virtual void onHandleMessage(const MsgBuf& buf) = 0;

    private:
        mqd_t 		m_qd{ -1 };
        std::string m_mqPath;
    };

}
