#include "ThreadManager.h"

ThreadManager::ThreadManager()
{  
}

ThreadManager::~ThreadManager()
{
}

void ThreadManager::CreateNewThread(void(ThreadClient::*Func)(), ThreadClient* obj, string NewThreadTag)
{
    thread* thr = new thread(Func, obj);
    cout << "Started new thread; id = " << thr->get_id() << " tag = " << NewThreadTag << endl;

    AliveThread* NewThread = new AliveThread(thr, NewThreadTag, obj);

    AliveThreadsColl.push_back(NewThread);
}

mutex* ThreadManager::GetSharedMutex()
{
    return &SharedMutex;
}

ThreadManager::AliveThread* ThreadManager::GetThreadByTag(string ThreadTag)
{
    AliveThread* pThreadToReturn = nullptr;

    for(auto CurrentThread : AliveThreadsColl)
    {
        if(CurrentThread->GetTag() == ThreadTag)
        {
            pThreadToReturn = CurrentThread;
            break;
        }
    }

    return pThreadToReturn;
}

void ThreadManager::StopThreadByTag(string ThreadTag)
{
    GetThreadByTag(ThreadTag)->GetThreadInvoker()->KillThread();
}

ThreadManager::AliveThread::AliveThread(thread* NewThread, string NewThreadTag, ThreadClient* NewThreadInvoker) : 
Thread(nullptr),
ThreadTag("no_tag"),
ThreadInvoker(nullptr)
{
    Thread = NewThread;
    ThreadTag = NewThreadTag;
    ThreadInvoker = NewThreadInvoker;
}
    
ThreadManager::AliveThread::~AliveThread()
{
}

thread* ThreadManager::AliveThread::GetThread()
{
    return Thread;
}

string ThreadManager::AliveThread::GetTag()
{
    return ThreadTag;
}

ThreadClient* ThreadManager::AliveThread::GetThreadInvoker()
{
    return ThreadInvoker;
}