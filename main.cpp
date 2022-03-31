    #include <iostream>
    #include <random>
    #include "vector"

    #include "IComparable.h"
    #include "Sort.cpp"
    #include "Intwrapper.cpp"
    #include "Stringwrapper.cpp"
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
    //    vector<IComparable * > things;
    //    things.push_back(new Stringwrapper("a"));
    //    things.push_back(new Stringwrapper("b"));
    //    things.push_back(new Stringwrapper("c"));
    //    things.push_back(new Stringwrapper("d"));
    //    things.push_back(new Stringwrapper("e"));
    //    things.push_back(new Stringwrapper("d"));

        //Sort::quickSort(things);
    //    cout << (Sort::isSorted(things));

    //    for (auto & thing : things) // didn't know you could write a for each loop like this, really cool
    //        thing->printValue();


    //    for (int i = 0; i < things.size() - 1; i ++) {
    //        things[i]->printValue();
    //    }



            const int amt = 1000000;
            vector<IComparable * > myIntegerWrappers;
            vector<IComparable * > myStringWrappers;

            myIntegerWrappers.reserve(amt);
            myStringWrappers.reserve(amt);

            random_device rd;
            default_random_engine eng(rd());
            uniform_int_distribution<int> randomIntRange(1, 1000);
            uniform_int_distribution<int> randomStringLength(1, 4);

            for (int i = 0; i < amt; i ++)
                myIntegerWrappers.push_back(new Intwrapper(randomIntRange(eng)));

            for (int i = 0; i < amt; i ++)
                myStringWrappers.push_back(new Stringwrapper(gen_random(randomStringLength(eng))));


            auto startTimeIntSort = chrono::high_resolution_clock::now();
            Sort::quickSort(myIntegerWrappers);
            auto stopTimeIntSort = high_resolution_clock::now();
            auto intSortTime = duration_cast<seconds>(stopTimeIntSort - startTimeIntSort);
            cout << "it took " << intSortTime.count() << " seconds to sort the integers" << endl;
            if (Sort::isSorted(myIntegerWrappers))
                cout << "sort verification complete, Integers are sorted!" << endl;


            auto startTimeStringSort = chrono::high_resolution_clock::now();
            Sort::quickSort(myStringWrappers);
            auto stopTimeStringSort = high_resolution_clock::now();
            auto stringSortTime = duration_cast<seconds>(stopTimeStringSort - startTimeIntSort);
            cout << "\nit took " << stringSortTime.count() << " seconds to sort the strings" << endl;
            if (Sort::isSorted(myStringWrappers))
                cout << "sort verification complete, Strings are sorted!" << endl;













    //
    //        Sort::quickSort(myIntegerWrappers);
    //        cout << Sort::isSorted(myIntegerWrappers);
    //    for (int i = 0; i < 100; i++)
    //        cout << gen_random(4) << endl;




        return 0;



    }
