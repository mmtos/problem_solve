#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T,W, memo[1004][2][34], jadu[1004];

int solution(int idx, int tree, int cnt){
	// idx : 시간 
	// tree : 현재 위치  
	// cnt : 남은 움직임 가능 횟수 -1도 들어올 수 있게 해놓음 
	
	// 최대값을 구해야하는 문제에서 -1000,000,000을 더해버리면 의미가 없어짐 
	if(cnt < 0) return -1e9;
	if(idx == T) return cnt >= 0 ? 0 : -1e9;
	if(memo[idx][tree][cnt] != -1) return memo[idx][tree][cnt];
	// tree^1 토글  
	memo[idx][tree][cnt] = max(solution(idx+1,tree^1,cnt-1), solution(idx+1,tree,cnt)) + (tree == (jadu[idx] - 1));
	return memo[idx][tree][cnt];
	 
} 

int main(){
	// #DP-bottom up
	// 꼭 W만큼 움직이지 않아도 됨
	// W는 어떻게 처리하지? 
	
	// 비트마스킹 참고:  ~k = -(k+1)
	// 3차원 이상일때 초기화 쉽게 하기 <cstring>에 포함되어있음. 
	memset(memo,-1,sizeof(memo));
	cin >> T >> W;
	for(int i=0; i<T; i++){
		cin >> jadu[i];
	}
	cout << max(solution(0,1,W-1), solution(0,0,W));
	return 0;
}
