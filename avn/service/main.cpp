#include <stdio.h>

#include "mqreceiver.h"

int main()
{
    printf("sevice\n");

    MqReceiver* receiver = new MqReceiver();
    receiver->runMessageLoop();
    delete receiver;

    return 0;
}
