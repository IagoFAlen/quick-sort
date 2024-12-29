#include "functions.hpp"

using namespace std;

int main(){
    ARRAY* arr;
    int numSize = 10;
    initialize(arr, numSize);
    arr->base = feed_array(numSize);
    show(arr, numSize);
    arr = sort(arr, numSize);
    show(arr, numSize);
    return 0;
}