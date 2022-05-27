#include "SorterFactory.h"

SorterFactory::SorterFactory()
{
}

SorterFactory::~SorterFactory()
{
}

Sorter* SorterFactory::CreateSort(SORTIRATIONTYPE SortirationToStart)
{
    Sorter* Result = nullptr;

    switch (SortirationToStart)
    {
    case SELECTION_SORT:
        Result = CreateSelectionSort();
        break;
    
    case BUBBLE_SORT:
        Result = CreateBubbleSort();
        break;

    default:
        break;
    }

    return Result;
}

Sorter* SorterFactory::CreateSelectionSort()
{
    return new Sorter();
}

Sorter* SorterFactory::CreateBubbleSort()
{
    return static_cast<Sorter*>(new BubbleSorter());
}