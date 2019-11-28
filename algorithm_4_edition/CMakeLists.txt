cmake_minimum_required(VERSION 3.5)
project(algorithm_cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(monote_carlo_simulation union_find/main.cpp union_find/quick_find_uf.h union_find/quick_union.h union_find/weighted_quick_union.h union_find/weighted_quick_union_path_compression.h union_find/monte_carlo_simulation.h list/list.h)
add_executable(list list/main.cpp)
add_executable(statck stack/main.cpp)
add_executable(queue queue/main.cpp)
add_executable(sort sort/main.cpp)