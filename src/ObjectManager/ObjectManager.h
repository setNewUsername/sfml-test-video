#pragma once
#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <thread>
#include <iostream>
#include <chrono>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class ObjectManager
{
private:
    std::vector<sf::Drawable*>* ObjectCollection;

public:
    ObjectManager();
    ~ObjectManager();

    void CreateTestObjects(int ObjectsAmount);
};
#endif