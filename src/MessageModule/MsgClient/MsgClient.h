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

    queue<MessageRequest*> MessagesToSend;
    queue<MessageAnswer*> Answers;

    bool MessagesReadyToSend;
    bool AnswersReadyToSend;

    void ConsoleMessage(string MessageToConsole);

public:
    MsgClient();
    virtual ~MsgClient();

    void SetClientName(MsgCliName NameOfClientToSet);
    void SetClientTag(string TagOfClientToSet);
    void SetSharedMsgQueue(MsgQueue* NewSharedMsgQueue);

    void AddMessage(MessageRequest* MessageToAdd);
    void AddAnswer(MessageAnswer* AnswerToAdd);

    virtual MessageAnswer* ConstructAnswer(MessageRequest* MessageToAnswerTo);
    virtual void ReactToAnswer(MessageAnswer* AnswerToReactTo);

    void OnMessageRecive(MessageRequest* MessageToAdd) override;
    void OnAnswerRecive(MessageAnswer* RecivedAnswer) override;
    vector<MessageAnswer*>* GetAnswers() override;
    vector<MessageRequest*>* GetMessagesToSend() override;
    MsgCliName GetClientName() override;
    string GetClientTag() override;
    bool IsMessagesReady() override;
    bool IsAnswersReady() override;
};

#endif