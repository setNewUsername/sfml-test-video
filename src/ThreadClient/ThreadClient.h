#pragma once
#ifndef THREADCLIENT_H
#define THREADCLIENT_H

#include <mutex>
#include <iostream>

using namespace std;

class ThreadClient
{
private:
    mutex* SharedMutex;
    string ThreadClientTag;
    bool ThreadKilled;

protected:
    bool GetThreadStatusKilled();

public:
    ThreadClient();
    virtual ~ThreadClient() {};
    void KillThread();
    void SetSharedMutex(mutex* MutexToSet);
    void Lock();
    void Unlock();
    void SetThreadClientTag(string NewName);
};

using ThrCliFuncType = void(ThreadClient::*)();

#endif