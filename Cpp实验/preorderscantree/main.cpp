#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
using namespace std;

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int value;
	TreeNode(int val):value(val),left(NULL),right(NULL){};
};

TreeNode* CreateTreeNode(vector<int>& nums,int start,int end){
	if(start >= end)return NULL;
	int middle = start + (end - start)/2;
	TreeNode* temp = new TreeNode(nums[middle]);
	temp->left = CreateTreeNode(nums,start,middle);
	temp->right = CreateTreeNode(nums,middle+1,end);
	return temp;
}

void DeleteTrees(TreeNode* root){
	if(NULL == root)return;
	DeleteTrees(root->left);
	DeleteTrees(root->right);
	delete root;
	return;
}

void prePrintOrder(TreeNode* root){
	if(NULL == root)return;
	//利用迭代法，需要一个栈
	stack<TreeNode*> s;
	TreeNode* cur = root;
	while(!s.empty() || NULL != cur){
		if(cur){
			cout << setw(4) << cur->value;
			s.push(cur);
			cur = cur->left;
		}else{
			cur = s.top();s.pop();
			cur = cur->right;
		}
	}
	cout << endl;
}

void inPrintOrder(TreeNode* root){
	if(NULL == root)return;
	stack<TreeNode*> s;
	TreeNode* cur = root;
	while(!s.empty() || NULL != cur){
		if(cur){
			s.push(cur);
			cur = cur->left;
		}else{
			cur = s.top();s.pop();
			cout << setw(4) << cur->value;
			cur = cur->right;
		}
	}
	cout << endl;
}

void postPrintOrder(TreeNode* root){
	if(NULL == root)return;
	stack<TreeNode*> s;
	TreeNode* cur = root;
	TreeNode* pre = NULL;
	while(cur){
		s.push(cur);//上面的while判断保证栈中节点必不为NULL
		cur = cur->left;
	}
	while(!s.empty()){
		cur = s.top();s.pop();
		if(NULL != cur->right && cur->right != pre){//说明右子树没访问过
			s.push(cur);//在访问右节点前，先将此节点入栈
			cur = cur->right;
			while(cur){//保证到左子树底端
				s.push(cur);//上面的while判断保证栈中节点必不为NULL
				cur = cur->left;
			}
		}else{
			cout << setw(4) << cur->value;
			pre = cur;
		}
	}
	cout << endl;
}

void preRecursiveOrder(TreeNode* root){
	if(NULL == root)return;
	cout << setw(4) << root->value;
	preRecursiveOrder(root->left);
	preRecursiveOrder(root->right);
	return;
}

void inRecursiveOrder(TreeNode* root){
	if(NULL == root)return;
	inRecursiveOrder(root->left);
	cout << setw(4) << root->value;
	inRecursiveOrder(root->right);
	return;
}

void postRecursiveOrder(TreeNode* root){
	if(NULL == root)return;
	postRecursiveOrder(root->left);
	postRecursiveOrder(root->right);
	cout << setw(4) << root->value;
	return;
}

int main(){
	int n;
	while(cin >> n){
		if(n <= 0)continue;
		vector<int> nums(n,0);
		for(int i = 0;i < n;i++){
			nums[i] = i;
		}
		TreeNode* root = CreateTreeNode(nums,0,nums.size());
		cout << "非递归先序：" << endl; 
		prePrintOrder(root);
		cout << "递归先序：" << endl;
		preRecursiveOrder(root);
		cout << endl;
		cout << "非递归中序：" << endl;
		inPrintOrder(root);
		cout << "递归中序：" << endl;
		inRecursiveOrder(root);
		cout << endl;
		cout << "非递归后续：" << endl;
		postPrintOrder(root);
		cout << "递归后续：" << endl;
		postRecursiveOrder(root);
		cout << endl;
		DeleteTrees(root);
	}
	return 0;
}