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
	// #그리디 #리뷰 DP vs 그리디
	// 동전의 종류가 랜덤이 아니라 바로 직전 동전의 배수라는 규칙을 사용하자  
	// 그리디 규칙 : 큰것부터 채워 넣는게 최소 값이다. 
	cin >> N >> K;
	for(int i=0; i<N; i++){
		// 동전의 크기가 정렬되어 들어온다. 
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
