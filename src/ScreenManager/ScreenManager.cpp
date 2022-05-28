#include "ScreenManager.h"

ScreenManager::ScreenManager() : 
Windows(nullptr),
PointerToWinFactory(nullptr)
{
}

ScreenManager::~ScreenManager()
{
}

void ScreenManager::StartScreenManagerLoop()
{
    Thread thr(&ScreenManager::ScreenManagerLoop, this);
    thr.launch();
    //ScreenManagerLoop();
}

void ScreenManager::ScreenManagerLoop()
{
    vector<Event*> ScreenEvents;

    for(auto CurrentWindow : *Windows)
    {
        ScreenEvents.push_back(new Event());
    }

    RenderWindow* MainWindow = GetWindowByDesc(MAIN_WINDOW);

    while(MainWindow->isOpen())
    {
        for(int i = 0; i < Windows->size(); i++)
        {
            while((*Windows)[i]->GetWindowObj()->pollEvent(*ScreenEvents[i]))
            {
                if (ScreenEvents[i]->type == Event::Closed)
                (*Windows)[i]->GetWindowObj()->close();
            }
        }

        for(auto CurrentWindow : *Windows)
        {
            CurrentWindow->GetWindowObj()->clear(Color::White);

            CurrentWindow->DrawObjects();
        
            CurrentWindow->GetWindowObj()->display();
        }
    }
}

void ScreenManager::AddWindow(WINDOWS_DESCRIPTIONS WindowDesc)
{
    if(PointerToWinFactory != nullptr)
    {
        PointerToWinFactory->CreateWindowContainer(WindowDesc);
    }
    else
    {
        cout << "WindowContainer factory doesnt exist" << endl;
    }
}

void ScreenManager::SetupMainWindow()
{
    if(PointerToWinFactory != nullptr)
    {
        PointerToWinFactory->CreateWindowContainer(MAIN_WINDOW);
    }
    else
    {
        cout << "WindowContainer factory doesnt exist" << endl;
    }
}

RenderWindow* ScreenManager::GetWindowByDesc(WINDOWS_DESCRIPTIONS WinDesc)
{
    RenderWindow* Result;

    for(auto CurrentWindowCont : *Windows)
    {
        if(CurrentWindowCont->GetWindowDesc() == WinDesc)
        {
            Result = CurrentWindowCont->GetWindowObj();
            break;
        }
    }

    return Result;
}

WindowContainer* ScreenManager::GetWindowContainerByDesc(WINDOWS_DESCRIPTIONS WinDesc)
{
    WindowContainer* Result;

    for(auto CurrentWindowCont : *Windows)
    {
        if(CurrentWindowCont->GetWindowDesc() == WinDesc)
        {
            Result = CurrentWindowCont;
            break;
        }
    }

    return Result;
}

void ScreenManager::SetWinFactory(WindowFactoryInterface* NewPointerToWinFactory)
{
    PointerToWinFactory = NewPointerToWinFactory;
}

void ScreenManager::SetWinCntrlColl(vector<WindowContainer*>* NewWinCntrlColl)
{
    Windows = NewWinCntrlColl;
}