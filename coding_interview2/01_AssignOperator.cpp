//
// Created by Silin Li on 15:54 01/26/2020.
// 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <mutex>

using namespace std;

namespace test1{
class CMyString {
public:
    CMyString(const char *pStr = nullptr) : pData_{nullptr} {
        if (!pStr) {
            return;
        }

        pData_ = new char[strlen(pStr) + 1]; //末尾存储'\0'
        strcpy(pData_, pStr);
    }

    // 不初始化这个: pData_{}，为啥就崩？，因为删除了一个非法地址
    // 拷贝构造函数
    CMyString(const CMyString &str) : pData_{nullptr} {
        // 检查是不是自身，非常重要
        if (this == &str) {
            return;
        }

        // 这一句是没有必要的，因为本身就是创建新的对象
        // delete[] pData_;

        pData_ = new char[strlen(str.data()) + 1];
        strcpy(pData_, str.data());
        cout << "copy constructor" << endl;
    }


    // 赋值运算符，深拷贝
    CMyString &operator=(const CMyString &str) {
        // 检查是不是自身，非常重要
        if (this == &str) {
            return *this;
        }

        // 异常不安全，有可能删除完，再申请内存失败，那么原有内容也丢失了
        // delete[] pData_;
        // pData_ = new char[strlen(str.data()) + 1];
        // strcpy(pData_, str.data());

        // 异常安全的写法，防止申请内存失败，仍能够保持原有数据
        // 思路：先申请一份内存，然后再交换，即使申请失败，也不会修改原有内容
        CMyString myString(str); // 调用copy constructor
        swap(pData_, myString.pData_);
        // swap(myString, *this); // Error: SIGSEGV 这个地方千万不能调用swap(*this, myString) 否则会无休止调用

        cout << "assign operator" << endl;
        return *this;//返回引用也非常细节
    }


    ~CMyString() {
        // 其实不判断也可以，因为删除空指针也没有问题
        if (pData_) {
            delete[] pData_;
        }
    }


    //---------------------------------
    // interface
    //---------------------------------
    char *data() const { return pData_; }
    size_t size() const { return strlen(pData_); }

private:
    char *pData_;
};

void run() {
    // init
    const char *str = string("123456789-nrsl").c_str();
    CMyString myString(str);
    printf("size: %zu\ncontent: %s\n", myString.size(), myString.data());

    CMyString myString1;
    myString1 = myString; // 调用 assign operator
    printf("size: %zu\ncontent: %s\n", myString1.size(), myString1.data());

    CMyString myString2 = myString;//这样会调用copy constructor
    printf("size: %zu\ncontent: %s\n", myString2.size(), myString2.data());
    CMyString myString3(myString);//这样会调用copy constructor
    printf("size: %zu\ncontent: %s\n", myString3.size(), myString3.data());
}

// 类外指针默认初始化为nullptr
// 类内指针随机指向一个地址，也就是野指针
class FuckPointer {
public:
    char *ptr;//传说中的野指针
    char *ptr1 = nullptr;//0
};

}



int main(int argc, char **argv) {
    test1::run();

    return 0;
}