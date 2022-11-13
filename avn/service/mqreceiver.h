#pragma once

#include <core/basemqreceiver.h>

class MqReceiver : public core::BaseMqReceiver
{
public:
    MqReceiver();

protected:
    void onHandleMessage(const core::MsgBuf& buf) override;
};
