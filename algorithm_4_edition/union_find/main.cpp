#include <iostream>
#include <algorithm>
#include "quick_find_uf.h"
#include "monte_carlo_simulation.h"
#include <eigen3/Eigen/Eigen>

using namespace algorithm_cpp;

using namespace std;

int main() {
//    MonteCarloSimulation monteCarloSimulation(20, 10000);
//    monteCarloSimulation.printPercolationStats();


    Eigen::Matrix<double, 3, 1> mat;
    mat << -1, 2, 3;
    cout << mat.cwiseAbs() << endl;
    cout << mat;

    auto a = 1 ? Eigen::Matrix<double, 3, 1>(mat.cwiseAbs()) : mat;

    return 0;
}