#include "stdafx.h"

int sum (int* arr, int itemsCount)
{
    //static int recursionStep = 0;
    //printf("\nВложение рекурсии: %d\n", recursionStep);
    if (itemsCount == 2)
        return arr[0]+arr[1];
    else
    {
        //recursionStep++;
        return arr[0] + sum(&arr[1], itemsCount - 1);
    }

}