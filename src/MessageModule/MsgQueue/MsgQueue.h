#pragma once
#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include <queue>
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
    BaseMessage* GetFrontMessage();
};

#endif