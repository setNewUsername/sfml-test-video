#include <iostream>

#include "ThreadModule/ThreadManager/ThreadManager.h"
#include "ThreadModule/ThreadClient/ThreadClient.h"

#include <SFML/System.hpp>

using namespace std;

class TestClass : public ThreadClient
{
private:
    
public:
    TestClass();
    ~TestClass();

    void FunctionToThread() override;
};

TestClass::TestClass()
{
}

TestClass::~TestClass()
{
}

void TestClass::FunctionToThread()
{
    while(1)
    {
        Lock();
        cout << "1" << endl;
        sf::sleep(sf::milliseconds(100));
        Unlock();
    }
}

class TestClass2 : public ThreadClient
{
private:
    
public:
    TestClass2();
    ~TestClass2();

    void FunctionToThread() override;
};

TestClass2::TestClass2()
{
}

TestClass2::~TestClass2()
{
}

void TestClass2::FunctionToThread()
{
    while(1)
    {
        Lock();
        cout << "2" << endl;
        Unlock();
    }
}

int main(int argc, char const* argv[])
{
    TestClass* tstcls = new TestClass();
    TestClass2* tstcls2 = new TestClass2();

    ThreadManager* thrmgr = new ThreadManager();

    tstcls->SetSharedMutex(thrmgr->GetSharedMutex());
    tstcls2->SetSharedMutex(thrmgr->GetSharedMutex());

    thrmgr->CreateThread(tstcls);
}