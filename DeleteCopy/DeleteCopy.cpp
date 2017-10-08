#include <iostream>
using namespace std;

class Base{
public:
	Base(){cout << "Base" << endl;}
	~Base(){cout << "~Base" << endl;}
	Base(const Base& b) = delete;
	Base& operator=(const Base& b) = delete;
};

class Derived:private Base{
public:
	Derived(){cout << "Derived" << endl;}
	~Derived(){cout << "~Derived" << endl;}
	Derived(const Derived& d){cout << "const Derived&" << endl;}
	Derived& operator=(const Derived & d){cout << "Derived& operator=(const Derived&)" << endl;return *this;}
};

int main(){
	{
		Derived d;
		Derived b = d;
		Derived c;
		c = b;
	}
	return 0;
}