#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;
int TC, N;
// 메모리 이슈  
//short stikers[MAX_N][MAX_N]; // 너무 큼 
short stikers[MAX_N][2];
// memo상태정의 : 1. 열 번호 2. 해당 열에서 선택한 스티커 (2인경우 둘다 선택하지 않음)   
// 부분문제 정의 : 해당 memo상태까지 왔을때 스티커 점수 합의 최대값
int memo[MAX_N][3];
/*
1
5
100 0 100 0 40
70 0 90 0 60

*/
int main(){
	// #DP
	cin >> TC;
	for(int t=0;t<TC;t++){
		cin >> N;
		for(int j=0;j<2;j++){
			for(int k=0;k<N;k++) cin >> stikers[k][j];
		}
		// 스티커의 점수는 0보다 크거나 같으므로 memo 는 -1로 초기화 
		memset(memo,-1, sizeof(memo));
		/*
		 3가지 케이스 
		   - 첫번째 열의 위쪽 스티커를 선택   
		   - 첫번째 열의 아래쪽 스티커를 선택  
		   - 첫번째 열을 선택하지 않는 경우 
		*/
		memo[0][0] = stikers[0][0];
		memo[0][1] = stikers[0][1];
		memo[0][2] = 0;
		
		for(int i=1;i<N;i++){
			memo[i][0] = max(memo[i-1][1], memo[i-1][2]) + stikers[i][0];
			memo[i][1] = max(memo[i-1][0], memo[i-1][2]) + stikers[i][1];
			memo[i][2] = max(memo[i-1][0], max(memo[i-1][1], memo[i-1][2]));
		} 
		for(int i=0;i<N;i++){
			cout << i << ": ("<< stikers[i][0] << "," << stikers[i][1] << ")\n";
		}
		cout <<  max(memo[N-1][0], max(memo[N-1][1], memo[N-1][2])) << "\n";
		
		for(int i=0;i<N;i++){
			cout << i << ": ("<< memo[i][0] << "," << memo[i][1] << "," << memo[i][2] << ")\n";
		}
	}
	return 0;
}
