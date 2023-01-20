#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;
int N;
// memo상태정의 : 1. 행 번호 2. 해당 행에서 사자를 넣은 우리 (2인경우 두 곳다 넣지 않음)   
// 부분문제 정의 : 해당 memo상태까지 도달하기 위한 경우의 수 
long long memo[MAX_N][3];
int main(){
	// #DP #나머지연산  9465번(스티커) 문제와 비슷, 이번 문제는 경우의 수를 구하는 문제 
	cin >> N;
	/* 3가지 케이스 
	   - 왼쪽에 사자 넣기
	   - 오른쪽에 사자넣기
	   - 사자 넣지 않기  
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
