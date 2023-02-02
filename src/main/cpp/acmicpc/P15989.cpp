#include<iostream>

using namespace std;
int tc, n;
int dp[10001];
int sumcase(int x){
	// 실패 중복제거 불가능 ..
	// dp 정의 : idx를 만들기 위한 총 경우의 수  
	if(dp[x]) return dp[x];
	// 1로 시작하는 경우 x-1을 만들기위한 경우의 수 
	// 2로 시작하는 경우 x-2을 만들기위한 경우의 수 
	// 3로 시작하는 경우 x-3을 만들기위한 경우의 수 
	int answer = sumcase(x-1) + sumcase(x-2) + sumcase(x-3); 
	dp[x] = answer; 
	return answer;
}

void wrong(){
	cin >> tc;
	for(int i=0; i<tc; i++){
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		// 2 2
		cin >> n;
		cout << sumcase(n) << "\n";
	}
}

int main(){
	// #DP(TOPDOWN : 재귀적으로 필요한 부분만.. , BOTTOMUP : 순서에따라 모든 sub문제를 다 품) 
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> tc;
	dp[0] = 1;
	// 1을 1개 추가해서 만들수 있는 idx -- 반복이 끝나면 더이상 1을 더하지 않는다 . 
	// 2를 1개 추가해서 만들수 있는 idx -- 중복 제거  
	// 3를 1개 추가해서 만들수 있는 idx 
	for(int digit=1; digit <=3; digit++){
		for(int i=1; i<10001; i++){
			if(i >= digit) dp[i] += dp[i-digit]; 
		}
	}
	for(int i=0; i<tc; i++){
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}

