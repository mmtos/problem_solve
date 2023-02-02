#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;
int TC, N;
// �޸� �̽�  
//short stikers[MAX_N][MAX_N]; // �ʹ� ŭ 
short stikers[MAX_N][2];
// memo�������� : 1. �� ��ȣ 2. �ش� ������ ������ ��ƼĿ (2�ΰ�� �Ѵ� �������� ����)   
// �κй��� ���� : �ش� memo���±��� ������ ��ƼĿ ���� ���� �ִ밪
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
		// ��ƼĿ�� ������ 0���� ũ�ų� �����Ƿ� memo �� -1�� �ʱ�ȭ 
		memset(memo,-1, sizeof(memo));
		/*
		 3���� ���̽� 
		   - ù��° ���� ���� ��ƼĿ�� ����   
		   - ù��° ���� �Ʒ��� ��ƼĿ�� ����  
		   - ù��° ���� �������� �ʴ� ��� 
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
