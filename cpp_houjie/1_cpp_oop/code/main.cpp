#include <iostream>

//-----------------------------------------------------
// functor
//-----------------------------------------------------
namespace functor{

class Stone {
public:
    Stone(const int &w) : weight_(w) {}
    bool operator<(const Stone &s) const { return this->weight_ < s.weight_; }
    int getWeight() const { return weight_; }
private:
    int weight_;
};

// 仿函数写法，需要实例化才能使用
template<typename T>
struct compare_st {
    bool operator()(const T &a, const T &b) const {
        return a < b;
    }
};

compare_st<Stone> comp;


// 模拟需要输入compare的函数接口
template<typename T, typename Compare>
bool compare_func(const T &a, const T &b, const Compare &cmp) {
    return cmp(a, b);
}

void FuncTest() {
    Stone s1(2);
    Stone s2(3);
    std::cout << compare_func(s1, s2, std::less<Stone>()) << std::endl; // 使用std标准库
    std::cout << compare_func(s1, s2, compare_st<Stone>()) << std::endl; // 使用自定义compare仿函数
    std::cout << compare_func(s1, s2, comp) << std::endl; // 使用自定义compare仿函数的实例化对象
    std::cout << compare_func(s1, s2, [&](const Stone &s1, const Stone &s2) { return s1 < s2; }) << std::endl; // 使用lambda函数
}

}// funtor_test namespace end

//-----------------------------------------------------
// member template: Pair Class Experiment
//-----------------------------------------------------
namespace member_template{

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair() : first(T1()), second(T2()) {}
    Pair(const T1 &t1, const T2 &t2) : first(t1), second(t2) {}

    // member template 支持传入不同类型的pair
    template<typename U1, typename U2>
    Pair(const Pair<U1, U2> &p):first(p.first), second(p.second) {}

    Pair(const Pair<T1, T2> &p) : first(p.first), second(p.second) {}

};


/**
 * @brief: base class
 */
class Shape {
    friend std::ostream &operator<<(std::ostream &os, const Shape &p);

public:
    Shape(const std::string &s = "Shape") : name_(s) { id_ = id_count_++; }
    virtual double getParam() const { return 0; };

protected:
    std::string name_;
    int id_; // 从0开始
    static int id_count_;
};

// init static member
int Shape::id_count_ = 0;

/**
 * @brief: output class shape information
 */
std::ostream &operator<<(std::ostream &os, const Shape &p) {
    os << "name: " << p.name_ << " id: " << p.id_;
    return os;
}


/**
 * @brief: Derive class
 */
class Circle : public Shape {
    friend std::ostream &operator<<(std::ostream &os, const Circle &c);

public:
    Circle(const std::string &name = "Circle", const double &r = 0) : Shape(name), radius_(r) {}
    double getParam() const override { return radius_; }
private:
    double radius_;
};

/**
 * @brief: output class Circle information
 */
std::ostream &operator<<(std::ostream &os, const Circle &c) {
    os << "name: " << c.name_ << " id: " << c.id_ << " radius: " << c.radius_;
    return os;
}

void PairTest() {
    // a Shape object
    Pair<Shape, Shape> p1(Shape("Shape1"), Shape("Shape2"));

    // a Circle object
    Pair<Circle, Circle> p2(Circle("Circle1", 0.5), Circle("Circle2", 0.6));

    // use a shape to contain a circle,
    Pair<Shape, Shape *> p3(Circle("Circle3", 0.7), new Circle("Circle4", 0.8));
    std::cout << "现在只能访问shape     : " << (p3.first) << std::endl; // 现在只能访问shape的部分
    std::cout << "dynamic_cast        : " << *dynamic_cast<Circle *> (p3.second) << std::endl; // 如果使用指针，可以利用多态，访问circle部分
    std::cout << "no dynamic_cast     : " << *p3.second << std::endl; // 如果使用指针，可以利用多态，访问circle部分


    // 需要member template才能支持这种写法
    Pair<Shape, Shape> p4(p2);
    std::cout << "非指针存储不能访问circle: " << p4.first << std::endl; // 还是仍然不能访问circle部分，还是必须利用多态，member template的作用就是多提供了一种初始化方式

    Pair<Circle *, Circle *> pp1(new Circle("pointer-circle1", 0.6), new Circle("pointer-circle2", 0.7));
    Pair<Shape *, Shape *> pp2(pp1);
    std::cout << "指针存储可以访问circle : " << *pp1.first << std::endl; //不需要

}

}// member template  namespace end

