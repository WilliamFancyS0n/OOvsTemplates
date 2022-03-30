//
// Created by Will on 3/30/2022.
//

#ifndef OOVSTEMPLATES_SORT_H
#define OOVSTEMPLATES_SORT_H

#include "IComparable.h"
#include "vector"


class Sort {
public:
    //static void swap(IComparable& a, IComparable& b);
    static bool isSorted(const std::vector<IComparable *> & comparables);
    static void quickSort(std::vector<IComparable *> & comparables);
private:
    static void quickSortHelper(std::vector<IComparable *> & comparables, int low, int high);
    static int Partition(std::vector<IComparable *> & comparables, int low, int high);
};


#endif //OOVSTEMPLATES_SORT_H
