#include <iostream>
#include "ThreadManager/ThreadManager.h"

#include "MessageModule/MsgDistr/MsgDistr.h"
#include "MessageModule/MsgClient/MsgClient.h"
#include "MessageModule/MsgClient/MsgClientName.h"

#include "MessageModule/MsgQueue/MsgQueue.h"
#include "MessageModule/Msg/BaseMessage.h"
#include "MessageModule/Msg/MsgRequestBody.h"

#include "VisualModule/WindowFactory/WindowFactory.h"

#include "VisualModule/WindowManager/WindowManager.h"

#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char const* argv[])
{
    WindowFactory winfac;
    WindowManager winmgr;

    winmgr.SetWindowFactory(&winfac);

    winmgr.SetupScreen();

    winmgr.ShowAllWindows();
}