#include<cstdio>
#include<array>
#include<functional>
#include<numeric>
using namespace std;

int A,B,C;
int tt[101];

int main(){
	// #���� #����
	// Ǯ�� ���� : �д����� ��� ��� 
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
