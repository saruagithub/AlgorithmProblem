#include <iostream>
#include <vector>
using namespace std;

class BaseA {
    public:
    BaseA() { cout << "Base A is called!" << endl; }
    //~BaseA() { cout << "Base A is destructed!" << endl; }
    virtual ~BaseA() { cout << "Base A is destructed!" << endl; }
};

class BaseB : public BaseA {
    public:
    BaseB() { cout << "Base B is called!" << endl; }
    ~BaseB() { cout << "Base B is destructed!" << endl; }
};

int main() {
    BaseA *a = new BaseB();
    delete a;
    // memory leak
    // Base A is called!
    // Base B is called!
    // Base A is destructed!

    // need virtual destructor,  把Base类的析构函数设为虚, line 9
    return 0;
}