//
// Created by nrsl on 19-9-12.
//

#ifndef ALGORITHM_CPP_QUICK_FIND_UF_H
#define ALGORITHM_CPP_QUICK_FIND_UF_H

#include <vector>
namespace algorithm_cpp
{

class QuickFindUF{
public:
    /// \brief init
    QuickFindUF(int N){
        id_.resize(N);
        for (int i = 0; i < N; ++i) {
            id_[i] = i;
        }
    }

    /// \brief change first element's id to the second element's id
    ///
    /// N^2
    void unionTwo(int p, int q)
    {
        if(isConnected(p,q))
            return;

        int pid = id_[p];
        int qid = id_[q];

        for (int i = 0; i < id_.size(); ++i) {
            if(id_[i] == pid)
            {
                id_[i] = qid;
            }
        }
    }

    bool isConnected(int p, int q)
    {
        return id_[p]==id_[q];
    }

private:
    std::vector<int> id_;

};

}



#endif //ALGORITHM_CPP_QUICK_FIND_UF_H
