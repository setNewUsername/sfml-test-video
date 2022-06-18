#include "ThreadClient.h"

ThreadClient::ThreadClient() : 
SharedMutex(nullptr)
{

}

void ThreadClient::SetSharedMutex(Mutex* NewSharedMutex)
{
    SharedMutex = NewSharedMutex;
}

void ThreadClient::Lock()
{
    if(SharedMutex != nullptr)
    {
        SharedMutex->lock();
    }
    else
        cout << "Mutex is nullptr" << endl;
}

void ThreadClient::Unlock()
{
    if(SharedMutex != nullptr)
    {
        SharedMutex->unlock();
    }
    else
        cout << "Mutex is nullptr" << endl;
}

void ThreadClient::FunctionToThread(){cout << "Not overrided method of ThreadClient" << endl;}