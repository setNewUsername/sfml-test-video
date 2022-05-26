#pragma once
#ifndef WINDOWFACTORYINTERFACE_H
#define WINDOWFACTORYINTERFACE_H

#include <vector>
#include "../Window/WindowContainer.h"
#include "../Window/WindowContainerEnum.h"

using namespace std;

class WindowFactoryInterface
{
private:

public:
    WindowFactoryInterface() {};
    virtual ~WindowFactoryInterface() {};  

    /**
     * @brief Create a Window Container object
     * 
     * @param NewWindowDesc 
     */
    virtual void CreateWindowContainer(WINDOWS_DESCRIPTIONS NewWindowDesc) = 0;

    /**
     * @brief Get the Window Collection object
     * 
     * @return vector<WindowContainer*>* 
     */
    virtual vector<WindowContainer*>* GetWindowCollection() = 0;
};

#endif