//
// Created by Will on 3/30/2022.
//
#include <iostream>
#include "vector"
#include "Sort.h"
#include "IComparable.h"
#include "Intwrapper.cpp"
#include "Stringwrapper.cpp"

void Sort::swap(auto * a, auto * b) {
    auto tmp = *a;
    *a = *b;
    *b = tmp;
}

int Sort::Partition(std::vector<IComparable *> & comparables, int low, int high) {
    int pivot = high;
    int j = low;
    for(int i=low; i < high; ++i){
        if (comparables[i]->isLessThan(*comparables[pivot])){
            swap(comparables[i], comparables[j]);
            ++j;
        }
    }
    swap(comparables[j],comparables[pivot]);
    return j;
}

void Sort::quickSortHelper(std::vector<IComparable *> & comparables, int low, int high) {

}



void Sort::quicksort(std::vector<IComparable *> & comparables) {
    quickSortHelper(comparables, 0, (int) comparables.size() - 1);
}


