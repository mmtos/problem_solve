#include <iostream>
#include <algorithm>

using namespace std;

int func2_n_squre(int arr[], int N){
	// 주어진 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 있으면 1을 리턴, 그렇지 않으면 0을 리턴  
	for(int i=0; i<N ;i++){
		for(int j=0;j<N;j++){
			if(i==j) continue;
			if(arr[i] + arr[j] == 100) return 1;
		}
	}
	return 0;
}
int func2(int arr[], int N){
	// 공간을 더 써서 시간을 줄여보자
	// O(N)
	int fraq[100];
	fill(fraq,fraq+100,0);
	for(int i=0; i<N ;i++){
		fraq[arr[i]] = 1;
	}
	for(int i=0; i<50 ;i++){
		if(fraq[i] + fraq[100-i]) return 1;
	}
	return 0;
}

int main(){
	int arr[] ={1,52,48};
	cout << func2_n_squre(arr,3) << "\n";
	cout << func2(arr,3) << "\n";
	return 0;
} 
