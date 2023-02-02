#include <iostream>
#include <algorithm>
#include <tuple>
#include <cstring>

using namespace std;

const int MAX_N = 101;
const int MAX_K = 100001;
int stuffs[MAX_N][2];
int N,K,w,v;
// ����: 1. ��ǰ ��ȣ(��ǰ�� �� - 1) 2. ����   
// �� : �ش� �κй��������� �ִ� ��ġ  
// �κй��� : �� ���� ��ǰ, �� ���� �賶 ����  
int memo[MAX_N][MAX_K];

int main(){
	// # DP #01knapsack #���� 
	// https://www.acmicpc.net/board/view/60752
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		cin >> w >> v;
		stuffs[i][0] = w;
		stuffs[i][1] = v;
	}
	
	// ��ǰ�� i�� ���� ������, �ִ� j��ŭ ����ִٸ� 
	for (int i=1;i<=N;i++){
		for (int j=1;j<=K;j++){
			if (j>=stuffs[i][0])
				memo[i][j]=max(memo[i - 1][j], (memo[i - 1][j - stuffs[i][0]]) + stuffs[i][1]); //�̺κ�
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
