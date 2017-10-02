#include <vector>
#include <iostream>
using namespace std;
#define N 10
#define START_ANS 'a'
#define END_ANS 'e'

class Solution;
class Question{
public:
	virtual bool isCorrect(Solutions& s);
};

class QueSolve1:public Question{
public:
	QueSolve1():issolved(false),sel('z'){
		map_indexs['a'] = 2;
		map_indexs['b'] = 3;
		map_indexs['c'] = 4;
		map_indexs['d'] = 5;
		map_indexs['e'] = 6;
	}
	bool isCorrect(Solution& s){
		if(issolved){
			char ans = sel;
			if(s.questions.size() == N){//问题规模不对则返回错误
				
			}
		}
		return false;
	};
	bool issolved;
	char sel;
	map<char,int> map_indexs;
};

class Solution{
public:
	Solution();
	vector<Question*> questions;
	void solve();
	void display();
	~Solution();
};

int main(void){
	Solution s;
	s.solve();
	s.display();
	return 0;
}