//
// Created by Silin Li on 19:47 01/03/2020.
// 

#pragma once
#include <cstdio>      /* printf, NULL */
#include <cstdlib>
#include <vector>
#include <ctime>
#include <chrono>
#include <iostream>

namespace Utility{


class Random {
public:
    /**
    * [lower_bound，upper_bound)
    */
    template<typename T>
    T cRandom(int min, int max) {
        srand(time(NULL));
        return (min + static_cast<T>(max*rand()/static_cast<T>(RAND_MAX + 1)));
    }

    static void CreateRandomIntsVector(const size_t &size, const int &a, const int &b, std::vector<int> &ret) {
        srand(time(NULL));
        ret.clear();
        ret.resize(size);
        for (int i = 0; i < size; ++i) {
            ret[i] = (rand()%(b - a)) + a;
        }
    }


    static void CreatRandomIntsArray(const size_t &size, const int &a, const int &b, int *&ret) {
        srand(time(NULL));
        ret = new int[size];
        for (int i = 0; i < size; ++i) {
            ret[i] = (rand()%(b - a)) + a;
        }
    }
};


class TicToc {
public:
    TicToc(bool out = false) : is_out_(out) {
        tic();
    }

    void tic() {
        start_ = std::chrono::system_clock::now();
    }

    double toc() {
        end_ = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end_ - start_;
        double delt_t = elapsed_seconds.count()*1000;
        if (is_out_) {
            std::cout << "\033[1;32mTime elapsed: " << delt_t << " ms\033[0m" << std::endl;
        }

        return delt_t;
    }

private:
    std::chrono::time_point<std::chrono::system_clock> start_, end_;
    bool is_out_;
};

template<typename Iterator>
void TraversalSequence(Iterator start, Iterator end) {
    while (start != end) {
        std::cout << *start << " ";
        ++start;
    }
    std::cout << std::endl;
}

}
