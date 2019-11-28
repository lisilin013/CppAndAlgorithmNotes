//
// Created by nrsl on 19-9-12.
//

#ifndef ALGORITHM_CPP_WEIGHTED_QUICK_UNION_PATH_COMPRESSION_H
#define ALGORITHM_CPP_WEIGHTED_QUICK_UNION_PATH_COMPRESSION_H

#include <vector>
#include <iostream>
#include <cassert>


namespace algorithm_cpp{

class WeightedQuickUnionPathCompression {
public:
    WeightedQuickUnionPathCompression() = default;

    WeightedQuickUnionPathCompression(int N) {
        sz_.resize(N);
        id_.resize(N);
        for (int i = 0; i < N; ++i) {
            id_[i] = i;
            sz_[i] = 1;
        }

        size_ = N;
    }

    void init(int N) {
        sz_.resize(N);
        id_.resize(N);
        for (int i = 0; i < N; ++i) {
            id_[i] = i;
            sz_[i] = 1;
        }

        size_ = N;
    }


    /// \brief 复杂度o(lgN)
    int getRoot(int i) {
        assert(i < size_);
        while (i != id_[i]) {
            id_[i] = id_[id_[i]]; // 把树压平，保证树不会太深
            i = id_[i];
        }
        return i;
    }

    bool isConnected(int p, int q) {
        return getRoot(p) == getRoot(q);
    }

    /// \brief 把小树放到大树的下面，复杂度o(lgN)
    /// \param p
    /// \param q
    void unionTwo(int p, int q) {
        int i = getRoot(p);
        int j = getRoot(q);
        if (i == j)
            return;
        if (sz_[i] < sz_[j])// point tree i to tree j
        {
            id_[i] = j;
            sz_[j] += sz_[i];
        }
        else {
            id_[j] = i;
            sz_[i] += sz_[j];
        }
    }

private:
    std::vector<int> id_;
    std::vector<int> sz_;
    int size_;
};
}


#endif //ALGORITHM_CPP_WEIGHTED_QUICK_UNION_PATH_COMPRESSION_H
