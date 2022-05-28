#pragma once
#ifndef WINDOWFACTORY_H
#define WINDOWFACTORY_H

#include "../Window/WindowContainer.h"
#include "../Window/WindowContainerEnum.h"
#include "WindowFactoryInterface.h"
#include "../../MsgDistributor/MessageDistributor.h"
#include "../../MsgDistributor/Message/MessageFactory/MessageFactory.h"

class WindowFactory : public WindowFactoryInterface
{
private:
    MessageDistributor* MsgDistr;
    MessageFactory* MsgFac;

    WindowContainer* CreateMainWindow();
    WindowContainer* CreateWindowOne();

    vector<WindowContainer*>* WinContColl;

public:
    WindowFactory(MessageDistributor* NewMsgDistr, MessageFactory* NewMsgFac);
    ~WindowFactory();

    /*
    
    */
    vector<WindowContainer*>* GetWindowCollection() override;

    /*
    
    */
    void CreateWindowContainer(WINDOWS_DESCRIPTIONS NewWindowDesc) override;
};

#endif