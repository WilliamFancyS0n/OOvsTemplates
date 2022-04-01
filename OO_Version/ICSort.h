//
// Created by Will on 3/30/2022.
//

#ifndef OOVSTEMPLATES_ICSORT_H
#define OOVSTEMPLATES_ICSORT_H

#include "IComparable.h"
#include "vector"


class ICSort {
public:
    static bool isSorted(const std::vector<IComparable *> & comparables);
    static void quickSort(std::vector<IComparable *> & comparables);
private:
    static void quickSortHelper(std::vector<IComparable *> & comparables, int low, int high);
    static int Partition(std::vector<IComparable *> & comparables, int low, int high);
};


#endif //OOVSTEMPLATES_ICSORT_H
