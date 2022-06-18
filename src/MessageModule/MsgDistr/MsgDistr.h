#pragma once
#ifndef MSGDISTR_H
#define MSGDISTR_H

#include <iostream>
#include <string>
#include <vector>
#include <thread>

#include "../MsgClient/MsgClientInterface.h"
#include "../MsgClient/MsgClientName.h"
#include "../../ThreadModule/ThreadClient/ThreadClient.h"

#include "../MsgQueue/MsgQueue.h"

using namespace std;

class MsgDistr// : public ThreadClient
{
private:
    vector<MsgClientInterface*> MessageClients;

    MsgQueue* SharedMessageQueue;

    void MessagingLoop();

    MsgClientInterface* GetClientByName(MsgCliName NameOfClientToGet);

public:
    MsgDistr();
    ~MsgDistr();

    void StartMessagingLoop();
    void SetSharedMsgQueue(MsgQueue* NewSharedMsgQueue);
    void RegistrClient(MsgClientInterface* NewClient);
};

#endif