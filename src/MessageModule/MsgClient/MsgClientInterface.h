#pragma once
#ifndef MSGCLIENTINTERFACE_H
#define MSGCLIENTINTERFACE_H

#include <queue>
#include <string>
#include <iostream>

#include "../Msg/BaseMessage.h"
#include "MsgClientName.h"

using namespace std;

class MsgClientInterface
{
public:
    MsgClientInterface(){};
    virtual ~MsgClientInterface(){};
    
    virtual void OnMessageRecieved(BaseMessage* Message) = 0;

    virtual MsgCliName GetClientName() = 0;
    virtual string GetClientTag() = 0;
};

#endif