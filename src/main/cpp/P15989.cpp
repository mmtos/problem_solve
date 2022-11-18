#include<iostream>

using namespace std;
int tc, n;
int dp[10001];
int sumcase(int x){
	// ���� �ߺ����� �Ұ��� ..
	// dp ���� : idx�� ����� ���� �� ����� ��  
	if(dp[x]) return dp[x];
	// 1�� �����ϴ� ��� x-1�� ��������� ����� �� 
	// 2�� �����ϴ� ��� x-2�� ��������� ����� �� 
	// 3�� �����ϴ� ��� x-3�� ��������� ����� �� 
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
	// #DP(TOPDOWN : ��������� �ʿ��� �κи�.. , BOTTOMUP : ���������� ��� sub������ �� ǰ) 
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> tc;
	dp[0] = 1;
	// 1�� 1�� �߰��ؼ� ����� �ִ� idx -- �ݺ��� ������ ���̻� 1�� ������ �ʴ´� . 
	// 2�� 1�� �߰��ؼ� ����� �ִ� idx -- �ߺ� ����  
	// 3�� 1�� �߰��ؼ� ����� �ִ� idx 
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

