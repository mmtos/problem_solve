#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){
	for(int i =0 ; i < size ; i++){
		cout << arr[i] << " ";
	}	
	cout << '\n';
}


void printVector(vector<int> v){
	// vector도 call by value가 된다..?  
	for(int i : v){
		cout << i << " ";
	}
	cout << "\n";
	v[0] = 100; // 파라미터로 전달된 벡터에 변경사항 반영되지 않음  
}

void nextPermutationTest(){
	vector<int> v;
	int source[3] = {1,1,3};
	
	for(int i = 0; i < 3 ; i++) v.push_back(source[i]);
	do{
		printVector(v);
	// call by reference로 호출된다 
	}while(next_permutation(v.begin(),v.end()));
}

void prevPermutationTest(){
	vector<int> v;
	int source[3] = {1,2,3};
	for(int i = 2; i >-1 ; i--) v.push_back(source[i]);
	do{
		printVector(v);
	// call by reference로 호출된다 
	}while(prev_permutation(v.begin(),v.end()));
}

// 전제 : 순열의 대상이되는 배열의 원소가 모두 달라야함. 
void makePermutation(int a[], int n, int r, int depth){
	if(r == depth){
		printArray(a,3);
		return;
	}
	for(int i = depth; i < n; i++){
		swap(a[i], a[depth]);
		makePermutation(a, n, r, depth + 1);
		swap(a[i], a[depth]);
	}
	return;
}

void recurPermutationTest(){
	int a[3] = {1,1,3};
	makePermutation(a,3,3,0);
}

int main(){
	cout << "\n===nextPermutationTest===\n";
	nextPermutationTest();
	cout << "\n===prevPermutationTest===\n";
	prevPermutationTest();
	cout << "\n===recurPermutationTest===\n";
	recurPermutationTest();
	return 0;
}

