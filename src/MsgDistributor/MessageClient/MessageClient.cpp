#include "MessageClient.h"

MessageClient::MessageClient() : 
MsgClientName(NONE_MSG_CLI),
MessageToAnswer(nullptr),
MsgClientTag("none"),
MsgDistr(nullptr),
MsgFactory(nullptr),
MessageReady(false),
MessageToSend(nullptr),
AnswerFromRecipient(nullptr)
{
}

MessageClient::~MessageClient()
{
}

void MessageClient::SetMsgClientName(MsgCliEnum NewClientName)
{
    MsgClientName = NewClientName;
}

MsgCliEnum MessageClient::GetMsgClientName()
{
    return MsgClientName;
}

bool MessageClient::AnswerPossible(Message* MessageToCheck)
{
    MessageToAnswer = MessageToCheck;
    return true;
}

DefaultAnswerMessage* MessageClient::Answer()
{
    DefaultAnswerMessage* Answer = nullptr;

    if(MessageToAnswer == nullptr)
    {
        cout << MsgClientTag << ": " << "I got empty message" << endl;
    }
    else
    {
        Answer = ConstructAnswer();
        MessageToAnswer = nullptr;
    }

    return Answer;
}

void MessageClient::SetMsgClientTag(string NewTag)
{
    MsgClientTag = NewTag;
}

void MessageClient::SetMsgDistr(MessageDistributor* NewMsgDistr)
{
    MsgDistr = NewMsgDistr;
}

void MessageClient::SetMessageFactory(MessageFactory* NewMsgFactory)
{
    MsgFactory = NewMsgFactory;
}

DefaultAnswerMessage* MessageClient::ConstructAnswer()
{   
    return new DefaultAnswerMessage();
}

MessageDistributor* MessageClient::GetMsgDistributor()
{
    return MsgDistr;
}

Message* MessageClient::GetMessageToAnswer()
{
    return MessageToAnswer;
}

MessageFactory* MessageClient::GetMsgFactory()
{
    return MsgFactory;
}

void MessageClient::SetupMessage(MsgBodyEnum NewMessageToSend, MsgCliEnum MsgRecipient)
{
    MessageToSend = new Message(NewMessageToSend, MsgRecipient);
    MessageReady = true;
}

Message* MessageClient::GetMessageToSend()
{
    return MessageToSend;
}

bool MessageClient::GetMessageState()
{
    return MessageReady;
}

void MessageClient::SetAnswerFromRecipient(DefaultAnswerMessage* Answer)
{
    AnswerFromRecipient = Answer;
}  

void MessageClient::ReadAnswerFromRecipient()
{
    cout << "Got message" << endl;
}

DefaultAnswerMessage* MessageClient::GetAnswerFromRecipient()
{
    return AnswerFromRecipient;
}