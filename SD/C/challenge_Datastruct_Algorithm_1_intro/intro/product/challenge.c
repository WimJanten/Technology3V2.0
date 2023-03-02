#include "challenge.h"
#include <stddef.h>

int FindSmallestNumberThatIsRepeatedKTimes(
            int* array, int size, int k, int* smallestNumber)
{
    int i;
    int j;
    int count = 0;
    int smallest = INT_MAX;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (array[i] == array[j])
            {
                count++;
            }
        }
        if (count == k && array[i] < smallest)
        {
            smallest = array[i];
        }
        count = 0;
    }
    if (smallest != INT_MAX)
    {
        *smallestNumber = smallest;
        return 0;
    }
    return -1;
}

int ComputeDifference(
            int* array, int size, int k, int* difference)
{
    if(array == NULL || size < 0 || k < 0 || difference == NULL){
        return -1;
    }
    int i;
    int sum1 = 0;
    int sum2 = 0;
    for (i = 0; i < k; i++)
    {
        sum1 += array[i];
    }
    for (i = 0; i < k; i++)
    {
        sum2 += array[size - i - 1];
    }
    *difference = sum2 - sum1;
    return 0;
}

int Swap(int *a, int *b) {
    if(a == NULL || b == NULL){
        return -1;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int BubbleSort(int* array, int size){
    if(array == NULL || size < 0){
        return -1;
    }

    int i;
    int j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                Swap(&array[j], &array[j + 1]);
            }
        }
    }
    return 0;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_BubbleSort(
            int* array, int size, int k, int* difference)
{
    int result = BubbleSort(array, size);
    if(result == -1){
        return -1;
    }
    result = ComputeDifference(array, size, k, difference);
    if(result == -1){
        return -1;
    }
    return 0;
}

//write a function that sorts the array using quicksort
int Quicksort(int* array, int left, int right)
{
    if(array == NULL || left < 0 || right < 0){
        return -1;
    }
    int i = left;
    int j = right;
    int pivot = array[(left + right) / 2];
    while (i <= j)
    {
        while (array[i] < pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            Swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }
    if (left < j)
    {
        Quicksort(array, left, j);
    }
    if (i < right)
    {
        Quicksort(array, i, right);
    }
    return 0;
}



int ComputeDifferenceBetweenMaxAndMinSumOfKElements_QuickSort(
            int* array, int size, int k, int* difference)
{
    int result = Quicksort(array, 0, size - 1);
    if(result == -1){
        return -1;
    }
    result = ComputeDifference(array, size, k, difference);
    if(result == -1){
        return -1;
    }
    return 0;
}

int SelectionSort(int* array, int size)
{
    if(array == NULL || size < 0){
        return -1;
    }
    int i;
    int j;
    int min;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        Swap(&array[min], &array[i]);
    }
    return 0;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_SelectionSort(
            int* array, int size, int k, int* difference)
{
    int result = SelectionSort(array, size);
    if(result == -1){
        return -1;
    }
    result = ComputeDifference(array, size, k, difference);
    if(result == -1){
        return -1;
    }
    return 0;
}

int ComputeDifferenceBetweenMaxAndMinSumOfKElements_3(
            int* array, int size, int k, int* difference)
{
    return -1;
}
