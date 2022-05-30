#pragma once
#ifndef MSGCLIENTINTERFACE_H
#define MSGCLIENTINTERFACE_H

#include <queue>
#include <string>
#include <iostream>

#include "../Msg/BaseMessage.h"
#include "MsgClientName.h"

using namespace std;

class MsgClientInterface
{
public:
    MsgClientInterface(){};
    virtual ~MsgClientInterface(){};

    virtual void OnMessageRecive(MessageRequest* MessageToAdd) = 0;
    virtual void OnAnswerRecive(MessageAnswer* RecivedAnswer) = 0;
    
    virtual vector<MessageAnswer*>* GetAnswers() = 0;
    virtual vector<MessageRequest*>* GetMessagesToSend() = 0;
    virtual MsgCliName GetClientName() = 0;
    virtual string GetClientTag() = 0;

    virtual bool IsMessagesReady() = 0;
    virtual bool IsAnswersReady() = 0;
};

#endif