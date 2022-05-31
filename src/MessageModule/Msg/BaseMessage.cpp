#include "BaseMessage.h"

BaseMessage::BaseMessage() :
Sender(MSG_CLI_NONE),
Recipient(MSG_CLI_NONE),
MessageType(MSG_TYPE_NONE)
{
    cout << "message construted" << endl;
}

BaseMessage::~BaseMessage()
{
    cout << "message destructed" << endl;
}

void BaseMessage::SetMessageSender(MsgCliName NewSender)
{
    Sender = NewSender;
}

void BaseMessage::SetMessageRecipient(MsgCliName NewRecipient)
{   
    Recipient = NewRecipient;
}

MsgCliName BaseMessage::GetMessageSender()
{
    return Sender; 
}

MsgCliName BaseMessage::GetMessageRecipient()
{
    return Recipient;
}

void BaseMessage::SetMessageType(MsgType NewMessageType)
{
    MessageType = NewMessageType;
}

MsgType BaseMessage::GetMessageType()
{
    return MessageType;
}

//request message

MessageRequest::MessageRequest(MsgRequestBody NewMsgBody) :
MessageBody(MSG_REQ_NONE)
{
    MessageBody = NewMsgBody;
    SetMessageType(MSG_TYPE_REQUEST);
}

MessageRequest::~MessageRequest()
{
}

MsgRequestBody MessageRequest::GetMessageBody()
{
    return MessageBody;
}

//request message

//answer message

MessageAnswer::MessageAnswer()
{
    SetMessageType(MSG_TYPE_ANSWER);
}

MessageAnswer::~MessageAnswer()
{
}

//answer message