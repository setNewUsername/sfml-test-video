#pragma once
#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "../ThreadClient/ThreadClient.h"

#include <thread>
#include <iostream>
#include <chrono>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class ObjectManager : public ThreadClient
{
private:
    vector<sf::Drawable*>* ObjetsVec;

public:
    ObjectManager(vector<sf::Drawable*>* Objects);
    ~ObjectManager();

    void Test();
};
#endif