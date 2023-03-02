#include "challenge.h"
#include "parsedata.h"
#include "realtime.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Please provide argument to select assignment.\n");
        return -1;
    }
    char selectedAssignment = atoi(argv[1]);

    int N = 0;
    GetSize(&N);
    int arr[N];
    GetArray(arr, N);
    int K = 0;
    GetK(&K);

    // printf("N:%i\n", N);
    // for (int i = 0; i < N; i++) 
    // {
    //     printf("%i", arr[i]);
    // }
    // printf("\n");
    // printf("K:%i\n", K);

    if (selectedAssignment == 1)
    {
        int smallestNumber = 0;
        FindSmallestNumberThatIsRepeatedKTimes(arr, N, K, &smallestNumber);

        printf("%d\n", smallestNumber);
    }
    else if (selectedAssignment == 2)
    {
        printf("BubbleSort\n");
        double startTime = getRealTime();
        int difference = 0;
        ComputeDifferenceBetweenMaxAndMinSumOfKElements_BubbleSort(arr, N, K, &difference);
        double endTime = getRealTime();
        double elapsedTime = endTime - startTime;

        printf("Elepsed time: %f\n", elapsedTime);
        printf("Difference: %d\n", difference);
    }
    else if (selectedAssignment == 31)
    {
        printf("QuickSort\n");
        double startTime = getRealTime();
        int difference = 0;
        ComputeDifferenceBetweenMaxAndMinSumOfKElements_QuickSort(arr, N, K, &difference);
        double endTime = getRealTime();
        double elapsedTime = endTime - startTime;

        printf("Elepsed time: %f\n", elapsedTime);
        printf("Difference: %d\n", difference);
    }
    else if (selectedAssignment == 32)
    {
        printf("SelectionSort\n");
        double startTime = getRealTime();
        int difference = 0;
        ComputeDifferenceBetweenMaxAndMinSumOfKElements_SelectionSort(arr, N, K, &difference);
        double endTime = getRealTime();
        double elapsedTime = endTime - startTime;

        printf("Elepsed time: %f\n", elapsedTime);
        printf("Difference: %d\n", difference);
    }
    else
    {
        printf("Error: Unknown assignment: %d\n", selectedAssignment);
    }

    return 0;
}
