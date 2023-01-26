#include <iostream>

using namespace std;

int N, K, coin[10];
/*
10 4200
1
5
10
50
100
500
1000
5000
10000
50000
*/
int main(){
	// #�׸��� #���� DP vs �׸���
	// ������ ������ ������ �ƴ϶� �ٷ� ���� ������ ������ ��Ģ�� �������  
	// �׸��� ��Ģ : ū�ͺ��� ä�� �ִ°� �ּ� ���̴�. 
	cin >> N >> K;
	for(int i=0; i<N; i++){
		// ������ ũ�Ⱑ ���ĵǾ� ���´�. 
		cin >> coin[i];
	}
	
	int count = 0;
	for(int i=N-1; i>=0; i--){
		while(K >= coin[i]) {
			K -= coin[i];
			count++;	
		}
		if(K == 0) break;
	}
	
	cout << count;
	return 0;
}
