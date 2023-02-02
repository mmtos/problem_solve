#include<iostream>
#include<cstring> 
#include<algorithm> 
#define MAX_N 16

//int의 max값으로 할경우 더했을때 값이 마이너스로 바뀜.. 
//const int INF_COST = ~(1 << 31);

//int.maxValue / 2; 약 10억
const int INF_COST = 1 << 30;
const int travelStartTown = 0;

using namespace std;
int n, dp[MAX_N][1 << MAX_N], g[MAX_N][MAX_N];

int tsp(int currentTown, int visitedArray){
	if(visitedArray == ((1 << n) -1)){
		//모든 도시를 순회한 경우. ex) n=5 -> 10000 -1 = 1111 
		//시작한 도시로 돌아온다. 
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
		// 모든 도시를 다 가보고 최소값을 받음.  
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
	// #DP : dp의 경우 재귀함수의 리턴값이 있는 편 (부분 문제의 답을 쌓아야하므로) 
	// dp 정의 :  k개의 도시를 방문한 상태에서 현재 위치한 도시부터 시작하여 도시를 순회하는데 필요한 최소 비용  
	// #비트마스킹 k개의 도시를 방문했다는 사실을 visited라는 배열을 매번 생성해서 쓰는게 아니라 int로 저장해서 2차원 DP 배열을 만들기 위함  
	// 어떤 위치에서 시작하던지 총 순회 비용은 동일하다. (비용 합산 순서만 다를뿐) 
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

