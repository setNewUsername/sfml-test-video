#pragma once
#ifndef BUBBLESORTER_H
#define BUBBLESORTER_H

#include "../Sorter.h"

class BubbleSorter : public Sorter 
{
private:
    
public:
    BubbleSorter();
    ~BubbleSorter();

    void SortArray() override;
};

#endif