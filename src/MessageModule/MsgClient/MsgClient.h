#pragma once 
#ifndef MSGCLIENT_H
#define MSGCLIENT_H

#include <queue>
#include <string>
#include <iostream>

#include "../Msg/BaseMessage.h"
#include "MsgClientName.h"
#include "MsgClientInterface.h"
#include "../../ThreadClient/ThreadClient.h"
#include "../MsgQueue/MsgQueue.h"

using namespace std;

class MsgClient : public MsgClientInterface, public ThreadClient
{
private:
    string TagOfClient;
    MsgCliName NameOfClient;

    MsgQueue* SharedMessageQueue;

    void ConsoleMessage(string MessageToConsole);

public:
    MsgClient();
    virtual ~MsgClient();

    void SetClientName(MsgCliName NameOfClientToSet);
    void SetClientTag(string TagOfClientToSet);
    void SetSharedMsgQueue(MsgQueue* NewSharedMsgQueue);

    void AddMessage(MessageRequest* MessageToAdd);
    void AddAnswer(MessageAnswer* AnswerToAdd);

    virtual MessageAnswer* MessageRecievedCallback(MessageRequest* MessageToReactTo);
    virtual void HandleAnswer(MessageAnswer* AnswerToReactTo);
    void OnMessageRecieved(BaseMessage* Message) override;

    MsgCliName GetClientName() override;
    string GetClientTag() override;
};

#endif