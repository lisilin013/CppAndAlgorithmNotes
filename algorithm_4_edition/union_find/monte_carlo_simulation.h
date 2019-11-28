//
// Created by nrsl on 19-9-14.
//

// question introduction: https://coursera.cs.princeton.edu/algs4/assignments/percolation/specification.php
#pragma once
#include "weighted_quick_union_path_compression.h"
#include <algorithm>
namespace algorithm_cpp{

class Percolation {
public:
    Percolation() = default;

    Percolation(int n) {
        reset(n);
    }

    // creates n-by-n grid, with all sites initially blocked
    void reset(int n) {
        opened_cnt_ = 0;
        uf_size_ = n*n + 2;
        row_num_ = n;
        uf_.init(uf_size_);
        opened_id_.resize(uf_size_);
        std::for_each(opened_id_.begin(), opened_id_.end(), [](int &id) { id = 0; });
    }

    // index: 1 -- n*n
    void open(int index) {
        int col = index%row_num_ - 1;
        int row = index/row_num_;
        open(row, col);
    }

    // opens the site (row, col) if it is not open already
    // start from 0 to n-1
    void open(int row, int col) {
        if (isOpen(row, col))
            return;

        // if still closed, then open this site
        int cur_id = getSiteId(row, col);
        opened_id_[cur_id] = 1;
        opened_cnt_++;

        // do unionTwo between its 4-neighbors
        if (row == 0) // union first node
        {
            uf_.unionTwo(cur_id, 0);
        }
        else if (row >= 1)// can find up neighbor
        {
            int up_id = getSiteId(row - 1, col);
            if (opened_id_[up_id])// up-neighbor is opened, then union two of them
                uf_.unionTwo(up_id, cur_id);
        }

        if (row == row_num_ - 1)// union last node
        {
            uf_.unionTwo(cur_id, uf_size_ - 1);
        }
        else if (row <= row_num_ - 2)// can find low neighbor
        {
            int low_id = getSiteId(row + 1, col);
            if (opened_id_[low_id])
                uf_.unionTwo(low_id, cur_id);
        }


        if (col >= 1)// can find left neighbor
        {
            int left_id = getSiteId(row, col - 1);
            if (opened_id_[left_id])
                uf_.unionTwo(left_id, cur_id);
        }

        if (col <= row_num_ - 2)// can find right neighbor
        {
            int right_id = getSiteId(row, col + 1);
            if (opened_id_[right_id])
                uf_.unionTwo(right_id, cur_id);
        }
    }

    // is the site (row, col) open?
    bool isOpen(int row, int col) {
        return opened_id_[getSiteId(row, col)];
    }

    // is the site (row, col) full?
    bool isFull(int row, int col) {

    }

    // returns the number of open sites
    int numberOfOpenSites() {
        return opened_cnt_;
    }

    // does the system percolate?
    bool percolates() {
        return uf_.isConnected(0, uf_size_ - 1);
    }

    // id is form 0 to n*n+1
    int getSiteId(int row, int col) {
        return row*row_num_ + col + 1;
    }

private:
    WeightedQuickUnionPathCompression uf_;
    int opened_cnt_;
    int uf_size_;
    int row_num_;
    std::vector<int> opened_id_;
};

class MonteCarloSimulation {
public:
    // perform independent trials on an n-by-n grid
    MonteCarloSimulation(int n, int trials) {
        trials_threshold_.resize(trials);
        // trial 100 tests
        for (int i = 0; i < trials; ++i) {
            percolation.reset(n);

            // generate random open index
            // 1 -- n*n
            std::vector<int> shuffle_open_index;
            for (int j = 0; j < n*n; ++j) {
                shuffle_open_index.push_back(j + 1);
            }
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(shuffle_open_index.begin(), shuffle_open_index.end(), g);

            // open sites using random index
            int cnt = 0;
            while (!percolation.percolates() || cnt >= shuffle_open_index.size()) {
                int index = shuffle_open_index[cnt++];// 1 -- n*n
                percolation.open(index);
            }

            // calculate percolate threshold
            trials_threshold_[i] = 1.0*percolation.numberOfOpenSites()/(n*n);
            std::cout << "Trial " << i + 1 << ", Threshold " << trials_threshold_[i] << std::endl;
        }
    }

    // sample mean of percolation threshold
    double mean() {
        double m = 0;
        std::for_each(trials_threshold_.begin(), trials_threshold_.end(), [&](double x) { m += x; });
        return m/trials_threshold_.size();
    }

    // sample standard deviation of percolation threshold
    double stddev() {
        double sum = 0;
        double m = mean();
        std::for_each(trials_threshold_.begin(), trials_threshold_.end(), [&](double x) { sum += (x - m)*(x - m); });
        return sqrt(sum/(trials_threshold_.size() - 1));
    }

    // low endpoint of 95% confidence interval
    double confidenceLo() {
        double m = mean();
        double s = stddev();
        return m - 1.96*s/sqrt(trials_threshold_.size());
    }

    // high endpoint of 95% confidence interval
    double confidenceHi() {
        double m = mean();
        double s = stddev();
        return m + 1.96*s/sqrt(trials_threshold_.size());
    }

    void printPercolationStats() {
        std::cout << "----Percolation Stats----\n";
        std::cout << "mean " << mean() << std::endl;
        std::cout << "stddev " << stddev() << std::endl;
        std::cout << "95% confidence interval " << confidenceLo() << " " << confidenceHi() << std::endl;
    }

private:
    Percolation percolation;
    std::vector<double> trials_threshold_;
};
}