//
// Created by Will on 3/30/2022.
//

#include "vector"
#include "Sort.h"
#include "IComparable.h"



//void Sort::swap(auto * a, auto * b) {
//    auto tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//void Sort::swap(IComparable& a, IComparable& b) {
//    IComparable &tmp = a;
//    *a = *b;
//    *b = *tmp;
//}

int Sort::Partition(std::vector<IComparable *> & comparables, int low, int high) {
    int pivot = high;
    int j = low;
    for(int i=low; i < high; ++i){
        if (comparables[i]->isLessThan(*comparables[pivot])){
            IComparable * tmp = comparables[i];
            comparables[i] = comparables[j];
            comparables[j] = tmp;

           // std::swap(comparables[i], comparables[j]); uses templates
            ++j;
        }
    }
    std::swap(comparables[j],comparables[pivot]);
    return j;
}

void Sort::quickSortHelper(std::vector<IComparable *> & comparables, int low, int high) {
    if (low < high) {
        int tmp = Partition(comparables, low, high);
        quickSortHelper(comparables, low, tmp - 1);
        quickSortHelper(comparables, tmp + 1, high);
    }
}

void Sort::quicksort(std::vector<IComparable *> & comparables) {
    quickSortHelper(comparables, 0, (int) comparables.size() - 1);
}




