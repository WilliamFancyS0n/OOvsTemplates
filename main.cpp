#include <iostream>



#include "Intwrapper.cpp"
#include "Stringwrapper.cpp"
#include "IComparable.h"
#include "vector"
#include "Sort.cpp"
using namespace std;



void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(vector<IComparable *> & comparables, int low, int high){
    int pivot = high;
    int j = low;
    for(int i=low; i < high; ++i){
        if (comparables[i]->isLessThan(*comparables[pivot])){
            swap(comparables[i],comparables[j]);
            ++j;
        }
    }
    swap(comparables[j],comparables[pivot]);
    return j;
}

void quickSortHelper(vector<IComparable *> & comparables, int low, int high) {
    if (low < high) {
        int tmp = Partition(comparables, low, high);
        quickSortHelper(comparables, low, tmp - 1);
        quickSortHelper(comparables, tmp + 1, high);
    }
}

void quickSort(vector<IComparable *> & comparables) {
    quickSortHelper(comparables, 0, (int) comparables.size() - 1);
}




int main() {
    vector<IComparable * > things;
    things.reserve(50);


    things.push_back(new Intwrapper(5));
    things.push_back(new Intwrapper(11));
    things.push_back(new Intwrapper(1));
    things.push_back(new Intwrapper(22));
    things.push_back(new Intwrapper(999));
    things.push_back(new Intwrapper(40));
    things.push_back(new Intwrapper(23));



    for (int i = 0; i < things.size(); i++)
        things[i]->printValue();










        return 0;
}
