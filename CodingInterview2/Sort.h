//
// Created by Silin Li on 09:51 02/03/2020.
// 

#ifndef CODINGINTERVIEW_SORT_H
#define CODINGINTERVIEW_SORT_H
#include <iostream>
#include <cassert>
#include <ctime>
namespace Algorithm{
/**
 * -------------------不好的排排序----------------------
 * 1. 选择排序 O(n^2) 不稳定排序 每次遍历一遍把最小的放在最前面
 * 2. 冒泡排序 O(n^2) 稳定排序 每次交换相邻两个不符合条件的，一轮循环结果就是最大的放在了最后面
 * 3. 插入排序 O(n^2) 稳定排序 将当前值插入到前面的已经排好顺序的合适位置，需要挨个交换
 *
 * -------------------好的排排序----------------------
 * 4. 归并排序 O(nlog(n))时间O(n)空间  稳定
 * 5. 桶排序  O(n)时间 O(k)空间       稳定
 * 6. 快速排序 O(nlog(n))            不稳定
 * 7. 堆排序   O(nlog(n))            不稳定
 * 7. 希尔排序 O(nlog(n))            不稳定
 */
/**
 * @brief 左闭右开区间[start, end)内排序
 * @param start
 * @param end
 */
//------------------------------------------------
// merge sort
//------------------------------------------------
template<typename T, typename Iterator, typename Compare>
void Merge(Iterator low, Iterator mid, Iterator high, Compare comp) {
    assert(low < mid && mid < high);

    // auxiliary array
    T *aux = new T[high - low];
    std::copy(low, high, aux);

    T *it1 = aux;
    T *it2 = aux + (mid - low);
    T *it1_end = it2;
    T *it2_end = aux + (high - low);
    Iterator index = low;//sort original sequence
    while (true) {
        if (it1 != it1_end) {//左半边有
            if (it2 != it2_end) {//右半边有
                if (comp(*it1, *it2)) {
                    *index = *it1;
                    ++index;
                    ++it1;

                }
                else {
                    *index = *it2;
                    ++index;
                    ++it2;
                }
            }
            else {//右半边没了，只剩下左半边了
                while (it1 != it1_end) {
                    *index = *it1;
                    ++index;
                    ++it1;
                }
            }
        }
        else if (it2 != it2_end) {//左半边没了,只剩下右半边
            while (it2 != it2_end) {
                *index = *it2;
                ++index;
                ++it2;
            }
        }
        else {
            break;
        }
    }

    delete[] aux;
}


template<typename T, typename Iterator, typename Compare>
void MergeSort(Iterator start, Iterator end, Compare comp) {
    if (end - start > 1) {//多于1个元素
        Iterator mid = start + (end - start)/2;
        MergeSort<T>(start, mid, comp);
        MergeSort<T>(mid, end, comp);
        Merge<T>(start, mid, end, comp);
    }
}

//--------------------------------------------------
// quick sort
// 在双闭区间内操作
//--------------------------------------------------
int Partition(int arr[], int start, int end) {
    assert(arr && start >= 0 && start <= end);
    srand(time(nullptr));
    int index = (rand()%(end - start + 1)) + start;//[start, end]
    std::swap(arr[index], arr[end]);//先把这个数字放到最后面

    int small = start - 1;
    for (int i = start; i < end; ++i) {
        if (arr[i] < arr[end]) {
            ++small;
            if (small != i) {//这是一种比较高效的做法
                std::swap(arr[small], arr[i]);
            }
        }
    }

    ++small;
    std::swap(arr[small], arr[end]);//把选中的数字放到分界位置
    return small;
}

void QuickSortCore(int arr[], int start, int end) {
    assert(arr && start >= 0 && start <= end);
    int index = Partition(arr, start, end);

    //[start, index, end]
    if (index > start) {
        QuickSortCore(arr, start, index - 1);
    }
    if (index < end) {
        QuickSortCore(arr, index + 1, end);
    }
}

void QuickSort(int data[], int length) {
    assert(data && length > 0);
    QuickSortCore(data, 0, length - 1);
}


}
#endif //CODINGINTERVIEW_SORT_H
