#include <iostream>

using namespace std;


namespace test_sizeof{
class EmptyClass {
};

class VirtualClass {
    VirtualClass() {}

    // virtual table pointer: 4 bytes
    // number of virtual functions: 4 bytes
    virtual ~VirtualClass() {}
};

void run() {
    cout << "==========test_sizeof===============" << endl;
    cout << "size_of(EmptyClass): " << sizeof(EmptyClass) << endl;
    cout << "size_of(VirtualClass): " << sizeof(VirtualClass) << endl; // run in gcc compiler
}
}


namespace test_copy_constructor{
class A {
private:
    int value_;
public:
    explicit A(const int &n) { value_ = n; }
    // 拷贝构造函数不允许传值，只能传引用
    // A(A a) { value_ = a.value_; }
    A(const A &a) {
        value_ = a.value_; //之所以可以直接访问私有变量，是因为类似友元函数
        cout << "copy contructor" << endl;
    }


    // 注意深拷贝（拷贝数据）和浅拷贝（只拷贝指针地址）
    A &operator=(const A& a) {
        this->value_ = a.getValue();
        cout << "assign operator" << endl;
        return *this;
    }


    void print() const { cout << value_ << endl; }
    int getValue() const { return value_; }
};

void run() {
    cout << "==========test_copy_constructor===============" << endl;
    A a(10);//调用A(int n)
    A b = a;//调用copy constructor，因为这是初始化
    A c(0);
    // 如果operator=函数是传值，那么发生两步故事(1)copy constructor (2)assign operator
    // 如果operator=函数是传引用，那么只有assign operator
    c = b;// 因为这个是赋值
}
}

int main() {
    test_sizeof::run();
    test_copy_constructor::run();

    return 0;
}

