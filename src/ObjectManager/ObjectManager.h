#pragma once
#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "../MsgDistributor/MessageClient/MessageClientEnum.h"
#include "../MsgDistributor/MessageClient/MessageClient.h"
#include "../MsgDistributor/MessageDistributor.h"
#include "../MsgDistributor/Message/MsgBodyEnum.h"

#include "../MsgDistributor/MessageDistributor.h"
#include "../MsgDistributor/Message/MessageFactory/MessageFactory.h"

#include "../MsgDistributor/Message/AnswerMessages/AnswerMessages.h"

#include <thread>
#include <iostream>
#include <chrono>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class ObjectManager : public MessageClient
{
private:
    vector<sf::Drawable*>* ObjectCollection;

public:
    ObjectManager(MessageDistributor* NewMsgDistr, MessageFactory* NewMsgFac);
    ~ObjectManager();

    void CreateTestObjects(int ObjectsAmount);

    DefaultAnswerMessage* ConstructAnswer() override;
};
#endif