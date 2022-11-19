/*
    Filename: QuickSort3.cpp
    Created by Benjamin Duncan
    Nov 19, 2022

    This is an effort to memorize the quicksort algorithm.
    This is my third iteration.

    Result: Success! I got it on the first try. I'll try again in two days and once more a week later to solidify it.
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
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    const int NUM_ELEMENTS = 10;
    int arr1[NUM_ELEMENTS] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr2[NUM_ELEMENTS] = {2, 3, 5, 6, 1, 4, 8, 2, 1};
    int arr3[NUM_ELEMENTS] = {9, 38, 67, 76, 0, 4, 5, 2, 3};

    quickSort(arr1, 0, NUM_ELEMENTS - 1);
    quickSort(arr2, 0, NUM_ELEMENTS - 1);
    quickSort(arr3, 0, NUM_ELEMENTS - 1);

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}