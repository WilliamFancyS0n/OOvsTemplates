#include <iostream>
#include <random>
#include "vector"
#include <chrono>

// OO_Version include
#include "OO_Version/IComparable.h"
#include "OO_Version/ICSort.cpp"
#include "OO_Version/ICIntWrapper.cpp"
#include "OO_Version/ICStringWrapper.cpp"

// Template_Version include
#include "Template_Version/Sort.cpp"
#include "Template_Version/IntWrapper.cpp"
#include "Template_Version/StringWrapper.cpp"

using namespace std;
using namespace std::chrono;

/*
 *   Name: William Alger
 *   Class: CSC 402
 *   Purpose of Program: This program defines two ways of sorting our wrapper classes IntWrapper and StringWrapper
 *
 *   Sorting method: QuickSort
 *
 *   Method 1: Inherit from IComparable
 *   Method 2: Templatize the Sorting method
 *
 *   Output shows the timing differences between the two methods of sorting.
 *
 * */


// random string generator of length len
string gen_random(const int len) {
    static const char alphanum[] =
            "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return tmp_s;
}

int main() {
    // create a random number generator
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> randomIntRange(1, 1000); // range 1 - 1000
    uniform_int_distribution<int> randomStringLength(1, 4); // range 1 - 4

    // declare the function objects we will use for our template sorting
    const isLessThan<StringWrapper *> StringWrapperFunctor;
    const isLessThan<IntWrapper *> IntWrapperFunctor;


    vector<IComparable *> IComparables;
    vector<IntWrapper *> IntWrappers;
    vector<StringWrapper *> StringWrappers;

    int amt = 50000;

    IntWrappers.reserve(amt);
    StringWrappers.reserve(amt);
    IComparables.reserve(amt);


    // create and sort IC IntWrappers
    for (int i = 0; i < amt; i++)
        IComparables.push_back(new ICIntWrapper(randomIntRange(eng)));

    auto startTime = chrono::high_resolution_clock::now();
    ICSort::quickSort(IComparables);
    auto stopTime = high_resolution_clock::now();
    auto sortTime = duration_cast<milliseconds>(stopTime - startTime);
    cout << "\nSorting ICIntWrapper took " << sortTime.count() << " milliseconds for " << amt << " objects" <<
    "\nSorted: " << (ICSort::isSorted(IComparables)? "True" : "False") << endl;

    // clear because we're now putting string wrappers here
    IComparables.clear();
    IComparables.reserve(amt);


    // create and sort IC StringWrappers
    for (int i = 0; i < amt; i++)
        IComparables.push_back(new ICStringWrapper(gen_random(randomStringLength(eng))));

    startTime = chrono::high_resolution_clock::now();
    ICSort::quickSort(IComparables);
    stopTime = high_resolution_clock::now();
    sortTime = duration_cast<milliseconds>(stopTime - startTime);
    cout << "\nSorting ICStringWrapper took " << sortTime.count() << " milliseconds for " << amt << " objects" <<
    "\nSorted: " << (ICSort::isSorted(IComparables)? "True" : "False") << endl;
    IComparables.clear();


    // create and sort template int wrappers
    for (int i = 0; i < amt; i++)
        IntWrappers.push_back(new IntWrapper(randomIntRange(eng)));

    startTime = chrono::high_resolution_clock::now();
    Sort::quickSort(IntWrappers, IntWrapperFunctor);
    stopTime = high_resolution_clock::now();
    sortTime = duration_cast<milliseconds>(stopTime - startTime);
    cout << "\nTemplatized sorting IntWrapper took " << sortTime.count() << " milliseconds for " << amt << " objects" <<
         "\nSorted: " << (Sort::isSorted(IntWrappers, IntWrapperFunctor)? "True" : "False") << endl;
    IntWrappers.clear();


    // create and sort template string wrappers
    for (int i = 0; i < amt; i++)
        StringWrappers.push_back(new StringWrapper(gen_random(randomStringLength(eng))));

    startTime = chrono::high_resolution_clock::now();
    Sort::quickSort(StringWrappers, StringWrapperFunctor);
    stopTime = high_resolution_clock::now();
    sortTime = duration_cast<milliseconds>(stopTime - startTime);
    cout << "\nTemplatized sorting StringWrapper took " << sortTime.count() << " milliseconds for " << amt << " objects" <<
         "\nSorted: " << (Sort::isSorted(StringWrappers, StringWrapperFunctor)? "True" : "False") << endl;
    StringWrappers.clear();

    return 0;
}
