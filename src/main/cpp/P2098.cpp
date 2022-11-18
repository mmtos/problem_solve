#include<iostream>
#include<cstring> 
#include<algorithm> 
#define MAX_N 16

//int�� max������ �Ұ�� �������� ���� ���̳ʽ��� �ٲ�.. 
//const int INF_COST = ~(1 << 31);

//int.maxValue / 2; �� 10��
const int INF_COST = 1 << 30;
const int travelStartTown = 0;

using namespace std;
int n, dp[MAX_N][1 << MAX_N], g[MAX_N][MAX_N];

int tsp(int currentTown, int visitedArray){
	if(visitedArray == ((1 << n) -1)){
		//��� ���ø� ��ȸ�� ���. ex) n=5 -> 10000 -1 = 1111 
		//������ ���÷� ���ƿ´�. 
		return g[currentTown][travelStartTown] ? 
				g[currentTown][travelStartTown] 
				: INF_COST;  
	}
	int returnVal = dp[currentTown][visitedArray];
	if(~returnVal) return returnVal;
	returnVal = INF_COST;
	for(int i=0; i<n; i++){
		if(visitedArray & (1 << i)) continue;
		if(!g[currentTown][i]) continue;
		// ��� ���ø� �� ������ �ּҰ��� ����.  
		returnVal = min(returnVal, tsp(i, visitedArray | (1 << i)) + g[currentTown][i]);
	}
	dp[currentTown][visitedArray] = returnVal;
	return returnVal;
}
/*
4
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0
*/
int main(){
	// #TSP 
	// #DP : dp�� ��� ����Լ��� ���ϰ��� �ִ� �� (�κ� ������ ���� �׾ƾ��ϹǷ�) 
	// dp ���� :  k���� ���ø� �湮�� ���¿��� ���� ��ġ�� ���ú��� �����Ͽ� ���ø� ��ȸ�ϴµ� �ʿ��� �ּ� ���  
	// #��Ʈ����ŷ k���� ���ø� �湮�ߴٴ� ����� visited��� �迭�� �Ź� �����ؼ� ���°� �ƴ϶� int�� �����ؼ� 2���� DP �迭�� ����� ����  
	// � ��ġ���� �����ϴ��� �� ��ȸ ����� �����ϴ�. (��� �ջ� ������ �ٸ���) 
		//0-1-3-2-0
	 	//1-3-2-0-1
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> g[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	int answer = tsp(travelStartTown, 1 << travelStartTown);
	cout << answer; 
	return 0;
}

