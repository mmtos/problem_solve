#include <iostream>
#include <algorithm>
#include <tuple>
#include <cstring>

using namespace std;

const int MAX_N = 101;
const int MAX_K = 100001;
int stuffs[MAX_N][2];
int N,K,w,v;
// 상태: 1. 물품 번호(물품의 수 - 1) 2. 무게   
// 값 : 해당 부분문제에서의 최대 가치  
// 부분문제 : 더 적은 물품, 더 적은 배낭 무게  
int memo[MAX_N][MAX_K];

int main(){
	// # DP #01knapsack #답지 
	// https://www.acmicpc.net/board/view/60752
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		cin >> w >> v;
		stuffs[i][0] = w;
		stuffs[i][1] = v;
	}
	
	// 물품이 i개 까지 있을때, 최대 j만큼 들수있다면 
	for (int i=1;i<=N;i++){
		for (int j=1;j<=K;j++){
			if (j>=stuffs[i][0])
				memo[i][j]=max(memo[i - 1][j], (memo[i - 1][j - stuffs[i][0]]) + stuffs[i][1]); //이부분
			else
				memo[i][j] = memo[i - 1][j];
		}
	}
	
	cout << memo[N][K] << "\n";
	
//	for(int i=0;i<N;i++){
//		for(int j=0;j<=K;j++){
//			cout << memo[i][j] << ",";
//		}
//		cout << "\n";
//	}
//	for(int i=0;i<N;i++){
//		cout << i << ": ("<< stuffs[i][0] << "," << stuffs[i][1] << ")\n";
//	}
	return 0;
}
