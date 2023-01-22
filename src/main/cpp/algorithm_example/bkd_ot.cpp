#include <iostream>
#include <algorithm>

using namespace std;

int func2_n_squre(int arr[], int N){
	// �־��� �迭 arr���� ���� 100�� ���� �ٸ� ��ġ�� �� ���Ұ� ������ 1�� ����, �׷��� ������ 0�� ����  
	for(int i=0; i<N ;i++){
		for(int j=0;j<N;j++){
			if(i==j) continue;
			if(arr[i] + arr[j] == 100) return 1;
		}
	}
	return 0;
}
int func2(int arr[], int N){
	// ������ �� �Ἥ �ð��� �ٿ�����
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
