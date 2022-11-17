/*
    Filename: QuickSort2.cpp
    Created by Benjamin Duncan
    Nov 17, 2022
    
    Goal: I've wanted to memorize the quicksort algorithm for a while now.
    Here's my second attempt at memorizing it. I've already done it
    once from a reference but I'm going to today from memory.

    Finished result: I did really well, only messing up one thing. I put the
    wrong index in one of the lines while switching values.
    I put
    > arr[i] = temp;
    rather than
    > arr[j] = temp;
    resulting in no changes. I was successful in debugging it quickly.

    I think that I did a good job!
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

    int temp = arr[high];
    arr[high] = arr[i + 1];
    arr[i + 1] = temp;

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
    int arr[NUM_ELEMENTS] = {1,6,3,8,9,2,1,5,8,4};

    quickSort(arr, 0, NUM_ELEMENTS - 1);

    for(int i = 0; i < NUM_ELEMENTS; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}