//
// Created by nrsl on 19-10-7.
//

#ifndef ALGORITHM_CPP_BINARY_SEARCH_H
#define ALGORITHM_CPP_BINARY_SEARCH_H
namespace algorithm_cpp{

// 对一个有序数组进行二分查找，找到[lo, hi)中p位置数据应该排列的位置
//template<typename BidirectionalIt, typename Compare>
//BidirectionalIt BinarySearch(BidirectionalIt lo, BidirectionalIt hi, const T &p, Compare comp) {
//    // 判断首尾两个特殊情况，避免进入迭代判断，加速算法
//    if (!comp(*lo, p))
//        return lo;
//    if (!comp(p, *(hi - 1)))
//        return hi;
//    hi -= 1;//[lo, hi]
//    BidirectionalIt mid = lo + (hi - lo)/2;
//    while (lo < hi) {
//        if (p == *mid) {
//            break;
//        }
//        else if (comp(p, *mid))
//            hi = mid - 1;
//        else
//            lo = mid + 1;
//        mid = lo + (hi - lo)/2;
//    }
//
//
//    // 这个返回条件很关键，返回的是*p在[lo, high)中的实际应该排列位置
//    if (p == *mid)
//        return mid - lo;
//    else if (comp(p, *mid))
//        return mid - lo;
//    else
//        return mid - lo+ 1;
//}

}
#endif //ALGORITHM_CPP_BINARY_SEARCH_H
