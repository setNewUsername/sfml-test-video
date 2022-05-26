#pragma once
#ifndef THREADCLIENT_H
#define THREADCLIENT_H

#include <mutex>

using namespace std;

class ThreadClient
{
private:
    mutex* SharedMutex;
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
};

using ThrCliFuncType = void(ThreadClient::*)();

#endif