//-----------------------------------------------------
// specialization
// 解决问题： 模板中的某些类型，可以用更高效或者不同的方法来处理的时候
// 比如针对两点间draw line的问题，如果是两个int 点，那么可以使用更好
// 的breshham算法来处理，其他的类型正常处理
//-----------------------------------------------------
namespace specialization{
template<typename T>
class DrawLine {
public:
    DrawLine() { std::cout << "draw line using normal algorithm\n"; }
};

template<>
class DrawLine<int> {
public:
    DrawLine() { std::cout << "draw line using Breshham algorithm\n"; }
};

// 类模板实例化的时候，会优先使用特化的模板
void test() {
    DrawLine<double> dl1; // draw line using normal algorithm
    DrawLine<std::string> dl2; // draw line using normal algorithm
    DrawLine<int> dl3; //draw line using Breshham algorithm

}

} //specialization namespace end


//-----------------------------------------------------
// partial specialization
// 有两种偏特化：
// 1. 个数的偏，模板中的某些类型，提供一些默认值
// 2. 范围的偏
// 解决问题： 模板中的某些类型，提前绑定
//-----------------------------------------------------
#include <vector>
namespace parial_specialization{
// -----------------【1. 个数的偏】-----------------------
class BoolAllocator;

// 一些类型根据模板正常推导
template<typename T, typename Alloc=std::allocator<T>>
class Container {
public:
    Container() { std::cout << "normal contailer\n"; }
};

// 针对某些特殊的类型，就自己提供后面的模板参数
// 比如存储bool类型的时候，由于只有1bit，如果使用int存储就会很浪费
// 那么就提供一个自我实现的高效的BoolAllocator
template<typename Alloc>
class Container<bool, Alloc> {
public:
    Container() { std::cout << "bool contailer\n"; }
};


// -----------------【2. 范围的偏】-----------------------
// 非指针的是使用这种模板推导
template<typename T>
class Storage {
public:
    Storage() { std::cout << "non-pointer like object\n"; }
};

// 指针使用这种模板推导
template<typename T>
class Storage<T *> {
public:
    Storage() { std::cout << "pointer like object\n"; }
};

void test() {
    // 1. 个数的偏
    Container<int> c1; // normal contailer
    Container<bool, BoolAllocator> c2; // bool contailer

    // 2. 范围的偏
    Storage<int> s1; // non-pointer like object
    Storage<int *> s2; // pointer like object
}
}//parial_specialization namespace end


//-------------------------------------------------------------
// template template parameter 模板模板参数
//-------------------------------------------------------------
#include <string>
#include <iostream>
#include <list>
#include <deque>

namespace template_template_parameter{

template<typename T, template<typename T> class Container>
class XCls {
public:
    Container<T> c;

    XCls() {
        // 预先开辟capacity=100的内存
        c.resize(100);
    }
};

template<typename T>
using Lst = std::list<T, std::allocator<T>>;   //Note: make sure your environment support C++2.0

void template_template_parameter_test() {
    std::cout << "test_template_template_parameters_1()" << std::endl;

    //!	XCls<string, list> mylist;
    //[Error] expected a template of type 'template<class T> class Container', got 'template<class _Tp, class _Alloc> class std::list'
    XCls<int, Lst> mylist;        //Note: make sure your environment support C++2.0
    std::cout << "size    : " << mylist.c.size() << std::endl;
}


//------------------------------------------------
// no template template parameter
//------------------------------------------------
template<class T, class Sequence=std::deque<T>>
class Stack {
public:
    Stack() {
        c.resize(100);
    }
    Sequence c;
};


void no_template_template_parameter_test() {
    Stack<int> s1;
    Stack<std::string, std::list<std::string>> s2;
}

} //namespace

//------------------------------------------------------------
// variadic templates: 不定长参数的用法
//                     这也太牛逼了....
//------------------------------------------------------------
namespace variadic_templates{
// 1. 用于function template types
void print() {}
template<typename T, typename ... Types>
void print(const T &first_arg, const Types &... args) {
    std::cout << first_arg << " sizeof: " << sizeof...(args) << std::endl;
    print(args...);
}

// 2. 用于template parameters
// 3. 用于function parameters

}//namespace variadic_templates end


#include <algorithm>

int main() {
    double array[32] = {-10.2810,
                        -6.4240,
                        2.3330,
                        3.3330,
                        4.6670,
                        7.0000,
                        10.3330,
                        15.0000,
                        0.3330,
                        -0.0000,
                        -0.3330,
                        -0.6670,
                        1.6849,
                        1.3330,
                        1.0000,
                        0.6670,
                        -25.0000,
                        -14.6380,
                        -7.9100,
                        -5.4070,
                        -3.6670,
                        -3.9287,
                        -4.3152,
                        -4.6670,
                        -2.3330,
                        -2.6313,
                        -3.0000,
                        -3.3330,
                        -1.0179,
                        -1.3688,
                        -1.6670,
                        -2.0000
    };

    std::sort(std::begin(array), std::end(array), std::less<double>());

    std::for_each(std::begin(array), std::end(array),[](const double& data){
        std::cout<<data<<",";
    });

    return 0;
}