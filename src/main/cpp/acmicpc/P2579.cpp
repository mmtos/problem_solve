#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 301;
int N, scores[MAX_N], memo[MAX_N][2];
bool debug = false;

int solution(){
	memo[0][0] = scores[0];
	memo[1][0] = scores[1];
	memo[1][1] = scores[0] + scores[1];
	
	for(int i=2; i<N; i++){
		memo[i][0] = max(memo[i-2][0],memo[i-2][1]) + scores[i];
		memo[i][1] = memo[i-1][0] + scores[i];
	}
	return max(memo[N-1][0], memo[N-1][1]);
}

int solution2(int stair, int prev){
	//기저사례 및 종료조건 ( 전체 문제에서 가장 하위 문제까지 내려온 케이스 )  
	if(stair < 0) return -1e5;
	int& ret = memo[stair][prev];
	if(ret > 0) return ret;
	if(stair == 0 && prev == 0) return ret = scores[0]; 
	if(stair == 1 && prev == 0) return ret = scores[1]; 
	if(stair == 1 && prev == 1) return ret = scores[0] + scores[1]; 
	
	//점화식  
//	int score_prev_is_one = solution2(stair-1, 0) + scores[stair];
//	int score_prev_is_zero = max(solution2(stair-2, 0), solution2(stair-2, 1)) + scores[stair];
//	return ret = max(score_prev_is_one , score_prev_is_zero);
	if(prev == 1) return ret = solution2(stair-1, 0) + scores[stair];
	return ret = max(solution2(stair-2, 0), solution2(stair-2, 1)) + scores[stair];
}

int main(){
	// #DP #리뷰 
	// 점수는 자연수, memo  초기화 필요없음  
	// 상태정의. 1. 현재 위치한 계단 2. 바로직전 계단을 밟았는지 여부(0이면 안밟음, 1이면 밟음)
	cin >> N;
	for(int i=0; i<N; i++) cin >> scores[i];
//	cout << solution();
	
	if(debug){
		for(int i=0;i<N;i++){
			cout << i << ": ("<< memo[i][0] << "," << memo[i][1] << ")\n";
		}
	}
	
	cout << max(solution2(N-1, 0), solution2(N-1, 1)) << "\n";
	
	if(debug){
		for(int i=0;i<N;i++){
			cout << i << ": ("<< memo[i][0] << "," << memo[i][1] << ")\n";
		}
	}
	return 0;
}
