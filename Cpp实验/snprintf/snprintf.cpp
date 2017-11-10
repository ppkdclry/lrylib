#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	char buff[4096];
	snprintf(buff,sizeof(buff),"%s\\%s","F:\\work\\snprintf","snprintf.cpp");
	cout << buff << endl;
	return 0;
}