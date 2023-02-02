#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;
int N;
// memo�������� : 1. �� ��ȣ 2. �ش� �࿡�� ���ڸ� ���� �츮 (2�ΰ�� �� ���� ���� ����)   
// �κй��� ���� : �ش� memo���±��� �����ϱ� ���� ����� �� 
long long memo[MAX_N][3];
int main(){
	// #DP #����������  9465��(��ƼĿ) ������ ���, �̹� ������ ����� ���� ���ϴ� ���� 
	cin >> N;
	/* 3���� ���̽� 
	   - ���ʿ� ���� �ֱ�
	   - �����ʿ� ���ڳֱ�
	   - ���� ���� �ʱ�  
	*/
	memo[0][0] = 1;
	memo[0][1] = 1;
	memo[0][2] = 1;
	
	for(int i=1;i<N;i++){
		memo[i][0] = memo[i-1][1] % 9901 + memo[i-1][2] % 9901;
		memo[i][1] = memo[i-1][0] % 9901 + memo[i-1][2] % 9901;
		memo[i][2] = memo[i-1][0] % 9901+ memo[i-1][1] % 9901 + memo[i-1][2] % 9901;
	} 
	cout <<  (memo[N-1][0] % 9901 + memo[N-1][1] % 9901 + memo[N-1][2] % 9901) % 9901 << "\n";
	return 0;
}
