#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int MX = 100000001;
// i : 맞춰야할 금액의 양  
// dp[i] : i를 맞추기 위한 동전의 최소 갯수
// D[i]를 가치의 합을 i로 만들 때 필요한 동전 개수의 최솟값 이라고 정의했을 때 D[i] = min(D[i-A1], D[i-A2], ... D[i-AN]) + 1이 됩니다.
// https://blog.encrypted.gg/975
int N, K, coin[10];
int dp[MX];

// (금액, 동전의 최소개수 )
map<int, int> dp2;

int solve(int am){
	// dp[1억]은 메모리 제한이 걸림 // 제한 256MB < 400MB 
	// 4억 바이트  400,000KB 400MB 
	// -1이 아니면 
	int &ret = dp[am]; 
	if(~ret) return ret;
	int min_value = 1e9+1e8;
	for(int i=0; i<N; i++){
		// 음수인 금액은 제외 
		if(am < coin[i]) continue;
		min_value = min(min_value, solve(am-coin[i]));
	}
	return ret = min_value + 1;
}

int solve2(int am){
	auto it = dp2.find(am);
	if(it != dp2.end()) return it -> second;
	int min_value = 1e9+1e8;
	for(int i=0; i<N; i++){
		// 음수인 금액은 제외 
		if(am < coin[i]) continue;
		min_value = min(min_value, solve2(am-coin[i]));
	}
	return dp2[am] = min_value + 1;
} 
/*
2 2
1
2
답 1 

2 2
1
5
답 2 
*/
int main(){
	// #DP  #OOM
	fill(dp,dp+MX,-1);
	dp[0] = 0;
	dp[1] = 1;
	dp2[0] = 0;
	dp2[1] = 1;
	
	cin >> N >> K;
	for(int i=0; i<N; i++){
		// 동전의 크기가 정렬되어 들어온다. 
		cin >> coin[i];
	}
	cout << solve2(K);
	return 0;
}
