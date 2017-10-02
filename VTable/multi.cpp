#include <iostream>
#include <string>
using namespace std;

class B1{
public:
	virtual void B1fun1(){
		cout << "B1::fun1" << endl;
	}
	virtual void B1fun2(){
		cout << "B1::fun2" << endl;
	}
	~B1(){};
};

class B2{
public:
	virtual void B2fun1(){
		cout << "B2::fun1" << endl;
	}
	virtual void B2fun2(){
		cout << "B2::fun2" << endl;
	}
	~B2(){};
};

class B3{
public:
	virtual void B3fun1(){
		cout << "B3::fun1" << endl;
	}
	virtual void B3fun2(){
		cout << "B3::fun2" << endl;
	}
	~B3(){}
};

class D1:public B1,public B2,public B3{
public:
	virtual void B1fun1(){cout << "D1::B1fun1" << endl;}
	virtual void B2fun1(){cout << "D1::B2fun1" << endl;}
	virtual void B3fun1(){cout << "D1::B3fun1" << endl;}
	~D1(){};
};
typedef void (*pFun)();
int main(){
	D1* d1 = new D1;
	B1* b1 = d1;
	B2* b2 = d1;
	B3* b3 = d1;
	cout << hex;
	cout << d1 << endl;
	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	d1->B1fun1();
	d1->B1fun2();
	d1->B2fun1();
	d1->B2fun2();
	d1->B3fun1();
	d1->B3fun2();
	b1->B1fun1();
	b1->B1fun2();
	b2->B2fun1();
	b2->B2fun2();
	b3->B3fun1();
	b3->B3fun2();
	delete d1;
	return 0;
}