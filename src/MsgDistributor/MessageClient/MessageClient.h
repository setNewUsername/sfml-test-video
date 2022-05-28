#pragma once
#ifndef MESSAGECLIENT_H
#define MESSAGECLIENT_H

#include "MessageClientEnum.h"
#include "../Message/Message.h"
#include "../Message/MsgBodyEnum.h"
#include "MessageClientInterface.h"
#include "../MessageDistributor.h"
#include "../Message/MessageFactory/MessageFactory.h"
#include "../Message/AnswerMessages/AnswerMessages.h"

#include <iostream>
#include <string>

using namespace std;

class MessageClient : public MessageClientInterface
{
private:
    string MsgClientTag;
    MsgCliEnum MsgClientName;

    Message* MessageToAnswer;
    Message* MessageToSend;

    DefaultAnswerMessage* AnswerFromRecipient;

    MessageDistributor* MsgDistr;
    MessageFactory* MsgFactory;
    bool MessageReady;

public:
    MessageClient();
    ~MessageClient();

    void SetMsgClientTag(string NewTag);
    void SetMsgClientName(MsgCliEnum NewClientName);

    void SetMsgDistr(MessageDistributor* NewMsgDistr);
    void SetMessageFactory(MessageFactory* NewMsgFactory);

    void SetupMessage(MsgBodyEnum NewMessageToSend, MsgCliEnum MsgRecipient);

    DefaultAnswerMessage* GetAnswerFromRecipient();

    MessageDistributor* GetMsgDistributor();
    MessageFactory* GetMsgFactory();

    MsgCliEnum GetMsgClientName() override;
    bool AnswerPossible(Message* MessageToCheck) override;
    DefaultAnswerMessage* Answer() override;
    Message* GetMessageToSend() override;
    Message* GetMessageToAnswer() override;
    bool GetMessageState() override;
    virtual void SetAnswerFromRecipient(DefaultAnswerMessage* Answer) override;

    virtual void ReadAnswerFromRecipient();
    virtual DefaultAnswerMessage* ConstructAnswer();
};

#endif