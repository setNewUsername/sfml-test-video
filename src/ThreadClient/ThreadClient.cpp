#include "ThreadClient.h"

ThreadClient::ThreadClient() : 
SharedMutex(nullptr),
ThreadKilled(false),
ThreadClientTag("none_thr_cli_tag")
{
}

void ThreadClient::SetSharedMutex(mutex* MutexToSet)
{
    SharedMutex = MutexToSet;
}

void ThreadClient::Lock()
{
    if(SharedMutex != nullptr)
    {
        SharedMutex->lock();
        cout << "mutex is locked by " << ThreadClientTag << endl;
    }
    else
    {
        cout << ThreadClientTag << "'s mutex is nullptr" << endl;
    }
}

void ThreadClient::Unlock()
{
    if(SharedMutex != nullptr)
    {
        SharedMutex->unlock();
        cout << "mutex is unlocked by " << ThreadClientTag << endl;
    }
    else
    {
        cout << ThreadClientTag << "'s mutex is nullptr" << endl;
    }
}

void ThreadClient::KillThread()
{
    ThreadKilled = true;
}

bool ThreadClient::GetThreadStatusKilled()
{
    return ThreadKilled;
}

void ThreadClient::SetThreadClientTag(string NewName)
{
    ThreadClientTag = NewName;
}