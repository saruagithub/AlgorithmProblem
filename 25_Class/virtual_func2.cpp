#include <iostream>
using namespace std;

class A {
    public: 
    int a;
};

class B : public A {
    public: 
    int b;
};

class C : public A {
    public: 
    int c;
};

// 菱形继承
class D : public B, public C {
    public:
    int d;
};

int main() {
    D d;
    //  member found by ambiguous name lookup (a)
    //d.a = 5;
    // cout << d.a << endl;

    // 经过指定类访问到爷类（基类的基类）的成员方法
    d.B::a = 5;
	cout << d.B::a << endl;

    // 经过B访问的a和经过C访问的a，它们，是一个a吗？ no addr is different
    cout << &d.B::a << endl;
	cout << &d.C::a << endl;
    return 0;
}