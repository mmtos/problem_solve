#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N, K, coin[10];
// (������� �ݾ��� ��  , ������ �ּҰ���)
map<int, int> dp2;

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
	// #DP #���� DP vs �׸���
	// Map�� �ᵵ OOM �߻� 
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
