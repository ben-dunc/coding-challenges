/*
    QuickSort5.cpp
    Created by Benjamin Duncan
    Nov 28, 2022

    Purpose: This is the 5th and final iteration of the quicksort algorithm in
    an attempt to memorize it.

    Result: Success! Did it without any issues
*/

#include <iostream>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, high, low);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int NUM_ELEMENTS = 10;
    int arr1[NUM_ELEMENTS] = {0, 2, 5, 1, 8, 4, 7, 2, 3, 3};

    quickSort(arr1, 0, NUM_ELEMENTS - 1);

    for (int i = 0; i < NUM_ELEMENTS; i++)
        cout << arr1[i] << ' ';
    cout << endl;

    return 0;
}