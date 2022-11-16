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
    int arr1[NUM_ELEMENTS] = {1,2,5,10,50,3,6,7,55,6,37,247,2,6,43,236,7,543,43,4,3,234,23,54,467,8,6,45,56,54,34,25,74,97,97,47,25,34,54,34,7,57,45,24,23,23,12,234,75,35};
    int arr2[NUM_ELEMENTS] = {85,0,29,3,3,89,55,56,91,30,49,37,94,47,98,100,36,33,27,68,16,29,93,42,57,39,45,20,75,18,3,41,62,74,29,23,49,75,70,96,85,100,30,61,75,73,23,24,53,33};
    int arr3[NUM_ELEMENTS] = {48,36,7,44,2,73,26,73,10,64,44,17,62,77,85,73,3,74,97,24,84,74,58,22,6,85,26,49,16,35,77,86,26,56,69,60,100,8,43,54,16,24,98,26,1,85,25,2,78,9};
    int arr4[NUM_ELEMENTS] = {22,63,73,97,8,13,43,17,66,15,28,54,93,79,84,96,30,73,86,21,58,75,53,44,85,21,71,56,41,9,88,81,69,97,65,40,77,51,8,82,10,93,93,9,29,35,75,68,100,78};

    quickSort(arr1, 0, NUM_ELEMENTS - 1);
    quickSort(arr2, 0, NUM_ELEMENTS - 1);
    quickSort(arr1, 0, NUM_ELEMENTS - 1);
    quickSort(arr4, 0, NUM_ELEMENTS - 1);

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
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        cout << arr4[i] << " ";
    }
    cout << endl;

    return 0;
}