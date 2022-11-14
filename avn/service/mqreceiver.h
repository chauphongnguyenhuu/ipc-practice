#pragma once

#include <core/basemqreceiver.h>

namespace core { class BaseProxy; }

class MqReceiver : public core::BaseMqReceiver
{
public:
    MqReceiver();

protected:
    void onHandleMessage(const core::MsgBuf& buf) override;

private:
    core::BaseProxy* m_deploy{ nullptr };
};
