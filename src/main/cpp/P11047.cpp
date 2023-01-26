#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int MX = 100000001;
// i : ������� �ݾ��� ��  
// dp[i] : i�� ���߱� ���� ������ �ּ� ����
// D[i]�� ��ġ�� ���� i�� ���� �� �ʿ��� ���� ������ �ּڰ� �̶�� �������� �� D[i] = min(D[i-A1], D[i-A2], ... D[i-AN]) + 1�� �˴ϴ�.
// https://blog.encrypted.gg/975
int N, K, coin[10];
int dp[MX];

// (�ݾ�, ������ �ּҰ��� )
map<int, int> dp2;

int solve(int am){
	// dp[1��]�� �޸� ������ �ɸ� // ���� 256MB < 400MB 
	// 4�� ����Ʈ  400,000KB 400MB 
	// -1�� �ƴϸ� 
	int &ret = dp[am]; 
	if(~ret) return ret;
	int min_value = 1e9+1e8;
	for(int i=0; i<N; i++){
		// ������ �ݾ��� ���� 
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
		// ������ �ݾ��� ���� 
		if(am < coin[i]) continue;
		min_value = min(min_value, solve2(am-coin[i]));
	}
	return dp2[am] = min_value + 1;
} 
/*
2 2
1
2
�� 1 

2 2
1
5
�� 2 
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
		// ������ ũ�Ⱑ ���ĵǾ� ���´�. 
		cin >> coin[i];
	}
	cout << solve2(K);
	return 0;
}
