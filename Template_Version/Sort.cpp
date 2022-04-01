#include "vector"
#include "Sort.h"



template<typename Comparable>
class IsLessThanTemplate {
public:
    bool operator() (const Comparable & lhs, const Comparable & rhs) const
    {
        return lhs < rhs;
    }
};


template<typename Comparable>
bool Sort::isSorted(const std::vector<Comparable *> & comparables) {
    const int n = (int) comparables.size();
    if (n == 0 || n == 1)
        return true;

    for (int i = 1; i < n; i++)
        // if the nth term is less than the n-1th term
        if (comparables[i]->isLessThan(*comparables[i - 1]))
            return false;

    // every nth term is smaller than the n+1th term
    return true;
}

template<typename Comparable>
void Sort::quickSort(std::vector<Comparable *> & comparables) {
    quickSortHelper(comparables, 0, (int) comparables.size() - 1);
}


template<typename Comparable>
 void Sort::quickSortHelper(std::vector<Comparable *> & comparables, int low, int high) {
    if (low < high) {
        int tmp = Partition(comparables, low, high);
        quickSortHelper(comparables, low, tmp - 1);
        quickSortHelper(comparables, tmp + 1, high);
    }
}

template<typename Comparable>
 int Sort::Partition(std::vector<Comparable *> & comparables, int low, int high) {
    int pivot = high;
    int j = low;
    for(int i = low; i < high; ++i){
        if (comparables[i]->isLessThan(*comparables[pivot])){
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