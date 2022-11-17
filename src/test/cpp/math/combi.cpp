#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
	for(int i : v){
		cout << i << " ";
	}
	cout << "\n";
}


void combi(int a[], int start, int n, int k, vector<int> b){
	if(b.size() == k){
		printVector(b);
		return;
	}
	for(int i = start +1; i< n; i++){
		b.push_back(a[i]);
		combi(a,i,n,k,b);
		b.pop_back();
	}
}

void combinationTest(){
	vector<int> selected;
	int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5};
	combi(a,-1,5,3, selected);
}

int main(){
	cout << "\n===combinationTest===\n";
	combinationTest();
	return 0;
}

