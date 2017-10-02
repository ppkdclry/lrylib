#include <iostream>
using namespace std;

class Base{
public:
	virtual void f() {cout << "Base::f()" << endl;};
};

class Derive:public Base{
public:
	virtual void f() {cout << "Derive::f()" << endl;}
	virtual void f2() {cout << "Derive::f2()" << endl;}
};

int main()
{
	Base *pbase1 = new Derive();
	Derive * pderive1 = dynamic_cast<Derive *>(pbase1);
	pderive1->f();
	
	delete pbase1;
	return 0;
}