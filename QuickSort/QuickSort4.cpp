/*
    Filename: Quicksort4.cpp
    Created by Benjamin Duncan
    Nov 22, 2022

    Purpose: This is my 4th iteration of the quick sort algorithm in an
    attempt to memorize it.

    Result: I did well. I messed up in two places: line 30 & 31 and line 49. I didn't have "i + 1"
    but just "i", throwing the sorting off and throwing an abort error 6. In addition, I didn't have
    "NUM_ELEMENTS - 1", just having "NUM_ELEMENTS" which threw an abort error 6.
*/

#include <iostream>

using namespace std;

int partition(int arr [], int low, int high) {
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

    int temp = arr[high];
    arr[high] = arr[i + 1];
    arr[i + 1] = temp;

    return i + 1;
}

void quickSort(int arr [], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    const int NUM_ELEMENTS = 10;
    int arr [NUM_ELEMENTS] = {9,8,7,6,5,4,3,2,1,0};

    quickSort(arr, 0, NUM_ELEMENTS - 1);

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}