#include "vector"

#include "Sort.h"
#include "IComparable.h"


bool Sort::isSorted(const std::vector<IComparable *> &comparables) {
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
int Sort::Partition(std::vector<IComparable *> & comparables, int low, int high) {
    int pivot = high;
    int j = low;
    for(int i = low; i < high; ++i){
        if (comparables[i]->isLessThan(*comparables[pivot])){
            IComparable * tmp = comparables[i];
            comparables[i] = comparables[j];
            comparables[j] = tmp;
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

void Sort::quickSort(std::vector<IComparable *> & comparables) {
    quickSortHelper(comparables, 0, (int) comparables.size() - 1);
}






