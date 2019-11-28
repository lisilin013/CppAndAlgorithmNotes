#include <iostream>
#include <vector>
using namespace std;

//---------------------------------------------
// 问题： 待定补充。。。。
//---------------------------------------------


/**
 * @brief: 最基础的组件，最原始的父类
 */
class Component {
public:
    virtual void traverse() = 0;
};


/**
 * @brief: 组件1
 */
class Primitive : public Component {
    int value;
public:
    Primitive(int val) {
        value = val;
    }
    void traverse() override {
        cout << value << "  ";
    }
};

/**
 * @brief: 组件2，混合型，使用继承和委托
 */
class Composite : public Component {
    vector<Component *> children;
    int value;
public:
    Composite(int val) {
        value = val;
    }
    void add(Component *c) {
        children.push_back(c);
    }

    // 是一种深度优先的递归
    void traverse() {
        cout << value << "  ";
        for (int i = 0; i < children.size(); i++)
            children[i]->traverse();
    }
};

class Row : public Composite {
public:
    // Two different kinds of "container" classes.  Most of the
    // "meat" is in the Composite
    Row(int val) : Composite(val) {}
    void traverse() {
        cout << "Row"; // base class.
        Composite::traverse(); // 这貌似是一个深度优先的遍历哦
    }
};

class Column : public Composite {
public:
    Column(int val) : Composite(val) {}
    void traverse() {
        cout << "Col";
        Composite::traverse();
    }
};

int main() {
    Row first(1);                 // Row1
    Column second(2);             //   |
    Column third(3);              //   +-- Col2
    Row fourth(4);                //   |     |
    Row fifth(5);                 //   |     +-- 7
    first.add(&second);           //   +-- Col3
    first.add(&third);            //   |     |
    third.add(&fourth);           //   |     +-- Row4
    third.add(&fifth);            //   |     |     |
    first.add(new Primitive(6));  //   |     |     +-- 9
    second.add(new Primitive(7)); //   |     +-- Row5
    third.add(new Primitive(8));  //   |     |     |
    fourth.add(new Primitive(9)); //   |     |     +-- 10
    fifth.add(new Primitive(10)); //   |     +-- 8
    first.traverse();             //   +-- 6
    cout << '\n';
}
