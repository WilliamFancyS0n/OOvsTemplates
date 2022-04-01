    #include <iostream>
    #include <random>
    #include "vector"

    #include "OO_Version/IComparable.h"
    #include "OO_Version/ICSort.cpp"
    #include "OO_Version/ICIntWrapper.cpp"
    #include "OO_Version/ICStringWrapper.cpp"

    #include <chrono>


    using namespace std;
    using namespace std::chrono;
    std::string gen_random(const int len) {
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
            //const int amt = 1000000;
            const int amt = 20000;
            vector<IComparable * > myIntegerWrappers;
            vector<IComparable * > myStringWrappers;

            myIntegerWrappers.reserve(amt);
            myStringWrappers.reserve(amt);

            random_device rd;
            default_random_engine eng(rd());
            uniform_int_distribution<int> randomIntRange(1, 1000);
            uniform_int_distribution<int> randomStringLength(1, 4);

            for (int i = 0; i < amt; i ++)
                myIntegerWrappers.push_back(new ICIntWrapper(randomIntRange(eng)));

            for (int i = 0; i < amt; i ++)
                myStringWrappers.push_back(new ICStringWrapper(gen_random(randomStringLength(eng))));


            auto startTimeIntSort = chrono::high_resolution_clock::now();
            ICSort::quickSort(myIntegerWrappers);
            auto stopTimeIntSort = high_resolution_clock::now();
            auto intSortTime = duration_cast<seconds>(stopTimeIntSort - startTimeIntSort);
            cout << "it took " << intSortTime.count() << " seconds to sort the integers" << endl;
            if (ICSort::isSorted(myIntegerWrappers))
                cout << "sort verification complete, Integers are sorted!" << endl;


            auto startTimeStringSort = chrono::high_resolution_clock::now();
            ICSort::quickSort(myStringWrappers);
            auto stopTimeStringSort = high_resolution_clock::now();
            auto stringSortTime = duration_cast<seconds>(stopTimeStringSort - startTimeIntSort);
            cout << "\nit took " << stringSortTime.count() << " seconds to sort the strings" << endl;
            if (ICSort::isSorted(myStringWrappers))
                cout << "sort verification complete, Strings are sorted!" << endl;


            for (auto & s : myStringWrappers) {
                s->printValue();
            }



        return 0;
    }
