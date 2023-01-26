#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N, K, coin[10];
// (맞춰야할 금액의 양  , 동전의 최소개수)
map<int, int> dp2;

int solve2(int am){
	auto it = dp2.find(am);
	if(it != dp2.end()) return it -> second;
	int min_value = 1e9+1e8;
	for(int i=0; i<N; i++){
		// 음수인 금액은 제외 
		if(am < coin[i]) continue;
		min_value = min(min_value, solve2(am-coin[i]));
	}
	return dp2[am] = min_value + 1;
} 
/*
10 4200
1
5
10
50
100
500
1000
5000
10000
50000
*/
int main(){
	// #DP #리뷰 DP vs 그리디
	// Map을 써도 OOM 발생 
	dp2[0] = 0;
	dp2[1] = 1;
	
	cin >> N >> K;
	for(int i=0; i<N; i++){
		// 동전의 크기가 정렬되어 들어온다. 
		cin >> coin[i];
	}
	cout << solve2(K);
	return 0;
}
