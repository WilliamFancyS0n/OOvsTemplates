
#ifndef OOVSTEMPLATES_SORT_H
#define OOVSTEMPLATES_SORT_H

#include "vector"

class Sort {
public:
    template<typename Comparable, typename Comparator>
    static void quickSort(std::vector<Comparable *> & comparables, Comparator & comparator);

    template<typename Comparable, typename Comparator>
    bool isSorted(const std::vector<Comparable *> & comparables, Comparator & comparator);

private:

    template<typename Comparable, typename Comparator>
    static void quickSortHelper(std::vector<Comparable *> & comparables, int low, int high, Comparator & comparator);

    template<typename Comparable, typename Comparator>
    static int Partition(std::vector<Comparable *> & comparables, int low, int high, Comparator & comparator);
};


#endif //OOVSTEMPLATES_SORT_H
