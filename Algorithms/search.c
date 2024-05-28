#include "stdafx.h"

int BinarySearch(const int *array, int arrayItemsCount, int itemToFind) 
{
    int low =  0;
    int high = arrayItemsCount - 1;
    
    int mid = -1;
    while(low <= high)
    {
        mid =  (low + high) / 2;
        if (array[mid] == itemToFind)
        {
            return mid;
        }
        else if(array[mid] < itemToFind)
        {
            low = mid + 1;  
        }
        else 
        {
            high = mid - 1;
        }
    }
    return -1;    
}

int _binarySearchRecursiveInternal(const int *array, int low, int high, int itemToFind)
{
    int mid = (low+high) / 2;

    if (low > high)
    {
        return -1;
    }

    if (array[mid] == itemToFind)
    {
       return mid;
    }
    else if(array[mid] < itemToFind)
    {
        return _binarySearchRecursiveInternal(array, low = mid + 1, high, itemToFind);  
    }
    else 
    {
         return _binarySearchRecursiveInternal(array, low,  high = mid - 1, itemToFind);
    }
} 

int BinarySearchRecursive(const int *array, int arrayItemsCount, int itemToFind) 
{
    return _binarySearchRecursiveInternal(array, 0, arrayItemsCount - 1, itemToFind);
}