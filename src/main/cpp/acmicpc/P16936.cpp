#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llong;

void vectorFindTest(){
	vector<int> a = {1,2,3};
	auto it = find(a.begin(),a.end(),3);
	if(it == a.end()){
		cout << "not found";
	}else{
		cout << find(a.begin(),a.end(),3) - a.begin() <<"\n";
	}
	
}

void vectorCopyTest(){
	// https://terrorjang.tistory.com/85
	cout << "\n=====" << __func__ << "=====\n";
	vector<int> a = {1,2,3};
	vector<int> b,c;
	// resize 필수  
	b.resize((int)(a.size()));
	copy(a.begin(),a.end(),b.begin());
	for(int i:b) cout << i <<", ";
	cout << "\n";
	
	
	c.assign(a.begin(),a.end());
	for(int i:c) cout << i <<", ";
	cout << "\n";
}

const int MAX_N = 103;
int N;
vector<llong> scrembled, original;
int contained_to_original[MAX_N];
bool isFound = false;

void printContainedToOriginal(){
	cout << "contained_to_original ::: ";
	for(int i=0;i<N;i++){
		cout << contained_to_original[i]<<", ";
	}
	cout << "\n";
}

void printOriginal(){
	cout << "originals ::: ";
	for(int i=0;i<original.size();i++){
		cout << original[i]<<", ";
	}
	cout << "\n";
}

int findNumberInScrembled(llong target){
	cout << "target0 :" << target << "\n";
	for(int i=0; i<N; i++){
		printContainedToOriginal();
		if(contained_to_original[i]) continue;
		if(scrembled[i] == target) {
			cout << "target :" << target;
			return i;
		}
	}
	return -1;	
}
void completeOriginal(){
	cout << "size:: " << original.size()<<"\n";
	if(original.size() == N){
		isFound = true;
		return;
	}
	llong last_element = original.back();
	cout << "last_element" << last_element << "\n";
	printOriginal();
	
	llong twice = last_element * 2;
	bool isDividable = last_element % 3 == 0;
	if(isDividable){
		int index1 = findNumberInScrembled(twice);
		int index2 = findNumberInScrembled(last_element / 3);
		if(index1 != -1 && index2 != -1){
			int temp[MAX_N];
			copy(contained_to_original,contained_to_original + MAX_N, temp);
			contained_to_original[index1] = 1;
			original.push_back(scrembled[index1]);
			completeOriginal();
			if(isFound) return;
			original.pop_back();
			copy(temp,temp + MAX_N, contained_to_original);
			contained_to_original[index2] = 1;
			original.push_back(scrembled[index2]);
			completeOriginal();
			
			if(isFound) return;
			original.pop_back();
		}else if (index1 == -1 && index2 == -1){
			return;
		}else if( index1 != -1){
			contained_to_original[index1] = 1;
			original.push_back(scrembled[index1]);
			completeOriginal();
			if(isFound) return;
			original.pop_back();
		}else if( index2 != -1){
			contained_to_original[index2] = 1;
			original.push_back(scrembled[index2]);
			completeOriginal();
			if(isFound) return;
			original.pop_back();
		}
	}else{
		int index = findNumberInScrembled(twice);
		cout << "index :" << index << "\n";
		if(index == -1) return;
		contained_to_original[index] = 1;
		original.push_back(scrembled[index]);
		completeOriginal();
		if(isFound) return;
		original.pop_back();
	}
}


/*
3
2 4 8
*/
int main(){
	//# DFS? 나3곱2 
	cin >> N;
	scrembled = vector<llong>(N);
	original = vector<llong>();
	
	for(int i=0;i<N;i++){
		cin >> scrembled[i];
	}
	
	for(int i=0;i<N;i++){
		original.push_back(scrembled[i]);
		contained_to_original[i] = 1;
		cout << scrembled[i] << "\n";
		cout << "kkk:" << original.size() << "\n";
		for(int i=0;i<N;i++){
			cout << original[i]<<", ";
		}
		cout << original[i]<<"\n";
		printOriginal();
		printContainedToOriginal();
		
		// 최초에 original의 첫번째 원소가 들어 있는 상태에서 찾기 시작함 
		completeOriginal();
		if(isFound) break; 
		fill(contained_to_original,contained_to_original+MAX_N,0);
		original.pop_back();
	}
	
	printOriginal();
	return 0;
}
