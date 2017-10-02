#include <iostream>
#include <string>
using namespace std;

class B1{
public:
	virtual void B1fun1(){
		cout << "B1::fun1" << endl;
	}
	virtual void B2fun2(){
		cout << "B2::fun2" << endl;
	}
	~B1(){};
};

class D1:public B1{
public:
	virtual void B1fun1(){
		cout << "D1::fun1" << endl;
	}
	//virtual void B2fun2(){
	//	cout << "D1::fun2" << endl;
	//}
	virtual void add(int a,int b){};
	~D1(){};
};

typedef void (*pFun)();

int main(){
	B1* b1p = new B1;
	B1* d1p = new D1;
	pFun p1,p2,pd1,pd2;
	p1 = (pFun)*((int*)*(int *)(b1p));
	p2 = (pFun)*((int*)*(int *)(b1p)+1);
	pd1 = (pFun)*((int*)*(int *)(d1p));
	pd2 =  (pFun)*((int*)*(int *)(d1p)+1);
	cout << hex;
	cout << "*b1p+0" << ((int*)*(int *)(b1p)) << endl;
	cout << "*b1p+1" << ((int*)*(int *)(b1p)+1) << endl;
	cout << "*b1p+2" << ((int*)*(int *)(b1p)+2) << endl;
	cout << "*(*b1p+0)" << *((int*)*(int *)(b1p)) << endl;
	cout << "*(*b1p+1)" << *((int*)*(int *)(b1p) + 1) << endl;
	cout << "*(*b1p+2)" << *((int*)*(int *)(b1p) + 2) << endl;
	cout << "p1:" << p1 << endl;
	cout <<	"p2:" << p2 << endl;
	p1();
	p2();
	cout << "*d1p+0" << ((int*)*(int *)(d1p)) << endl;
	cout << "*d1p+1" << ((int*)*(int *)(d1p)+1) << endl;
	cout << "*d1p+2" << ((int*)*(int *)(d1p)+2) << endl;
	cout << "*d1p+3" << ((int*)*(int *)(d1p)+3) << endl;
	cout << "*(*d1p+0)" << *((int*)*(int *)(d1p)) << endl;
	cout << "*(*d1p+1)" << *((int*)*(int *)(d1p) + 1) << endl;
	cout << "*(*d1p+2)" << *((int*)*(int *)(d1p) + 2) << endl;
	cout << "*(*d1p+3)" << *((int*)*(int *)(d1p) + 3) << endl;
	cout << "pd1:" << pd1 << endl;
	cout <<	"pd2:" << pd2 << endl;
	pd1();
	pd2();
	delete b1p;
	delete d1p;
	return 0;
}