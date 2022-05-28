#pragma once
#ifndef MESSAGEDISTRIBUTOR_H
#define MESSAGEDISTRIBUTOR_H

#include <vector>
#include <thread>
#include <iostream>

#include "MessageClient/MessageClientInterface.h"
#include "MessageClient/MessageClientEnum.h"
#include "Message/Message.h"
#include "Message/AnswerMessages/AnswerMessages.h"

#include "../ThreadClient/ThreadClient.h"

using namespace std;

class MessageDistributor : public ThreadClient
{
private:
    vector<MessageClientInterface*> MsgClientsCollection;

    MessageClientInterface* GetClientByName(MsgCliEnum MsgClientToGet);

    void MessageLoop();

public:
    MessageDistributor();
    ~MessageDistributor();

    void SetupMessageLoop();

    void RegMsgClient(MessageClientInterface* NewMsgClient);
    DefaultAnswerMessage* SendMessageTo(MsgCliEnum MsgRecipient, Message* MessageToSend);
};

#endif