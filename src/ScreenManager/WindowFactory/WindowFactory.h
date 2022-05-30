#pragma once
#ifndef WINDOWFACTORY_H
#define WINDOWFACTORY_H

#include "../Window/WindowContainer.h"
#include "../Window/WindowContainerEnum.h"
#include "WindowFactoryInterface.h"

class WindowFactory : public WindowFactoryInterface
{
private:
    WindowContainer* CreateMainWindow();
    WindowContainer* CreateWindowOne();

    vector<WindowContainer*>* WinContColl;

public:
    WindowFactory();
    ~WindowFactory();

    /*
    
    */
    vector<WindowContainer*>* GetWindowCollection() override;

    /*
    
    */
    void CreateWindowContainer(WINDOWS_DESCRIPTIONS NewWindowDesc) override;
};

#endif