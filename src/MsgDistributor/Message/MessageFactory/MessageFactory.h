#pragma once
#ifndef MESSAGEFACTORY_H
#define MESSAGEFACTORY_H

#include "../Message.h"
#include "../MsgBodyEnum.h"

class MessageFactory
{
private:
    
public:
    MessageFactory();
    ~MessageFactory();

    Message* operator [] (MsgBodyEnum NewMsgBody)
    {
        //return new Message(NewMsgBody);
        return nullptr;
    }
};


#endif