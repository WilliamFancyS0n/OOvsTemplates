#include <iostream>
#include "vector"

#include "IComparable.h"
#include "Sort.cpp"
#include "Intwrapper.cpp"
#include "Stringwrapper.cpp"


using namespace std;
int main() {
    vector<IComparable * > things;
    things.push_back(new Intwrapper(1));
    things.push_back(new Intwrapper(2));
    things.push_back(new Intwrapper(3));
    things.push_back(new Intwrapper(22));
    things.push_back(new Intwrapper(5));
    things.push_back(new Intwrapper(6));


    cout << (Sort::isSorted(things));

//    for (auto & thing : things) // didn't know you could write a for each loop like this, really cool
//        thing->printValue();


//    for (int i = 0; i < things.size() - 1; i ++) {
//        things[i]->printValue();
//    }

    return 0;

   // Sort::quickSort(things);


}
