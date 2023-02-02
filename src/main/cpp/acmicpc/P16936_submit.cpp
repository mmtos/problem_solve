#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llong;

const int MAX_N = 103;
int N;
vector<llong> scrembled, original;
int contained_to_original[MAX_N];
bool isFound = false;

int findNumberInScrembled(llong target){
	for(int i=0; i<N; i++){
		if(contained_to_original[i]) continue;
		if(scrembled[i] == target) return i;
	}
	return -1;	
}
void completeOriginal(){
	if(original.size() == N){
		isFound = true;
		return;
	}
	llong last_element = original.back();
	
	llong twice = last_element * 2;
	bool isDividable = last_element % 3 == 0;
	if(isDividable){
		int index1 = findNumberInScrembled(twice);
		int index2 = findNumberInScrembled(last_element / 3);
		if (index1 == -1 && index2 == -1) return;
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
		if(index == -1) return;
		contained_to_original[index] = 1;
		original.push_back(scrembled[index]);
		completeOriginal();
		if(isFound) return;
		original.pop_back();
	}
}

void printOriginal(){
	for(int i=0;i<N;i++){
		cout << original[i];
		if(i != N-1) cout << " ";
	}
}

int main(){
	// #DFS
	cin >> N;
	scrembled = vector<llong>(N);
	original = vector<llong>();
	
	for(int i=0;i<N;i++){
		cin >> scrembled[i];
	}
	
	for(int i=0;i<N;i++){
		original.push_back(scrembled[i]);
		contained_to_original[i] = 1;
		completeOriginal();
		if(isFound) break; 
		fill(contained_to_original,contained_to_original+MAX_N,0);
		original.pop_back();
	}
	
	printOriginal();
	return 0;
}
