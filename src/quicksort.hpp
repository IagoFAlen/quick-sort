#pragma once
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>

namespace quicksort{

    typedef struct array {
        int* base;

        array* left;
        int pivot;
        array* right;

        int leftSize;
        int pivotIndex;
        int rightSize;

        array(int n ){
            
            base = new int[n];

            left = NULL;        
            pivot = 0;          
            right = NULL;

            leftSize = 0;       
            pivotIndex = 0;     
            rightSize = 0; 
        }
        
        ~array(){
            delete[] left;
            delete[] right;
        }
    } ARRAY;

    void initialize(ARRAY* arr, int n);
    int* feed_array_manually();
    bool is_duplicated(int* baseArr, int n, int randomNumber);
    int* feed_array_generated(int n, int range);
    int* feed_array_input(int n);
    void show(ARRAY* arr, int n);
    ARRAY* feed_left(ARRAY* arr, int n);
    ARRAY* feed_right(ARRAY* arr, int rightStart, int n, int rightSize);
    int* rebase(ARRAY* arr, int leftSize, int pivotIndex, int rightStart, int n);
    ARRAY* sort(ARRAY* arr, int n);

}