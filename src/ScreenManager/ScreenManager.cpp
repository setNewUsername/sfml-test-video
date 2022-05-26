#include "ScreenManager.h"

ScreenManager::ScreenManager() : 
ObjectsToDraw(nullptr)
{
    ObjectsToDraw = new vector<Drawable*>;
    Windows = new vector<WindowContainer*>;
}

ScreenManager::~ScreenManager()
{
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

void ScreenManager::SetupMainWindow(unsigned int MainWindowWidth, unsigned int MainWindowHeight)
{
    WindowContainer* MainWindow = new WindowContainer();

    MainWindow->SetWindowSize(MainWindowWidth, MainWindowHeight);
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