#include "stdafx.h"
int FindSmallest(int *arr, int arrayItemsCount)
{
    if (!arr)
    {
        return -1;
    }

    int smallestItem = arr[0];
    int smallestItemIndex = 0;
    for (int i = 0; i < arrayItemsCount; i++)
    {
        if (arr[i] < smallestItem)
        {
            smallestItem = arr[i];
            smallestItemIndex = i;
        }
    }
    return smallestItemIndex;
}


//необхоидмо удалить память нового массива после использования
void SelectionSort(int *array, int arrayItemsCount)
{   
    //tempArray нужен для свободного замещения элементов
    int* tempArray = (int*)calloc(arrayItemsCount, sizeof(int));
    for (int i = 0; i < arrayItemsCount; i++)
    {
        tempArray[i] = array[i];
    }
    for (int i = 0; i < arrayItemsCount; i++)
    {
        int smallestItemIndex = FindSmallest(tempArray, arrayItemsCount);
        array[i] = tempArray[smallestItemIndex];
        tempArray[smallestItemIndex] = __INT_MAX__;
    }
    free(tempArray);
    return;
}


void _quickSortInternal(int *array, int left, int right)
{
    if (left > right) return;
    //берем элемент из середины массива
    int pivot = array[(left+right) / 2];
    int i = left, j = right;
    while(i <= j)
    {
        //идем влево, пока не найдем элемент больший, либо равный опорному
        while (array[i] < pivot) i++;
        //идем вправо, пока не найдем элемент меньший, либо равный опорному
        while (array[j] > pivot) j--;
        if (i <= j)
        {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    }
    _quickSortInternal(array, left, j);
    _quickSortInternal(array, i, right);
}

void QuickSort(int *array, int arrayItemsCount)
{
    return _quickSortInternal(array, 0, arrayItemsCount - 1);
}