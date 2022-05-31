#include "MsgQueue.h"

MsgQueue::MsgQueue()
{
}

MsgQueue::~MsgQueue()
{
}

void MsgQueue::AddNewMessageToQueue(BaseMessage* NewMessage)
{
    MessageQueue.push(NewMessage);
    cout << "Added new message by client " << NewMessage->GetMessageSender() << "; message queue size is " << MessageQueue.size() << endl;
}

vector<BaseMessage*>* MsgQueue::GetFrontMessage()
{
    cout << to_string(MessageQueue.size()) << endl;
    vector<BaseMessage*>* Messages = new vector<BaseMessage*>;

    while(!MessageQueue.empty())
    {
        if(MessageQueue.front() != nullptr)
        {
            Messages->push_back(MessageQueue.front());
        }
        else
            cout << "nullptr message" << endl;
        MessageQueue.pop();
    }

    cout << to_string(Messages->size()) << endl;
    cout << to_string(MessageQueue.size()) << endl;
    return Messages;
}

int MsgQueue::GetQueueSize()
{
    return MessageQueue.size(); 
}