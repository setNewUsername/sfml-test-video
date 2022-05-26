#include "ScreenManager.h"

ScreenManager::ScreenManager() : 
ScreenWidth(100),
ScreenHeight(100),
ScreenWindow(nullptr),
ScreenSizeChanged(false),
ObjectsToDraw(nullptr)
{
    ObjectsToDraw = new vector<Drawable*>;
    Windows = new vector<WindowContainer*>;
}

ScreenManager::~ScreenManager()
{
}

void ScreenManager::SetScreenSize(int NewScreenWidth, int NewScreenHeight)
{
    ScreenWidth = NewScreenWidth;
    ScreenHeight = NewScreenHeight;
}

vector<Drawable*>* ScreenManager::GetObjects()
{
    return ObjectsToDraw;
}

void ScreenManager::StartScreenManagerLoop()
{
    Thread thr(&ScreenManager::ScreenManagerLoop, this);
    thr.launch();
}

void ScreenManager::ScreenManagerLoop()
{
    vector<Event*> ScreenEvents;

    for(auto CurrentWindow : *Windows)
    {
        ScreenEvents.push_back(new Event());
    }

    while((*Windows)[0]->GetWindowObj()->isOpen())
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

        
            CurrentWindow->GetWindowObj()->display();
        }
    }
}

void ScreenManager::PushWindow(unsigned int Width, unsigned int Height, string Name, WINDOWS_DESCRIPTIONS WindowDesc)
{
    WindowContainer* NewWindow = new WindowContainer();

    NewWindow->SetWindowSize(Width, Height);
    NewWindow->SetWindowName(Name);

    if((Windows->size() == 0) && (WindowDesc != MAIN_WINDOW))
    {
        WindowDesc = MAIN_WINDOW;
    }
    else
    {
        WindowDesc = NONE;
    }

    NewWindow->SetWindowDescriptor(WindowDesc);

    NewWindow->CreateWindow();

    Windows->push_back(NewWindow);
}

void ScreenManager::SetupMainWindow()
{
    WindowContainer* MainWindow = new WindowContainer();

    MainWindow->SetWindowSize(1000, 800);
    MainWindow->SetWindowName("Main Window");
    MainWindow->SetWindowDescriptor(MAIN_WINDOW);

    MainWindow->CreateWindow();

    Windows->push_back(MainWindow);
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