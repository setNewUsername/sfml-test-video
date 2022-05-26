#pragma once
#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <vector>
#include <thread>
#include <mutex>
#include <iostream>

#include "../ObjectManager/ObjectManager.h"
#include "../ThreadClient/ThreadClient.h"

using namespace std;

class ThreadManager
{
private:
    mutex SharedMutex;

    class AliveThread
    {
    private:
        ThreadClient* ThreadInvoker;
        thread* Thread;
        string ThreadTag;

    public:
        AliveThread(thread* NewThread, string NewThreadTag, ThreadClient* NewThreadInvoker);
        ~AliveThread();

        ThreadClient* GetThreadInvoker();
        thread* GetThread();
        string GetTag();
    };
    
    vector<AliveThread*> AliveThreadsColl;

    AliveThread* GetThreadByTag(string ThreadTag);

public:
    ThreadManager();
    ~ThreadManager();

    void CreateNewThread(void(ThreadClient::*Func)(), ThreadClient* obj, string NewThreadTag);

    void StopThreadByTag(string ThreadTag);

    mutex* GetSharedMutex();
};
#endif