
#ifndef OOVSTEMPLATES_SORT_H
#define OOVSTEMPLATES_SORT_H

#include "vector"

class Sort {
public:
    template<typename Comparable>
    static void quickSort(std::vector<Comparable *> & comparables);

    template<typename Comparable>
    static bool isSorted(const std::vector<Comparable *> & comparables);

private:

    template<typename Comparable>
    static void quickSortHelper(std::vector<Comparable *> & comparables, int low, int high);

    template<typename Comparable>
    static int Partition(std::vector<Comparable *> & comparables, int low, int high);


};


#endif //OOVSTEMPLATES_SORT_H
