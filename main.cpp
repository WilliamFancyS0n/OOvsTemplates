#include <iostream>



#include "Intwrapper.cpp"
#include "Stringwrapper.cpp"
#include "IComparable.h"
#include "vector"
using namespace std;
int main() {
    vector<IComparable * > things;
    things.reserve(50);
    for (int i = 0; i < 50; i++) {
        things.push_back(new Intwrapper(i));
    }

    for (int i = 1; i < 50; i++) {
        if (things[i-1]->isLessThan(*things[i])) {
            cout << "true" << endl;
        }
    }








    return 0;
}
