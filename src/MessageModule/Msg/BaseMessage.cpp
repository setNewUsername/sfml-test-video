#include "BaseMessage.h"

BaseMessage::BaseMessage() :
Sender(MSG_CLI_NONE),
Recipient(MSG_CLI_NONE)
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

//request message

MessageRequest::MessageRequest(MsgRequestBody NewMsgBody) :
MessageBody(MSG_REQ_NONE)
{
    MessageBody = NewMsgBody;
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
}

MessageAnswer::~MessageAnswer()
{
}

//answer message