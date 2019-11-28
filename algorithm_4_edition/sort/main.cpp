//
// Created by nrsl on 19-10-6.
//

#include <iostream>
#include <vector>

#include "sort.h"

using namespace algorithm_cpp;
using namespace std;

#define TestSort SelectSort

int main() {
    int v[] = {1, 9, 3, 5, 8, 4, 1, 3, 2};
    int sz = sizeof(v)/sizeof(int);
    cout << "IsSorted: " << (IsSorted(v, v + sz, std::less_equal<int>()) ? "True" : "False") << endl;


    // 排序1
    TestSort(v, v + sz, std::less_equal<int>());
    cout << "IsSorted: " << (IsSorted(v, v + sz, std::less_equal<int>()) ? "True" : "False") << endl;

    // 排序2
    TestSort(v, v + 1, std::less_equal<int>());
    cout << "IsSorted: " << (IsSorted(v, v + 1, std::less_equal<int>()) ? "True" : "False") << endl;


    return 0;
}
