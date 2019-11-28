/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.24
 *      Author: Caroline
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

//-----------------------------------------------------
// member template： 和functor结合使用
//-----------------------------------------------------
class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}

    // functor
    // member template
    template<typename T>
    void operator()(T *p) const {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};


//-----------------------------------------------------
// member template： 用于排序
//-----------------------------------------------------
template<typename T>
class Blob {
public:

    // 应对不同类型，可以排序
    template <typename It>
    Blob (It b, It e) {
        std::sort(b, e); //容器需要允许被排序
    }
};

// 类外的写法
//template<typename T>
//template<typename It>
//Blob<T>::Blob(It b, It e) {
//    std::sort(b, e); //容器需要允许被排序
//}

int main(void) {

    // delete using functor
    double *p = new double;
    DebugDelete d;
    d(p); //使用时, 可以自动推倒模板

    int *ip = new int;
    DebugDelete()(ip);

    std::unique_ptr<int, DebugDelete> pi(new int, DebugDelete());
    std::unique_ptr<std::string, DebugDelete> ps(new std::string, DebugDelete());


    // 构建不同的容器类型
    int ia[] = {9, 8, 7, 6, 5};
    std::vector<long> vi = {5, 4, 3, 2, 1, 0};
    std::deque<std::string> w = {"lady", "girl", "woman", "now"};

    // 构建Blob对象，构造函数自动会对其进行排序
    Blob<int> a1(std::begin(ia), std::end(ia));
    Blob<int> a2(vi.begin(), vi.end());
    Blob<std::string> a3(w.begin(), w.end());

    // 打印输出
    std::cout << "int ia[] = ";
    for (const auto i : ia) { std::cout << i << " "; }
    std::cout << std::endl;

    std::cout << "std::vector<long> vi = ";
    for (const auto i : vi) { std::cout << i << " "; }
    std::cout << std::endl;

    std::cout << "std::list<const char*> w = ";
    for (const auto i : w) { std::cout << i << " "; }
    std::cout << std::endl;

    return 0;

}