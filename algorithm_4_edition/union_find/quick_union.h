//
// Created by nrsl on 19-9-12.
//

#ifndef ALGORITHM_CPP_QUICK_UNION_H
#define ALGORITHM_CPP_QUICK_UNION_H

#include <vector>
#include <iostream>
#include <cassert>

namespace algorithm_cpp{

/// \brief 相比QucikFindUF在数据结构上使用树的形式进行管理
///        虽然unionTwo的操作效率提高了，但是查找root的效率还是很低
///        复杂度为o(N)
class QuickUnion {
public:
    QuickUnion(int N) {
        id_.resize(N);
        for (int i = 0; i < N; ++i) {
            id_[i] = i;
        }

        size_ = N;
    }


    /// \brief union two elements means
    ///        make p's root point to q's root
    void unionTwo(int p, int q) {
        if (isConnected(p, q))
            return;

        id_[getRoot(p)] = getRoot(q);
    }

    /// \brief N
    int getRoot(int p) {
        assert(p < id_.size());
        while (id_[p] != p) {
            p = id_[p];
        }
        return p;
    }

    bool isConnected(int p, int q) {
        return getRoot(p) == getRoot(q);
    }

private:
    std::vector<int> id_;
    int size_;
};
}


#endif //ALGORITHM_CPP_QUICK_UNION_H
