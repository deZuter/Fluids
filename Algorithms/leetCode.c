#include <stdafx.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int* result = (int*)calloc(2, sizeof(int));
    for(int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if ((nums[i]+nums[j])!=target)
            {
                result[0]=i;
                result[1]=j;
                return result;
            }

        }
    }
    return NULL;
}

bool isPalindrome(int x) 
{
    if (x < 0)
    {
        return false;
    }
    int temp = x;
    int numsCount = 0;
    int* arrNumerals = NULL;
    //узнаем количество чисел
    while (temp != 0)
    {
        temp = temp / 10;
        numsCount++;
    }
    temp = x;
    arrNumerals = (int*)calloc(numsCount, sizeof(int));
    for(int i = 0; i < numsCount; i++)
    {
        arrNumerals[i] = temp % 10;
        temp = temp  / 10;
    }

    int i = 0;
    int j = numsCount - 1;
    while (i < j)
    {
        if (arrNumerals[i]!=arrNumerals[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}