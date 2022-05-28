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
#include "MsgDistributor/MessageDistributor.h"
#include "MsgDistributor/Message/MessageFactory/MessageFactory.h"

using namespace std;

int main(int argc, char const* argv[])
{
    MessageDistributor msgdistr;
    MessageFactory msgfac;

    WindowFactory winfac(&msgdistr, &msgfac);
    ObjectManager objmgr(&msgdistr, &msgfac);
    ThreadManager thrmmgr;

    ScreenManager srcmngr;
    srcmngr.SetSharedMutex(thrmmgr.GetSharedMutex());
    srcmngr.SetWinFactory(static_cast<WindowFactoryInterface*>(&winfac));
    srcmngr.SetWinCntrlColl(winfac.GetWindowCollection());
    srcmngr.SetupMainWindow();
    
    thrmmgr.CreateNewThread(static_cast<ThrCliFuncType>(&MessageDistributor::SetupMessageLoop), static_cast<ThreadClient*>(&msgdistr), "ObjThr");

    cout << "Hello 1" << endl;

    //WindowContainer* MainWindow = srcmngr.GetWindowContainerByDesc(MAIN_WINDOW);

    //MainWindow->SetupMessage(MSG_GET_OBJ_TO_DRAW, OBJECT_MANAGER_MSG_CLI);

    //AnswerObjMgr* AnswerFromObjectMgr = static_cast<AnswerObjMgr*>(MainWindow->GetAnswerFromRecipient());

    //MainWindow->SetDrawableObjectCollection(AnswerFromObjectMgr->GetDrawableCollection());

    //srcmngr.StartScreenManagerLoop();

    cout << "Hello 2" << endl;

    //ObjectManager objmngr(srcmngr.GetObjects());
    //objmngr.SetSharedMutex(thrmmgr.GetSharedMutex());

    //thrmmgr.CreateNewThread(static_cast<ThrCliFuncType>(&ObjectManager::Test), static_cast<ThreadClient*>(&objmngr), "ObjThr");

    //ArrayContainer arrcont;

    //arrcont.CreateArray(1000);

    //arrcont.SetRandRange(0, 10);

    //arrcont.PrintArray();

    //SorterFactory fact;

    //BubbleSorter* srt = dynamic_cast<BubbleSorter*>(fact.CreateSort(BUBBLE_SORT));

    //srt->SetArrayContPointer(&arrcont);

    //srt->SortArray();

    //arrcont.PrintArray();

    return 0;
}
