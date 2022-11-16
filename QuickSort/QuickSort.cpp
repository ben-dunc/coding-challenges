/*
    Filename: QuickSort.cpp
    Created by Benjamin Duncan
    Nov 16, 2022

    I've been wanting to memorize the quicksort algorithm for a while now because I've encountered sorting algorithms in previous job interviews before.
    Here's an effort to learn it well.
*/

#include <iostream>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
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

int main (int argc, char* argv[]) {
    
    const int NUM_ELEMENTS = 50;
    int arrayToSort[NUM_ELEMENTS] = {1,2,5,10,50,3,6,7,55,6,37,247,2,6,43,236,7,543,43,4,3,234,23,54,467,8,6,45,56,54,34,25,74,97,97,47,25,34,54,34,7,57,45,24,23,23,12,234,75,35};

    quickSort(arrayToSort, 0, NUM_ELEMENTS - 1);

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        cout << arrayToSort[i] << " ";
    }

    cout << endl;

    return 0;
}