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

    /*
    Syb class. Contains thread
    */
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
    
    /*
    Contains pointers to thread containers
    */
    vector<AliveThread*> AliveThreadsColl;

    AliveThread* GetThreadByTag(string ThreadTag);

public:
    ThreadManager();
    ~ThreadManager();

    /*
    Creates new thread for method of object
    */
    void CreateNewThread(void(ThreadClient::*Func)(), ThreadClient* obj, string NewThreadTag);

    /*
    Kills thread by tag
    */
    void StopThreadByTag(string ThreadTag);

    /*
    Returns mutex for all threads
    */
    mutex* GetSharedMutex();
};
#endif