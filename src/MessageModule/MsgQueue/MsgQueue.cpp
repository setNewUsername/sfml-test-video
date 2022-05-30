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
    cout << "Added new message by client " << NewMessage->GetMessageSender() << endl;
}

BaseMessage* MsgQueue::GetFrontMessage()
{
    BaseMessage* Result = MessageQueue.front();
    if(Result == nullptr)
        cout << "Nullptr message" << endl;
    MessageQueue.pop();
    return Result;
}