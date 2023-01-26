#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 11;
int TC, N, dp[MX];
int main(){
	// #DP
	// 더하는 순서가 다르면 다른 케이스임.  
	cin >> TC;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while(TC--){
		cin >> N;
		for(int i=4; i<=N; i++){
			if(dp[i]) continue;
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		}
		cout << dp[N] << "\n";
	}
	return 0;
} 
