#include <iostream>
#include <vector>
using namespace std;

class Base {
public:
	Base() { cout << "Base() called." << endl; }
	virtual ~Base() { cout << "~Base() called." << endl; }
	virtual void func() { cout << "Base virtual func() is called." << endl; }
};


class Dervied : public Base {
public:
	Dervied() { cout << "Dervied() called." << endl; }
	~Dervied() { cout << "~Dervied() called." << endl; }
	void func() { cout << "Dervied func() called." << endl; }
};


int main() {
	Base *b1 = new Base();
	Dervied *d1 = new Dervied();
	delete b1;
	delete d1;

    cout << endl;
    Base b2;
    Dervied d2;

    cout << endl;
    // __vfptr指向的却是Dervied类的虚函数表
    b1 = new Dervied();
	delete b1;
	return 0;
}