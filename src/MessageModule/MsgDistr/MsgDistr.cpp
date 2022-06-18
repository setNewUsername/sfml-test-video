#include "MsgDistr.h"

MsgDistr::MsgDistr() : 
SharedMessageQueue(nullptr)
{
}

MsgDistr::~MsgDistr()
{
}

void MsgDistr::RegistrClient(MsgClientInterface* NewClient)
{
    bool UniqueClient(true);

    for(auto CurrentClient : MessageClients)
    {
        if(CurrentClient->GetClientName() == NewClient->GetClientName())
        {
            UniqueClient = false;
            cout << "Found not unique clients; registration denied for client " << NewClient->GetClientName() << "(" << NewClient->GetClientTag() << ")" << endl;
        }
    }
    if(UniqueClient)
    {
        MessageClients.push_back(NewClient);
        cout << "Client " << NewClient->GetClientName() << "(" << NewClient->GetClientTag() << ") registreted" << endl;
    }
}

void MsgDistr::MessagingLoop()
{
    vector<BaseMessage*>* MessageTmp = nullptr;
    MsgClientInterface* ClientTmp = nullptr;

    cout << "Started messaging loop" << endl;
    while(1)
    {   
        if(SharedMessageQueue != nullptr)
        {
            if(SharedMessageQueue->GetQueueSize() > 0)
            {
                //Lock();
                MessageTmp = SharedMessageQueue->GetFrontMessage();
                //Unlock();
                for(auto CurrentMessageToSend : *MessageTmp)
                {
                    if(CurrentMessageToSend != nullptr)
                    {
                        ClientTmp = GetClientByName(CurrentMessageToSend->GetMessageRecipient());
                        if(ClientTmp != nullptr)
                        {
                            ClientTmp->OnMessageRecieved(CurrentMessageToSend);
                        }
                        else
                        {
                            cout << "client is nullprt" << endl;
                        }
                    }
                }
                delete(MessageTmp);
            }
        }
    }
}

MsgClientInterface* MsgDistr::GetClientByName(MsgCliName NameOfClientToGet)
{
    MsgClientInterface* Result = nullptr;
    for(auto CurrentClient : MessageClients)
    {
        if(CurrentClient->GetClientName() == NameOfClientToGet)
        {
            Result = CurrentClient;
            break;
        }
    }
    if(Result == nullptr)
    {
        cout << "Recipient by name " << NameOfClientToGet << " wasn't registreted or doesnt't exist" << endl;
    }
    return Result;
}

void MsgDistr::StartMessagingLoop()
{
    MessagingLoop();
}

void MsgDistr::SetSharedMsgQueue(MsgQueue* NewSharedMsgQueue)
{
    SharedMessageQueue = NewSharedMsgQueue;
}