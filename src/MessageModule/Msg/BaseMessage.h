#pragma once
#ifndef BASEMESSAGE_H
#define BASEMESSAGE_H

#include <iostream>
#include <string>

#include "../MsgClient/MsgClientName.h"
#include "MsgRequestBody.h"

using namespace std;

class BaseMessage
{
private:
    MsgCliName Sender;
    MsgCliName Recipient;
    MsgType MessageType;

public:
    BaseMessage();
    virtual ~BaseMessage();

    void SetMessageType(MsgType NewMessageType);
    void SetMessageSender(MsgCliName NewSender);
    void SetMessageRecipient(MsgCliName NewRecipient);

    MsgType GetMessageType();
    MsgCliName GetMessageSender();
    MsgCliName GetMessageRecipient();
};

//requests

class MessageRequest : public BaseMessage
{
private:
    MsgRequestBody MessageBody;

public:
    MessageRequest(MsgRequestBody NewMsgBody);
    ~MessageRequest();

    MsgRequestBody GetMessageBody();
};

//requests

//answers

class MessageAnswer : public BaseMessage
{
private:
    
public:
    MessageAnswer();
    ~MessageAnswer();
};

//answers

#endif