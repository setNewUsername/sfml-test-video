#pragma once
#ifndef MESSAGECLIENTINTERFACE_H
#define MESSAGECLIENTINTERFACE_H

#include "../Message/Message.h"
#include "MessageClientEnum.h"
#include "../Message/AnswerMessages/AnswerMessages.h"

class MessageClientInterface
{
public:
    MessageClientInterface() {};
    virtual ~MessageClientInterface() {};

    virtual MsgCliEnum GetMsgClientName() = 0;
    virtual bool AnswerPossible(Message* MessageToCheck) = 0;
    virtual DefaultAnswerMessage* Answer() = 0;
    virtual Message* GetMessageToSend() = 0;
    virtual Message* GetMessageToAnswer() = 0;
    virtual bool GetMessageState() = 0;
    virtual void SetAnswerFromRecipient(DefaultAnswerMessage* Answer) = 0;
};

#endif