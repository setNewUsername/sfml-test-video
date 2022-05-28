#pragma once 
#ifndef MESSAGE_H
#define MESSAGE_H

#include "MsgBodyEnum.h"
#include "../MessageClient/MessageClientEnum.h"

class Message
{
private:
    MsgBodyEnum MessageToRecipient;
    MsgCliEnum Recipient;

public:
    Message(MsgBodyEnum NewMessageToRecipient, MsgCliEnum NewRecipient);
    ~Message();

    MsgCliEnum GetMsgRecipient();
    MsgBodyEnum GetMessageBody();
};

#endif