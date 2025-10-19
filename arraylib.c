#include "arraylib.h"
#include <stdio.h>

/* display array elements */
void displayArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int findMaxIndex(int arr[], int size) {
    if (size <= 0) return -1;
    int maxIdx = 0;
    for (int i = 1; i < size; ++i)
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    return maxIdx;
}

int findMinIndex(int arr[], int size) {
    if (size <= 0) return -1;
    int minIdx = 0;
    for (int i = 1; i < size; ++i)
        if (arr[i] < arr[minIdx]) minIdx = i;
    return minIdx;
}

float findAverage(int arr[], int size) {
    if (size <= 0) return 0.0f;
    long sum = 0;
    for (int i = 0; i < size; ++i) sum += arr[i];
    return (float)sum / (float)size;
}

void reverseArray(int arr[], int size) {
    int i = 0, j = size - 1;
    while (i < j) {
        int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
        i++; j--;
    }
}

/* simple ascending bubble sort */
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int swapped = 0;
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j+1]) {
                int t = arr[j]; arr[j] = arr[j+1]; arr[j+1] = t;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int linearSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; ++i)
        if (arr[i] == value) return i;
    return -1;
}
