#include <iostream>
#include <memory>
using namespace std;

void Test(std::unique_ptr<int>& uni_ptr){
	cout << *uni_ptr << endl;
}

int main()
{
	unique_ptr<int> p(new int(2));
	Test(p);
	return 0;
}