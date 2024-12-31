#include "quicksort.cpp"

using namespace std;
using namespace quicksort;

int main(){
    int numSize = 10;
    ARRAY* arr = new ARRAY(numSize);

    arr->base = quicksort::feed_array(numSize);
    quicksort::show(arr, numSize);
    arr = quicksort::sort(arr, numSize);
    quicksort::show(arr, numSize);
    return 0;
}