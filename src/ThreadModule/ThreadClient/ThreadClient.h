#pragma once
#ifndef THREADCLIENT_H
#define THREADCLIENT_H

#include <SFML/System/Mutex.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class ThreadClient
{
private:
    Mutex* SharedMutex;
    //vector<ThreadClient::>

public:
    ThreadClient();
    virtual ~ThreadClient() = default;

    void Lock();
    void Unlock();
    void SetSharedMutex(Mutex* NewSharedMutex);

    virtual void FunctionToThread();
};

#endif