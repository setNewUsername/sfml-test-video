#pragma once
#ifndef SCREENMANAGER_H
#define SCREEMMANAGER_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../ThreadClient/ThreadClient.h"
#include "Window/WindowContainer.h"
#include "WindowFactory/WindowFactoryInterface.h"

using namespace sf;
using namespace std;

class ScreenManager : public ThreadClient
{
private:
    /*
    Contains pointers to Drawable objects
    */
    vector<Drawable*>* ObjectsToDraw;
    /*
    Contains pointers to containers for RenredWindow 
    */
    vector<WindowContainer*>* Windows;

    WindowFactoryInterface* PointerToWinFactory;

    /*
    Draw all windows
    */
    void ScreenManagerLoop();

public:
    ScreenManager();
    ~ScreenManager();

    vector<Drawable*>* GetObjects();

    /*
    Returns pointer to window
    */
    RenderWindow* GetWindowByDesc(WINDOWS_DESCRIPTIONS WinDesc);

    /*
    Initiates ScreenManagerLoop in new thread
    */
    void StartScreenManagerLoop();
    
    /*
    Setups main window with MAIN_WINDOW descriptor
    */
    void SetupMainWindow();

    void SetWinFactory(WindowFactoryInterface* NewPointerToWinFactory);

    void SetWinCntrlColl(vector<WindowContainer*>* NewWinCntrlColl);

    /*
    Add new window. If its first window, get MAIN_WINDOW descriptor
    */
    void AddWindow(WINDOWS_DESCRIPTIONS WindowDesc);
};
#endif