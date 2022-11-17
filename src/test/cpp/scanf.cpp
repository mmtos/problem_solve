#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	
	scanf("%d %d %d", &a, &b, &c);
	printf("%d %d %d\n", a, b, c);
	
	// 공백으로 끊기기때문에 문장의 경우 하나의 문자열로 받아올 수 없음. 
	// cin 사용하는게 편함  
	char d[3];
	scanf("%s", d);
	printf("%s\n", d);
	return 0;
}
