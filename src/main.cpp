#include <iostream>
#include "ScreenManager/ScreenManager.h"
#include "ThreadManager/ThreadManager.h"
#include "ObjectManager/ObjectManager.h"
#include "test/test.h"

using namespace std;

int main(int argc, char const* argv[])
{
    ThreadManager thrmmgr;

    ScreenManager srcmngr;
    srcmngr.SetupMainWindow(1000, 800);
    srcmngr.SetSharedMutex(thrmmgr.GetSharedMutex());

    srcmngr.PushWindow(500, 500, "window 1", NONE);

    srcmngr.StartScreenManagerLoop();

    ObjectManager objmngr(srcmngr.GetObjects());
    objmngr.SetSharedMutex(thrmmgr.GetSharedMutex());

    //thrmmgr.CreateNewThread(static_cast<ThrCliFuncType>(&ObjectManager::Test), static_cast<ThreadClient*>(&objmngr), "ObjThr");

    //thrmmgr.StopThreadByTag("ObjThr");

    //srcmngr.StartWindow();

    //srcmngr.StartScreenManagerLoop();

    return 0;
}
