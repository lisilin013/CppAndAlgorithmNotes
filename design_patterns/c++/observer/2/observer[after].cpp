#include <vector>
#include <iostream>
using namespace std;

//-------------------------------------------------------------------
// 问题： 同一个数据，想要用几种不同的方式去处理
//
// Subject和Observer是很早就写好的
// 开发应用程序的用户，想要创建自己业务场景的Observer，那么就继承Observer
// 事实上，可以看做ros中的callback机制的建议实现，用于数据更新
//-------------------------------------------------------------------


/**
 * @brief: 最根本的父类
 */
class Observer {
public:
    // 必须是纯虚函数，不同的子类应该有不同的行为
    virtual void update(int value) = 0;
};


/**
 * @brief: 管理所有观察者的类
 */
class Subject {
    int m_value;
    vector<Observer *> m_views; //委托
public:
    // 加入一个观察者
    void attach(Observer *obs) {
        m_views.push_back(obs);
    }

    // 改变数据，通知所有观察者
    void set_val(int value) {
        m_value = value;
        notify();
    }

    // 通知所有观察者
    void notify() {
        for (auto &m_view : m_views)
            m_view->update(m_value);
    }
};

/**
 * @brief: 观察者1
 */
class DivObserver : public Observer {
    int m_div;
public:
    // 创建观察者
    DivObserver(Subject *model, int div) {
        model->attach(this);
        m_div = div;
    }

    DivObserver(int div) {
        m_div = div;
    }

    // 重新实现update函数，用来接受Subject通知的更新信息
    void update(int v) override {
        cout << v << " div " << m_div << " is " << v/m_div << '\n';
    }
};

/**
 * @brief: 观察者2
 */
class ModObserver : public Observer {
    int m_mod;
public:
    ModObserver(Subject *model, int mod) {
        model->attach(this);
        m_mod = mod;
    }

    ModObserver(int mod) {
        m_mod = mod;
    }

    // 重新实现update函数，用来接受Subject通知的更新信息
    void update(int v) override {
        cout << v << " mod " << m_mod << " is " << v%m_mod << '\n';
    }
};

int main() {
    //-------------------------------------
    // 用法1，管理方式不同，有很多种实现方法
    //-------------------------------------
    cout << "method 1:\n";
    Subject subj;
    DivObserver divObs1(&subj, 4);
    DivObserver divObs2(&subj, 3);
    ModObserver modObs3(&subj, 3);
    subj.set_val(14);

    //-------------------------------------
    // 用法2
    //-------------------------------------
    cout << "method 2:\n";
    Subject subj2;
    DivObserver divObserver1(4);
    DivObserver divObserver2(3);
    ModObserver modObserver3(3);
    subj2.attach(&divObserver1);
    subj2.attach(&divObserver2);
    subj2.attach(&modObserver3);
    subj2.set_val(14);


}
