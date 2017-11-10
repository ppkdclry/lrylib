#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int> & arr,int start,int end){
	if(start >= end)return;
	int key = arr[start];
	int s = start,e = end;
	while(s < e){
		while(s < e && arr[--e] >= key);
		arr[s] = arr[e];
		while(s < e && arr[++s] <= key);
		arr[e] = arr[s];
	}
	arr[s] = key;
	quicksort(arr,start,s);
	quicksort(arr,s+1,end);
}

int binary_search_first(const vector<int>& arr,int key){
	if(0 == arr.size())return -1;
	int start = 0,end = arr.size();
	int middle;
	while(start < end){
		middle = start + (end - start)/2;
		if(key <= arr[middle]){
			end = middle;
		}else{
			start = middle + 1;
		}
	}
	return (key == arr[start]) ? start : -1;
}

int binary_search_last(const vector<int>& arr,int key){
	if(0 == arr.size()) return -1;
	int start = 0,end = arr.size();
	int middle;
	while(start < end){
		middle = start + (end - start)/2;
		if(key >= arr[middle]){
			start = middle + 1;
		}else{
			end = middle;
		}
	}
	return (key == arr[end - 1]) ? end - 1 : -1;
}

int main(){
	vector<int> arr = {4,2,5,3,3,3,7,8,10,9};
	quicksort(arr,0,arr.size());
	for(int i = 0;i < arr.size();i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << binary_search_first(arr,3) << endl;
	cout << binary_search_last(arr,3) << endl;
	cout << binary_search_first(arr,6) << endl;
	cout << binary_search_last(arr,6) << endl;
	return 0;
}