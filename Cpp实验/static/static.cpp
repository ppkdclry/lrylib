#include <iostream>
using namespace std;

class A{
public:
	static void fun();
};

void A::fun(){
	cout << "fun" << endl;
};

int main(){
	A::fun();
	return 0;
}