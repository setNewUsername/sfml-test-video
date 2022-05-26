#include <iostream>
#include "ScreenManager/ScreenManager.h"
#include "ThreadManager/ThreadManager.h"
#include "ObjectManager/ObjectManager.h"
#include "ScreenManager/WindowFactory/WindowFactory.h"
#include "test/test.h"

using namespace std;

int main(int argc, char const* argv[])
{
    WindowFactory winfac;
    ThreadManager thrmmgr;


    ScreenManager srcmngr;
    srcmngr.SetSharedMutex(thrmmgr.GetSharedMutex());

    srcmngr.SetWinFactory(static_cast<WindowFactoryInterface*>(&winfac));
    srcmngr.SetWinCntrlColl(winfac.GetWindowCollection());

    srcmngr.SetupMainWindow();
    srcmngr.AddWindow(WINDOW_ONE);

    srcmngr.StartScreenManagerLoop();

    //ObjectManager objmngr(srcmngr.GetObjects());
    //objmngr.SetSharedMutex(thrmmgr.GetSharedMutex());

    //thrmmgr.CreateNewThread(static_cast<ThrCliFuncType>(&ObjectManager::Test), static_cast<ThreadClient*>(&objmngr), "ObjThr");

    return 0;
}
