#include "ThreadManager.h"

ThreadManager::ThreadManager()
{
}

ThreadManager::~ThreadManager()
{
}

Mutex* ThreadManager::GetSharedMutex()
{
    return &SharedMutex;
}

void ThreadManager::InvokeThreads()
{
    for(auto CurrentThread : ThreadCollection)
    {
        CurrentThread->launch();
    }
}

void ThreadManager::CreateThread(ThreadClient* ThreadClientToNewThread)
{
    ThreadCollection.push_back(new Thread(&ThreadClient::FunctionToThread, ThreadClientToNewThread));

    InvokeThreads();
}

