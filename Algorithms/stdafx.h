#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//search.c
int BinarySearch(const int *array, int arrayItemsCount, int itemToFind);
int BinarySearchRecursive(const int *array, int arrayItemsCount, int itemToFind);

//sort.c
void SelectionSort(int *array, int arrayItemsCount);
void QuickSort(int *array, int arrayItemsCount);

//recusrion.c
int sum (int* arr, int itemsCount);


//leetCode.c
int* twoSum(int* nums, int numsSize, int target, int returnSize);
bool isPalindrome(int x);

int weight1(unsigned x);
int weight2(unsigned x);
int weight3(unsigned x);

int parity1(unsigned x);
int parity2(unsigned x);
int parity3(unsigned x);