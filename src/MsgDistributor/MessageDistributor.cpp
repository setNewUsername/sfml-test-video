#include "MessageDistributor.h"

MessageDistributor::MessageDistributor()
{
}

MessageDistributor::~MessageDistributor()
{
}

void MessageDistributor::RegMsgClient(MessageClientInterface* NewMsgClient)
{
    MsgClientsCollection.push_back(NewMsgClient);
}

DefaultAnswerMessage* MessageDistributor::SendMessageTo(MsgCliEnum MsgRecipient, Message* MessageToSend)
{
    DefaultAnswerMessage* AnswerFromRecipient = nullptr;

    if(GetClientByName(MsgRecipient)->AnswerPossible(MessageToSend))
    {
        AnswerFromRecipient = GetClientByName(MsgRecipient)->Answer();
    }
    
    return AnswerFromRecipient;
}

MessageClientInterface* MessageDistributor::GetClientByName(MsgCliEnum MsgClientToGet)
{
    MessageClientInterface* Result = nullptr;

    for(auto CurrentClient : MsgClientsCollection)
    {
        if(CurrentClient->GetMsgClientName() == MsgClientToGet)
        {
            Result = CurrentClient;
            break;
        }
    }

    return Result;
}

void MessageDistributor::SetupMessageLoop()
{
    cout << "hello" << endl;
    thread* thr = new thread(&MessageDistributor::MessageLoop, this);
}

void MessageDistributor::MessageLoop()
{
    cout << "hello" << endl;
    while(1)
    {
        Lock();
        for(auto CurrentMessageCli : MsgClientsCollection)
        {
            if(CurrentMessageCli->GetMessageState())
            {
                Message* MessageToSend = CurrentMessageCli->GetMessageToSend();
                if(MessageToSend == nullptr)
                    cout << "no" << endl;

                MsgCliEnum Recipient = MessageToSend->GetMsgRecipient();
                if(Recipient == OBJECT_MANAGER_MSG_CLI)
                    cout << "yes" << endl;

                CurrentMessageCli->SetAnswerFromRecipient(SendMessageTo(Recipient, MessageToSend));
            }
        }
        Unlock();
    }
}