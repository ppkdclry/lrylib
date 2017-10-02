#include <iostream>
#include <stdlib.h>
using namespace std;

class Base{
public:
	int a;
	virtual int fun(){
		memset(this,0,sizeof(*this));
		return 0;
	}
};

int main(){
	Base b;
	b.fun();
	return 0;
}