#include "Sorter.h"

Sorter::Sorter() : 
ArrayContPointer(nullptr),
SortirationName("Selection sort")
{
}

Sorter::~Sorter()
{
}

void Sorter::SetArrayContPointer(ArrayContainer* NewArrayContPointer)
{
    ArrayContPointer = NewArrayContPointer;
}

void Sorter::SortArray()
{   
    PrintSortirationName();

    for(int i = 0; i < ArrayContPointer->GetArraySize(); i++)
    {
        for(int j = i; j < ArrayContPointer->GetArraySize(); j++)
        {
            if((*ArrayContPointer)[i] > (*ArrayContPointer)[j])
            {
                ArrayContPointer->SwapElements(i, j);
            }
        }
    }
}

void Sorter::SetSortirationName(string NewSortirationName)
{
    SortirationName = NewSortirationName;
}

void Sorter::PrintSortirationName()
{
    cout << SortirationName << " started " << endl;
}

ArrayContainer* Sorter::GetArrayContPointer()
{
    return ArrayContPointer;
}