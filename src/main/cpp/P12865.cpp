#include <iostream>
#include <algorithm>
#include <tuple>
#include <cstring>

using namespace std;

const int MAX_N = 101;
pair<int,int> stuffs[MAX_N];
int N,K,w,v;
// 상태: 1. 물품 번호(물품의 수) : 0(N개), 1(N-1개) .. N-1(1개) 2. 해당 물품이 배낭에 포함되었는지 여부 
// 값 : 해당 부분문제에서의 최대 가치  
int memo[MAX_N][2];


/*
4 7
7 1000
1 2000
1 1
1 1

4 7
7 3000
1 200
1 1
1 1

4 7
2 300
4 200
3 500
5 400

800 (0번 2번 물품) 

2 2
2 10
2 20

2 4 
1 2
4 1

*/

int solution(int start_stuff_num, bool is_contain, int remaining) {
	if(remaining < 0) return -1e9;
	if(start_stuff_num >= N) return 0;
	int & ret = memo[start_stuff_num][is_contain];
	if(~ret) return ret;	
	return ret = max(
	solution(start_stuff_num + 1, 0, remaining)
	, solution(start_stuff_num + 1, 1, remaining - stuffs[start_stuff_num+1].first) + stuffs[start_stuff_num+1].second
	);
	
}

int main(){
	// # DP 
	// 1. 그리디가 아닌 완탐인 이유 : 가치가 큰것부터 넣거나, 무게가 작은것 부터 넣어도 반례가 있음.  
	// 2. DP를 적용할 수 있는 이유  
	// - 더 작은 무게에 대한 sub problem이 main problem의 구조와 동일하다. 
	// - 이후의 선택이 sub problem의 답에 영향을 주지 않는다.
	// - 최대 2^100의 경우의 수가 발생한다.(시간복잡도 O(2^n) 1024^10 = 10^30 => 엄청 크다.
	
	// sub problem 재정의.. 더 적은 물품의 수 
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> w >> v;
		stuffs[i] = {w,v}; 	
	}
	// 물품의 최소가치가 1이므로 memo는 -1로 초기화
	memset(memo, -1, sizeof(memo));
	
//	memo[N-1][0] = 0;
//	memo[N-1][1] = stuffs[N-1].second;
	
	// 0번 물건이 포함된 경우 , 포함되지 않는 경우  
	cout << max(solution(0,0,K), solution(0,1,K - stuffs[0].first) + stuffs[0].second) << "\n";
	
	for(int i=0;i<=N;i++){
		cout << stuffs[i].first << "," << stuffs[i].second << "\n";
	}
	for(int i=0;i<N;i++){
			cout << i << ": ("<< memo[i][0] << "," << memo[i][1] << ")\n";
		}
	return 0;
}
