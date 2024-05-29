#include "stdafx.h"

void SortingAndSelectionAlgorithms()
{
    int arr[] = {21, 3, 4, 6, 2, 1, 23, 23, 1};
    int arrItemsCount = sizeof(arr)/sizeof(int);
    printf("Массив до сортировки выбором: ");
    for (int i = 0; i < arrItemsCount; i++)
    {
        printf("%d ", arr[i]);
    }
    SelectionSort(arr, arrItemsCount);
    printf("\nМассив после сортировки выбором: ");
    for (int i = 0; i < arrItemsCount; i++)
    {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < arrItemsCount; i++)
    {
        arr[i] = rand()%50;
    }
    printf("\nМассив до QuickSort: ");
    for (int i = 0; i < arrItemsCount; i++)
    {
        printf("%d ", arr[i]);
    }
    QuickSort(arr, arrItemsCount);
    printf("\nМассив после QuickSort: ");
    for (int i = 0; i < arrItemsCount; i++)
    {
        printf("%d ", arr[i]);
    }
    int itemToFind = arr[5];

    printf("\n\nМассив для поиска: ");
    for (int i = 0; i < arrItemsCount; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nЭлемент для поиска: %d", itemToFind);
    printf("\nПоиск циклическим алгоритмом: %d", itemToFind);
    int result = BinarySearch(arr, arrItemsCount, itemToFind);
    if (result == -1)
    {
        printf("\nЭлемент не найден");
        return;
    }
    printf("\nМесто: %d", result + 1);

    printf("\nПоиск рекурсивным алгоритмом: %d", itemToFind);
    result = BinarySearchRecursive(arr, arrItemsCount, itemToFind);
    if (result == -1)
    {
        printf("\nЭлемент не найден");
        return;
    }
    printf("\nМесто: %d", result + 1);
    

    int arrSum = sum(arr, arrItemsCount);
    printf("\nСумма элементов массива: %d\n", arrSum);
    return;
}

void LeetCodeAlogorithms()
{
    printf("\n\nТестирование LeetCode алгоритмов");
    printf("\nНа вход массив и число, на выход 2 индекса элемента массива, соответствующие сумме массива");
    printf("\nМассив: ");
    int arr[] = {2, 7, 11, 15};
    int arrItemsCount = 4;
    int num = 9;
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nЧисло: %d", num);
    int* temp = twoSum(arr, arrItemsCount, num, sizeof(int)*2);
    printf("\nРезультат: ");
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", temp[i]);
    }
    free(temp);

    num = 101;
    printf("\n\nНа вход число, проверить, является ли число полиндромом");
    printf("\nЧисло: %d", num);
    bool result = isPalindrome(num);
    printf("\nРезультат: %d", result);
}


void JobAlgorithms()
{
    weight1(3);
    printf("\n");
    weight2(21);
    printf("\n");
    weight3(7);
    printf("\n");
    printf("\n");
    printf("%d ", parity1(4));    
    printf("\n");
    printf("%d ", parity2(12));    
    printf("\n");
    printf("%d ", parity3(652));    
    printf("\n");
}



int main(int argc, char**argv)
{
    //SortingAndSelectionAlgorithms();
    //LeetCodeAlogorithms();
    JobAlgorithms();
}