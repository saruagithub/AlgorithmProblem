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

class B : public A {
    public:
    void func() {
        cout << "B is called!" << endl;
    }
};


int main() {
    // 抽象类是不可以被实例化的
    // A a;
    // a.func();
    B b;
    b.func();
    return 0;
}