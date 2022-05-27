#pragma once
#ifndef SORTERFACTORY_H
#define SORTERFACTORY_H

#include "../SortirationTypesEnum.h"
#include "../Sorter.h"
#include "../BubbleSorter/BubbleSorter.h"

class SorterFactory
{
private:
    Sorter* CreateSelectionSort();
    Sorter* CreateBubbleSort();

public:
    SorterFactory();
    ~SorterFactory();

    Sorter* CreateSort(SORTIRATIONTYPE SortirationToStart);
};

#endif