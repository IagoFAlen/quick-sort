#ifndef ARRAY_FUNCTIONS_INCLUDED
#define ARRAY_FUNCTIONS_INCLUDED
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>

using namespace std;

typedef struct array {
    int* base;

    array* left;
    int pivot;
    array* right;

    int leftSize;
    int pivotIndex;
    int rightSize;
    
    ~array(){
        delete[] left;
        delete[] right;
    }
} ARRAY;

void initialize(ARRAY* arr, int n) {
    // Ensure `arr` is not NULL
    if (arr == NULL) {
        return;
    }

    arr->base = new int[n];

    arr->left = NULL;        
    arr->pivot = 0;          
    arr->right = NULL;

    arr->leftSize = 0;       
    arr->pivotIndex = 0;     
    arr->rightSize = 0;      
}

int* feed_array(int n){
    int* arr = new int[n];

    // Populate the array manually
    int values[] = {9, 4, 3, 8, 2, 7, 0, 6, 1, 5};
    for (int i = 0; i < n && i < sizeof(values) / sizeof(values[0]); i++) {
        arr[i] = values[i];
    }

    return arr;
}

void show(ARRAY* arr, int n){
    for(int i = 0; i < n; i++){
        cout << "A[" << i << "]: " << arr->base[i] << endl;
    }

    cout << endl;
}

ARRAY* feed_left(ARRAY* arr, int n){
    ARRAY* leftArr = new ARRAY;

    initialize(leftArr, n);
    for(int i = 0; i < n; i++){
        leftArr->base[i] = arr->base[i];
    }

    return leftArr;
}

// rightStart is pivotIndex
ARRAY* feed_right(ARRAY* arr, int rightStart, int n, int rightSize){
    ARRAY* rightArr = new ARRAY;
    initialize(rightArr, rightSize);

    for(int i = rightStart; i < n - 1; i++){
        rightArr->base[i - rightStart] = arr->base[i];
    }

    return rightArr;
}

int* rebase(ARRAY* arr, int leftSize, int pivotIndex, int rightStart, int n){
    for(int i = 0; i <= leftSize; i++){
        arr->base[i] = arr->left->base[i];
    }

    arr->base[pivotIndex] = arr->pivot;

    for(int i = rightStart; i < n; i++){
        arr->base[i] = arr->right->base[i - rightStart];
    }
    
    return arr->base;
}

ARRAY* sort(ARRAY* arr, int n){
    arr->pivot = arr->base[n - 1];

    int i = -1;

    for(int j = 0; j < n; j++){
        if(arr->base[j] < arr->pivot){
            i++;
            swap(arr->base[j], arr->base[i]);
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