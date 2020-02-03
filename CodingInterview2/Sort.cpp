//
// Created by Silin Li on 09:52 02/03/2020.
// 
#include "Utility.h"
#include "Sort.h"
using namespace Algorithm;
using namespace std;
namespace test_sort{

void run() {
    vector<int> nums1, nums2;
    Utility::Random::CreateRandomIntsVector(25, 0, 25, nums1);
    Utility::TraversalSequence(nums1.begin(), nums1.end());
    MergeSort<int>(nums1.begin(), nums1.end(), std::less<int>());
    Utility::TraversalSequence(nums1.begin(), nums1.end());

    int *arr;
    Utility::Random::CreatRandomIntsArray(25, 0, 20, arr);
    QuickSort(arr, 25);
    Utility::TraversalSequence(arr, arr + 25);
}
}

int main(int argc, char **argv) {
    test_sort::run();
    return 0;
}

