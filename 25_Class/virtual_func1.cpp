#include <iostream>
using namespace std;

class A {
    public:
    // virtual void func() {
    //     cout << "A is called!" << endl;
    // }
    virtual void func()=0;
    // 纯虚函数是不能被调用的，因为它根本就没有实现，只有声明
};

// 一个抽象类是可以继承自抽象类的
class B : public A {
    public:
    virtual void func()=0;
};

// 一个抽象类是可以继承自抽象类的，并且它可以被另一个类所继承。
class C : public B {
    public:
    void func() {cout << "C is called!" << endl;}
};

int main() {
    // 抽象类是不可以被实例化的
    // A a;
    // a.func();
    C c;
    c.func();
    return 0;
}