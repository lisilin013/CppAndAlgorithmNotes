//
// Created by lisilin on 20-1-3.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include "Utility.h"
using namespace std;

namespace test3{


class FindDuplicate {
public:
    virtual bool operator()(vector<int> &nums, unordered_map<int, int> &duplicates) = 0;

};

/**
 * @brief 找出任意一个重复的数字
 *        NOTICE: cpp中数组传入退化为指针传入
 *        空间O(n)，时间O(1) 不改变数组
 * @param nums
 * @param duplicates<重复的数字，重复次数>
 * @return
 */
class FindDuplicateByHash : public FindDuplicate {
public:
    bool operator()(vector<int> &nums, unordered_map<int, int> &duplicates) override {
        bool isDuplicate = false;
        duplicates.reserve(nums.size()/2);

        // 使用hash table统计数据
        unordered_set<int> nums_set;
        size_t N = nums.size();
        for (int i = 0; i < N; ++i) {
            if (nums_set.count(nums[i])) {
                isDuplicate = true;
                duplicates[nums[i]]++; //统计重复的数字，及重复个数
                return true; //只找出第一个那么就返回
            }
            else {
                nums_set.insert(nums[i]);
            }
        }

        return isDuplicate;
    }
};

/**
 * @brief 空间O(1)，时间O(nlogn) 会改变原先数组数据
 */
class FindDuplicateBySort : public FindDuplicate {
public:
    bool operator()(vector<int> &nums, unordered_map<int, int> &duplicates) override {
        bool isDuplicate = false;
        duplicates.reserve(nums.size()/2);

        sort(nums.begin(), nums.end());

        // 使用hash table统计数据
        size_t N = nums.size();
        int now = nums[0];
        int pre = now;
        for (int i = 1; i < N; ++i) {
            now = nums[i];
            if (now == pre) {
                isDuplicate = true;
                duplicates[now]++; //统计重复的数字，及重复个数
                return true;//只找出第一个那么就返回
            }
            pre = now;
        }

        return isDuplicate;
    }
};

/**
 * 时间O(n)，空间O(1)
 * 前面的两种解法适用于任何范围的数字，并且可以找出所有重复的数字，并统计
 * 根据题目的特殊性，可以进一步加速
 * 数字范围[0, n-1]，长度为n
 * NOTICE: 会修改数组，且不能找出所有重复数字
 */
class FindDuplicateByArray : public FindDuplicate {
public:
    bool operator()(vector<int> &nums, unordered_map<int, int> &duplicates) override {
        duplicates.reserve(nums.size()/2);
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            // check number is in range
            if (nums[i] < 0 || nums[i] >= N) {
                cout << "A number is out of range [0, " << N - 1 << "]" << endl;
                cout << "The number is " << nums[i] << endl;
                cout << "The number's index is " << i << endl;
                return false;
            }
        }
        for (int i = 0; i < N; ++i) {
            // check duplicate
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    duplicates[nums[i]]++;
                    return true;
                }
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }

        return false;
    }
};

/**
 * @brief 利用多态来管理不同的测试算法
 */
template<typename Func>
void run(const vector<Func *> &funcs) {
    for (const auto &func  : funcs) {
        // generator random vector numbers
        vector<int> nums;
        Utility::Random::CreateRandomIntsVector(1000000, 0, 1000000, nums);

        // run algorithm
        unordered_map<int, int> dups;
        Utility::TicToc tictoc(true);
        bool find_duplicate = (*func)(nums, dups);
        tictoc.toc();

        // print result
        if (find_duplicate) {
            cout << "duplicate size: " << dups.size() << endl;
//            cout << "duplicate num | duplicates counts" << endl;
//            for (const auto &item: dups) {
//                cout << item.first << " : " << item.second << endl;
//            }
        }
        else {
            cout << "There is no duplicate nums" << endl;
        }
    }


}
}

/*
 * 算法分析：上述三种方法，从时间上看，最快的是hash方法，最慢的是sort方法，中间的是array方法
 *
 * hash不改变数组，但是消耗空间大，速度最快，可以找出所有的重复数字
 * sort改变数组，不消耗空间，但是速度太慢，不建议！！
 * array改变数组，不消耗空间，速度比hash方法慢一倍多
 *
 * 总结：如果空间足够，用hash；如果时间要求不是极致，那么用数组。如果要求找出全部，还是用hash
 **/
int main(int argc, char **argv) {
    vector<test3::FindDuplicate *> funs;
    funs.push_back(new test3::FindDuplicateByHash());
    funs.push_back(new test3::FindDuplicateBySort());
    funs.push_back(new test3::FindDuplicateByArray());
    test3::run(funs);
    return 0;
}
