#pragma once
#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include "../Msg/BaseMessage.h"

using namespace std;

class MsgQueue
{
private:
    queue<BaseMessage*> MessageQueue;

public:
    MsgQueue();
    ~MsgQueue();

    void AddNewMessageToQueue(BaseMessage* NewMessage);
    vector<BaseMessage*>* GetFrontMessage();
    int GetQueueSize();
};

#endif