//
// Created by Silin Li on 16:27 02/03/2020.
// 
#include <iostream>
#include <assert.h>
#include <vector>
#include "Utility.h"
using namespace std;

namespace test11{

int MinInOrder(int *arr, int low, int high) {
    int min_num = arr[high];
    for (int i = low; i < high; ++i) {
        if (min_num > arr[i])
            min_num = arr[i];
    }
    return min_num;
}
// 双闭区间内操作
int MinNumberInRotateArray(int *arr, int len) {
    assert(arr && len > 0);

    int low = 0, high = len - 1;
    int mid = low;//如果数组是有序的，直接就返回了

    // 前半边大
    while (arr[low] >= arr[high]) {
        if (low + 1 == high) {
            mid = high;//min等于第二个
            break;
        }

        mid = (low + high)/2;


        // 处理特殊情况
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            return MinInOrder(arr, low, high);
        }


        if (arr[mid] >= arr[low]) {
            low = mid;
        }
        else if (arr[mid] <= arr[high]) {
            high = mid;
        }
    }

    return arr[mid];
}

void run() {
    int len = 50;
    int *arr = new int[len];
    for (int i = 0; i < len/3; ++i) {
        arr[i] = len + i;
    }
    for (int i = len/3; i < len; ++i) {
        arr[i] = i;
    }

    Utility::TraversalSequence(arr, arr + len);
    cout << MinNumberInRotateArray(arr, len) << endl;
}
}


int main(int argc, char **argv) {
    test11::run();
    return 0;
}

