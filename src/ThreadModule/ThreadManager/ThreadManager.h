#pragma once
#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <SFML/System/Thread.hpp>
#include <SFML/System/Mutex.hpp>
#include <vector>
#include <iostream>

#include "../ThreadClient/ThreadClient.h"

using namespace std;
using namespace sf;

class ThreadManager
{
private:
    Mutex SharedMutex;
    vector<Thread*> ThreadCollection;

    void InvokeThreads();

public:
    ThreadManager();
    ~ThreadManager();

    Mutex* GetSharedMutex();

    void CreateThread(ThreadClient* ThreadClientToNewThread);
};

#endif