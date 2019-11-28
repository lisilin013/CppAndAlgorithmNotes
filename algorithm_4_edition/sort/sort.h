//
// Created by nrsl on 19-10-6.
//

#ifndef ALGORITHM_CPP_SORT_H
#define ALGORITHM_CPP_SORT_H
#include <algorithm>
#include <cassert>

#include "../search/binary_search.h"

namespace algorithm_cpp{


template<typename BidirectionalIt>
void PrintSorted(BidirectionalIt first, BidirectionalIt last) {
    assert(first < last);
    std::cout << "data: ";
    while (first != last) {
        std::cout << *first << " ";
        first++;
    }
    std::cout << std::endl;
}

/// 是否是有序数组，没有越界检查
template<typename BidirectionalIt, typename Compare>
bool IsSorted(BidirectionalIt first, BidirectionalIt last, Compare comp) {
    assert(first < last);
    if (first + 1 == last)
        return true;
    while (first != last - 1) {
        if (comp(*first, *(first + 1))) {
            first++;
        }
        else
            return false;
    }
    return true;
}


// 默认按照从小到大排列
// 复杂度 O(N^2)
// 选择排序，操作的是右半边的index
template<typename BidirectionalIt, typename Compare>
void SelectSort(BidirectionalIt first, BidirectionalIt last, Compare comp) {
    assert(first < last);
    for (auto i = first; i != last; i++) {
        auto index = i;
        // 遍历找到[i, last)中最小的那个index
        for (auto j = i; j != last; j++) {
            if (!comp(*index, *j))
                index = j;
        }
        // 如果确实找到了，那么将index和当前的i对应的数据进行位置交换
        if (index != i)
            std::swap(*i, *index);
    }
}


// 插入排序，操作的是左半边的index
template<typename BidirectionalIt, typename Compare>
void InsertSort(BidirectionalIt first, BidirectionalIt last, Compare comp) {
    assert(first < last);
    // 一个元素自然有序
    if (first + 1 == last)
        return;

    // >=2个元素
    for (auto i = first + 1; i != last; ++i) {
        // 当前位置i
        // 找到前段部分有序数列中的合适位置[first, i-1]
        auto index = i;
        for (auto j = first; j < i; ++j) {
            if (!comp(*j, *i)) {
                index = j;
                break;
            }
        }
        // 找到了合适的位置
        if (index != i) {
            auto tmp = *i;//使用一个tmp变量，节省内存
            while (i != index) {
                *i = *(i - 1);
                --i;
            }
            *index = tmp;
        }
    }
}

template<typename BidirectionalIt, typename Compare>
void ShellSort(BidirectionalIt first, BidirectionalIt last, Compare comp) {

}

// 普通数组类型进行操作
// [lo, mid) [mid, hi)
template<typename T, typename Compare>
void Merge(T *arr, size_t lo, size_t mid, size_t hi, Compare comp) {
    // 辅助数组
    auto arr_copy = new T[hi - lo];
    for (int i = lo; i < hi; ++i) {
        arr_copy[i] = arr[i];
    }

    //
    size_t i = lo;
    size_t j = mid;
    while (true) {
        if (i <= mid - 1 && j <= hi - 1) {//双边都有值可以接着取
            if (comp(arr[i], arr[j]))//i位置符合条件，原地不动
            {
                arr_copy
                i++;
            }
            else {
                tmp = *i;
                tmp = *j;
                j++;
            }
        }
        else if (i <= mid - 1 && j > hi - 1) {//只剩i这一边，保持不动即可
            break;
        }
        else if (i > mid - 1 && j <= hi - 1) {//只剩j这一边

        }
    }

    delete[] arr_copy;
}

template<typename T, typename Compare>
void MergeSort(T *arr, size_t lo, size_t hi, Compare comp) {

}

template<typename T, typename Compare>
void QuickSort(T *arr, size_t lo, size_t hi, Compare comp) {

}


}//namespace end


#endif //ALGORITHM_CPP_SORT_H
