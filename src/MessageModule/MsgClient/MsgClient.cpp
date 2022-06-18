#include "MsgClient.h"

MsgClient::MsgClient() : 
TagOfClient("msg_cli_notag"),
NameOfClient(MSG_CLI_NONE),
SharedMessageQueue(nullptr)
{
    cout << "Created new msg_client" << endl;
}

MsgClient::~MsgClient()
{
}

void MsgClient::SetClientName(MsgCliName NameOfClientToSet)
{
    NameOfClient = NameOfClientToSet;
    cout << "New msg_client name is " << NameOfClient << endl;
}

void MsgClient::SetClientTag(string TagOfClientToSet)
{
    TagOfClient = TagOfClientToSet;
    cout << "New msg_client tag is " << TagOfClient << endl;
}

void MsgClient::AddMessage(MessageRequest* MessageToAdd)
{
    if(SharedMessageQueue != nullptr)
    {
        if(MessageToAdd->GetMessageType() == MSG_TYPE_REQUEST)
        {
            //Lock();
            SharedMessageQueue->AddNewMessageToQueue(static_cast<BaseMessage*>(MessageToAdd));
            //Unlock();
        }
        else
        {
            ConsoleMessage("wrong message type");
        }
    }
    else
    {
        ConsoleMessage("shared message queue is nullptr");
    }
}

void MsgClient::AddAnswer(MessageAnswer* AnswerToAdd)
{
    
    if(SharedMessageQueue != nullptr)
    {
        if(AnswerToAdd->GetMessageType() == MSG_TYPE_ANSWER)
        {
            //Lock();
            SharedMessageQueue->AddNewMessageToQueue(static_cast<BaseMessage*>(AnswerToAdd));
            //Unlock();
        }
        else
        {
            ConsoleMessage("wrong message type");
        }
    }
    else
    {
        ConsoleMessage("shared message queue is null");
    }
}

MsgCliName MsgClient::GetClientName()
{
    return NameOfClient;
    ConsoleMessage("returned name");
}

string MsgClient::GetClientTag()
{
    return TagOfClient;
    ConsoleMessage("returned tag");
}

void MsgClient::ConsoleMessage(string MessageToConsole)
{
    cout << "msg_client " << NameOfClient << "(" << TagOfClient << ") " << MessageToConsole << endl;
}

void MsgClient::SetSharedMsgQueue(MsgQueue* NewSharedMsgQueue)
{
    SharedMessageQueue = NewSharedMsgQueue;
}

void MsgClient::OnMessageRecieved(BaseMessage* Message)
{
    MsgType MessageType = Message->GetMessageType();
    switch (MessageType)
    {
    case MSG_TYPE_NONE:
        cout << "NONE type of massege" << endl;
        delete(Message);
        break;
    
    case MSG_TYPE_REQUEST:
        SharedMessageQueue->AddNewMessageToQueue(static_cast<BaseMessage*>(MessageRecievedCallback(static_cast<MessageRequest*>(Message))));
        break;

    case MSG_TYPE_ANSWER:
        HandleAnswer(static_cast<MessageAnswer*>(Message));
        break;

    default:
        cout << "ERROR NOT STATED MESSAGE TYPE" << endl;
        break;
    }
}

MessageAnswer* MsgClient::MessageRecievedCallback(MessageRequest* MessageToReactTo)
{
    MessageAnswer* mes = new MessageAnswer();
    ConsoleMessage("base class method called, override required; sending empty answer");
    return mes;
}

void MsgClient::HandleAnswer(MessageAnswer* AnswerToReactTo)
{}