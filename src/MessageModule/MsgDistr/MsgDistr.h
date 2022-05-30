#pragma once
#ifndef MSGDISTR_H
#define MSGDISTR_H

#include <iostream>
#include <string>
#include <vector>
#include <thread>

#include "../MsgClient/MsgClientInterface.h"
#include "../MsgClient/MsgClientName.h"
#include "../../ThreadClient/ThreadClient.h"

using namespace std;

class MsgDistr : public ThreadClient
{
private:
    vector<MsgClientInterface*> MessageClients;

    void MessagingLoop();

    void SendClientsMessages(MsgClientInterface* Client);
    void SendClientsAnswers(MsgClientInterface* Client);

    MsgClientInterface* GetClientByName(MsgCliName NameOfClientToGet);

public:
    MsgDistr();
    ~MsgDistr();

    void StartMessagingLoop();

    void RegistrClient(MsgClientInterface* NewClient);
};

#endif