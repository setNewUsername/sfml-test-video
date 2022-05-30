#include "MsgDistr.h"

MsgDistr::MsgDistr()
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

/*
void MsgDistr::MessagingLoop()
{
    cout << "Started messaging loop" << endl;
    while(1)
    {
        for(auto CurrentClient : MessageClients)
        {
            if(CurrentClient != nullptr)
            {
                cout << "Checking up for messages and answers for client " << CurrentClient->GetClientName() << "(" << CurrentClient->GetClientTag() << ")" << endl;

                if (CurrentClient->IsMessagesReady())
                    SendClientsMessages(CurrentClient);
                if(CurrentClient->IsAnswersReady())
                    SendClientsAnswers(CurrentClient);
            }
        }
        std::this_thread::sleep_for(10000ms);
    }
}*/

void MsgDistr::SendClientsMessages(MsgClientInterface* Client)
{
    Lock();
    vector<MessageRequest*>* MessagesTmp = Client->GetMessagesToSend();
    Unlock();

    if(MessagesTmp != nullptr)
    {
        cout << "Client " << Client->GetClientName() << "(" << Client->GetClientTag() << ") returned message set with " << MessagesTmp->size() << " messages" << endl;
        for(auto CurrentMessageToSend : *MessagesTmp)
        {
            MsgClientInterface* Recipient = GetClientByName(CurrentMessageToSend->GetMessageRecipient());
            if(Recipient != nullptr)
            {
                Recipient->OnMessageRecive(CurrentMessageToSend);
                cout << "Send message to " << Recipient->GetClientName() << "(" << Recipient->GetClientTag() << ")" << endl;
            }
            else
            {
                cout << "Recipient " << CurrentMessageToSend->GetMessageRecipient() << " is nullptr" << endl;
            }
        }
    }
    else
    {
        cout << "Client " << Client->GetClientName() << "(" << Client->GetClientTag() << ") returned empty message set" << endl;
    }
}

void MsgDistr::SendClientsAnswers(MsgClientInterface* Client)
{
    vector<MessageAnswer*>* AnswersTmp = Client->GetAnswers();

    if(AnswersTmp != nullptr)
    {
        cout << "Client " << Client->GetClientName() << "(" << Client->GetClientTag() << ") returned answer set with " << AnswersTmp->size() << " answers" << endl;
        for(auto CurrentAnswer : *AnswersTmp)
        {
            MsgClientInterface* Recipient = GetClientByName(CurrentAnswer->GetMessageRecipient());
            if(Recipient != nullptr)
            {
                Recipient->OnAnswerRecive(CurrentAnswer);
                cout << "Send answer to " << Recipient->GetClientName() << "(" << Recipient->GetClientTag() << ")" << endl;
            }
            else
            {
                cout << "Recipient " << CurrentAnswer->GetMessageRecipient() << " is nullptr" << endl;
            }
        }
    }
    else
    {
        cout << "Client " << Client->GetClientName() << "(" << Client->GetClientTag() << ") returned empty answer set" << endl;
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