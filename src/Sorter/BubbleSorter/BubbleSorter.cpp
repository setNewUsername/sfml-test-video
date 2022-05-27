#include "BubbleSorter.h"

BubbleSorter::BubbleSorter()
{
    SetSortirationName("Bubble sort");
}

BubbleSorter::~BubbleSorter()
{
}

void BubbleSorter::SortArray()
{
    PrintSortirationName();
    for(int j = 0; j < GetArrayContPointer()->GetArraySize(); j++)
    {
        for(int i = 0; i < GetArrayContPointer()->GetArraySize()-1; i++)
        {
            if((*GetArrayContPointer())[i] > (*GetArrayContPointer())[i+1])
            {
                GetArrayContPointer()->SwapElements(i, i+1);
            }
        }
    }
}