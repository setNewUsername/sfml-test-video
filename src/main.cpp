#include <iostream>
#include "ScreenManager/ScreenManager.h"
#include "ThreadManager/ThreadManager.h"
#include "ObjectManager/ObjectManager.h"
#include "ScreenManager/WindowFactory/WindowFactory.h"
#include "test/test.h"
#include "ArrayContainer/ArrayContainer.h"
#include "Sorter/BubbleSorter/BubbleSorter.h"
#include "Sorter/SorterFactory/SorterFactory.h"
#include "Sorter/SortirationTypesEnum.h"

using namespace std;

int main(int argc, char const* argv[])
{
    //WindowFactory winfac;
    //ThreadManager thrmmgr;

    //ScreenManager srcmngr;
    //srcmngr.SetSharedMutex(thrmmgr.GetSharedMutex());

    //srcmngr.SetWinFactory(static_cast<WindowFactoryInterface*>(&winfac));
    //srcmngr.SetWinCntrlColl(winfac.GetWindowCollection());

    //srcmngr.SetupMainWindow();
    //srcmngr.AddWindow(WINDOW_ONE);

    //srcmngr.StartScreenManagerLoop();

    //ObjectManager objmngr(srcmngr.GetObjects());
    //objmngr.SetSharedMutex(thrmmgr.GetSharedMutex());

    //thrmmgr.CreateNewThread(static_cast<ThrCliFuncType>(&ObjectManager::Test), static_cast<ThreadClient*>(&objmngr), "ObjThr");

    ArrayContainer arrcont;

    arrcont.CreateArray(1000);

    arrcont.SetRandRange(0, 10);

    arrcont.PrintArray();

    SorterFactory fact;

    BubbleSorter* srt = static_cast<BubbleSorter*>(fact.CreateSort(SELECTION_SORT));

    srt->SetArrayContPointer(&arrcont);

    srt->SortArray();

    arrcont.PrintArray();

    return 0;
}
