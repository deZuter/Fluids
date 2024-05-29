#include <stdafx.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int returnSize) 
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


void printBinary(unsigned int x)
{
    for (int i = 31; i >= 0; i--)    //32 - количество бит в int-е
    {
        printf("%d", (x >> i) & 1);
    }
}

int weight1(unsigned x)
{
    printBinary(x);
    int bitsCount = 0;
    while(x != 0)
    {
        //если есть бит четности
        if (x & 1)
        {
            bitsCount++;
        }
        //делим на 2 (то же самое, что и убрать крайний правый бит)
        x = x / 2;
    }
    printf(" %d ", bitsCount);
    return bitsCount;
}
int weight2(unsigned x)
{
    printBinary(x);

    int bitsCount = 0;
    for (int i = 0; i < sizeof(int) * 8; i++)
    {
        //сдвигаем на количество бит, пройдем по всем битам и сделаем 'И' с каждым битом
        bitsCount += (x >> i) & 1;
    }
    printf(" %d ", bitsCount);
    return bitsCount;
}
int weight3(unsigned x)
{
    printBinary(x);
    int bitsCount = 0;
    //пока x не нулевой
    while(x)
    {
        //сдвигаем на 1 бит
        bitsCount += x & 1;
        x >>= 1;
    }
    printf(" %d ", bitsCount);
    return bitsCount;
}
int parity1(unsigned x)
{
    int bitsCount = weight1(x);
    return bitsCount & 1;
}
int parity2(unsigned x)
{
    int bitsCount = weight2(x);
    return bitsCount & 1;
}
int parity3(unsigned x)
{
    int bitsCount = weight3(x);
    return bitsCount & 1;
}