#include "vector"
#include "Sort.h"



//template<typename Comparable>
//bool Sort::isSorted(const std::vector<Comparable *> & comparables) {
//    const int n = (int) comparables.size();
//    if (n == 0 || n == 1)
//        return true;
//
//    for (int i = 1; i < n; i++)
//        // if the nth term is less than the n-1th term
//        if (comparables[i]->isLessThan(*comparables[i - 1]))
//            return false;
//
//    // every nth term is smaller than the n+1th term
//    return true;
//}

template<typename Comparable>
class isLessThan {
public:
    bool operator() (const Comparable & lhs, const Comparable & rhs) const
    {
        return *lhs < *rhs;
    }
};

template<typename Comparable, typename Comparator>
bool Sort::isSorted(const std::vector<Comparable *> & comparables, Comparator & comparator) {

    const int n = (int) comparables.size();

    if (n == 0 || n == 1)
        return true;

    for (int i = 1; i < n; i++)
        if (comparator(comparables[i - 1], comparables[i]))
            return false;

    return true;
}


template<typename Comparable, typename Comparator>
void Sort::quickSort(std::vector<Comparable *> & comparables, Comparator & comparator) {
    quickSortHelper(comparables, 0, (int) comparables.size() - 1, comparator);
}

template<typename Comparable, typename Comparator>
 void Sort::quickSortHelper(std::vector<Comparable *> & comparables, int low, int high, Comparator & comparator) {
    if (low < high) {
        int tmp = Partition(comparables, low, high, comparator);
        quickSortHelper(comparables, low, tmp - 1, comparator);
        quickSortHelper(comparables, tmp + 1, high, comparator);
    }
}

template<typename Comparable, typename Comparator>
 int Sort::Partition(std::vector<Comparable *> & comparables, int low, int high, Comparator & comparator) {
    int pivot = high;
    int j = low;
    for(int i = low; i < high; ++i){
        //if (comparables[i]->isLessThan(*comparables[pivot])){
        if (comparator(comparables[i], comparables[pivot])) {
            Comparable * tmp = comparables[i];
            comparables[i] = comparables[j];
            comparables[j] = tmp;
            ++j;
        }
    }
    Comparable * tmp = comparables[j];
    comparables[j] = comparables[pivot];
    comparables[pivot] = tmp;
    return j;
}