//
// Created by lisilin on 2020-01-01.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <mutex>

using namespace std;



namespace test2{

// 该类只能创建一个实例
class Singleton {
public:
    static Singleton &getInstance() {
        // 为空则创建
        if (!instance_) {
            // 线程安全，防止其他线程冲突的时候，同时创建超过一个实例
            // TODO：之所以是双重判断，是为了防止同时加锁？？
            std::unique_lock<std::mutex> lock(*mtx_);
            {
                if (!instance_) {
                    instance_ = new Singleton();
                }
            }
        }
        return *instance_;
    }

    int getData() const { return data_; }
    void setData(const int &data) { data_ = data; }
private:
    Singleton() {}
    // 数据全部是共享的，没有私有数据
    static Singleton *instance_;
    static int data_;
    static std::mutex *mtx_;
};

// init data member
int Singleton::data_ = 0;
Singleton *Singleton::instance_ = nullptr;
std::mutex *Singleton::mtx_ = new std::mutex();

void run() {
    Singleton instance = Singleton::getInstance();
    instance.setData(10);
    cout << Singleton::getInstance().getData() << endl;

    Singleton instance2 = Singleton::getInstance();
    instance2.setData(5);

    cout << Singleton::getInstance().getData() << endl;
}
}

int main(int argc, char **argv) {
//    test1::run();

    test2::run();
    return 0;
}