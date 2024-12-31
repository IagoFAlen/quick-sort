#ifndef QUICKSORT_FUNCTIONS_INCLUDED
#define QUICKSORT_FUNCTIONS_INCLUDED
#include "quicksort.hpp"

using namespace quicksort;

int* quicksort::feed_array(int n){
    int* arr = new int[n];

    // Populate the array manually
    int values[] = {9, 4, 3, 8, 2, 7, 0, 6, 1, 5};
    for (int i = 0; i < n && i < sizeof(values) / sizeof(values[0]); i++) {
        arr[i] = values[i];
    }

    return arr;
}

void quicksort::show(ARRAY* arr, int n){
    for(int i = 0; i < n; i++){
        std::cout << "A[" << i << "]: " << arr->base[i] << std::endl;
    }

    std::cout << std::endl;
}

ARRAY* quicksort::feed_left(ARRAY* arr, int n){
    ARRAY* leftArr = new ARRAY(n);

    for(int i = 0; i < n; i++){
        leftArr->base[i] = arr->base[i];
    }

    return leftArr;
}

// rightStart is pivotIndex
ARRAY* quicksort::feed_right(ARRAY* arr, int rightStart, int n, int rightSize){
    ARRAY* rightArr = new ARRAY(rightSize);

    for(int i = rightStart; i < n - 1; i++){
        rightArr->base[i - rightStart] = arr->base[i];
    }

    return rightArr;
}

int* quicksort::rebase(ARRAY* arr, int leftSize, int pivotIndex, int rightStart, int n){
    for(int i = 0; i <= leftSize; i++){
        arr->base[i] = arr->left->base[i];
    }

    arr->base[pivotIndex] = arr->pivot;

    for(int i = rightStart; i < n; i++){
        arr->base[i] = arr->right->base[i - rightStart];
    }
    
    return arr->base;
}

ARRAY* quicksort::sort(ARRAY* arr, int n){
    arr->pivot = arr->base[n - 1];

    int i = -1;

    for(int j = 0; j < n; j++){
        if(arr->base[j] < arr->pivot){
            i++;
            std::swap(arr->base[j], arr->base[i]);
        }
    }

    arr->leftSize = i + 1;
    arr->pivotIndex = i + 1;
    arr->rightSize = (n - arr->pivotIndex) - 1;

    arr->left = feed_left(arr, arr->leftSize);
    arr->right = feed_right(arr, arr->pivotIndex, n, arr->rightSize);

    if(arr->leftSize > 1)
        arr->left = sort(arr->left, arr->leftSize);
    if(arr->rightSize > 1)
        arr->right = sort(arr->right, arr->rightSize);

    arr->base = rebase(arr, arr->leftSize, arr->pivotIndex, (n - arr->rightSize), n);

    return arr;
}

#endif