//
// Created by Will on 3/30/2022.
//

#ifndef OOVSTEMPLATES_SORT_H
#define OOVSTEMPLATES_SORT_H

#include "IComparable.h"
#include "vector"


class Sort {
public:
    void swap(auto * a, auto * b);
    void quicksort(std::vector<IComparable *> & comparables);
    void quickSortHelper(std::vector<IComparable *> & comparables, int low, int high);
    int Partition(std::vector<IComparable *> & comparables, int low, int high);

private:



};


#endif //OOVSTEMPLATES_SORT_H
