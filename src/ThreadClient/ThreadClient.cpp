#include "ThreadClient.h"

ThreadClient::ThreadClient() : 
SharedMutex(nullptr),
ThreadKilled(false)
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
    }
}

void ThreadClient::Unlock()
{
    if(SharedMutex != nullptr)
    {
        SharedMutex->unlock();
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