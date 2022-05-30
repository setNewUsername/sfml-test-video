#include "MsgClient.h"

MsgClient::MsgClient() : 
TagOfClient("msg_cli_notag"),
NameOfClient(MSG_CLI_NONE),
MessagesReadyToSend(false),
AnswersReadyToSend(false),
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
        Lock();
        SharedMessageQueue->AddNewMessageToQueue(static_cast<BaseMessage*>(MessageToAdd));
        Unlock();
    }
    else
    {
        ConsoleMessage("shared message queue is null");
    }
    MessagesReadyToSend = true;
    //ConsoleMessage(string("added messages; message queue size is " + to_string(MessagesToSend.size())));
}

void MsgClient::AddAnswer(MessageAnswer* AnswerToAdd)
{
    
    if(SharedMessageQueue != nullptr)
    {
        Lock();
        SharedMessageQueue->AddNewMessageToQueue(static_cast<BaseMessage*>(AnswerToAdd));
        Unlock();
    }
    else
    {
        ConsoleMessage("shared message queue is null");
    }
    
    AnswersReadyToSend = true;
    //ConsoleMessage(string("added answer; answer queue size is " + to_string(Answers.size())));
}

vector<MessageAnswer*>* MsgClient::GetAnswers()
{
    vector<MessageAnswer*>* AnswersContainer = new vector<MessageAnswer*>;
    ConsoleMessage(string("answer queue size is " + to_string(Answers.size())));
    for(int i = 0; i < Answers.size(); i++)
    {
        if(Answers.front() != nullptr)
        {
            AnswersContainer->push_back(Answers.front());
        }
        else
        {
            ConsoleMessage("nullptr answer!");
        }
        Answers.pop();
    }
    ConsoleMessage(string("answer queue size is " + to_string(Answers.size())));
    ConsoleMessage("returned answers");
    AnswersReadyToSend = false;
    return AnswersContainer;
}

vector<MessageRequest*>* MsgClient::GetMessagesToSend()
{
    vector<MessageRequest*>* MessagesContainer = new vector<MessageRequest*>;
    ConsoleMessage(string("message queue size is " + to_string(MessagesToSend.size())));
    for(int i = 0; i < MessagesToSend.size(); i++)
    {
        if(MessagesToSend.front() != nullptr)
        {
            MessagesContainer->push_back(MessagesToSend.front());
        }
        else
        {
            ConsoleMessage("nullptr message!");
        }
        MessagesToSend.pop();
    }
    ConsoleMessage(string("message queue size is " + to_string(MessagesToSend.size())));
    ConsoleMessage("returned messages");
    MessagesReadyToSend = false;
    return MessagesContainer;
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

void MsgClient::OnMessageRecive(MessageRequest* MessageToAdd)
{
    AddAnswer(ConstructAnswer(MessageToAdd));
}

void MsgClient::OnAnswerRecive(MessageAnswer* RecivedAnswer)
{
    ReactToAnswer(RecivedAnswer);
    ConsoleMessage("recieved answer");
}

void MsgClient::ConsoleMessage(string MessageToConsole)
{
    cout << "msg_client " << NameOfClient << "(" << TagOfClient << ") " << MessageToConsole << endl;
}

MessageAnswer* MsgClient::ConstructAnswer(MessageRequest* MessageToAnswerTo)
{
    MessageAnswer* Answer = new MessageAnswer();

    if(MessageToAnswerTo->GetMessageRecipient() == this->NameOfClient)
    {
        switch (MessageToAnswerTo->GetMessageBody())
        {
        case MSG_REQ_NONE:
            ConsoleMessage("NONE message recieved");
            break;
        
        case MSG_REQ_GET_0:
            ConsoleMessage("Message_0 recieved");
        break;

        case MSG_REQ_GET_1:
            ConsoleMessage("Message_1 recieved");
        break;

        default:
            ConsoleMessage("MESSAGING ERROR NOT STATED REQUEST MESSAGE_BODY");
            break;
        }
    }

    return Answer;
}

void MsgClient::ReactToAnswer(MessageAnswer* AnswerToReactTo)
{
    MsgCliName AnswerSender = AnswerToReactTo->GetMessageSender();

    string ConsoleMessageStr = "got answer from client " +  to_string(AnswerSender);

    ConsoleMessage(ConsoleMessageStr);
}

bool MsgClient::IsMessagesReady()
{
    return MessagesReadyToSend;
}

bool MsgClient::IsAnswersReady()
{
    return AnswersReadyToSend;
}

void MsgClient::SetSharedMsgQueue(MsgQueue* NewSharedMsgQueue)
{
    SharedMessageQueue = NewSharedMsgQueue;
}