#include<cstdio>
#include<array>
#include<functional>
#include<numeric>
using namespace std;

int A,B,C;
int tt[101];

int main(){
	// #미정 #구현
	// 풀이 방향 : 분단위로 요금 계산 
	fill(tt, tt+101, 0); // in <array>
	scanf("%d %d %d", &A, &B, &C); // in <cstdio>
	int start, end;
	for(int i=0 ; i < 3; i++) {
		scanf("%d %d", &start, &end);
		for(int j=start; j<end; j++) tt[j]++;
	} 
	// in <functional>
	auto mysum = [](int a, int b){
		if(b == 1) return a + A;
		if(b == 2) return a + 2 * B;
		if(b == 3) return a + 3 * C;
		return a;
	};
	
	
	printf("%d",
	 accumulate(tt, tt+101, 0, mysum) // in <numeric>
	);
	return 0;
}
