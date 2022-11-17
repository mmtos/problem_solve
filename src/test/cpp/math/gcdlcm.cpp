#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(a == 0) return b;	
	//a 와 b의 최대공약수는 a를 b로 나눈 나머지 와 a 사이의 최대공약수와 같다.
	return gcd(b % a, a); 
}

int lcm(int a, int b){
	return a * b / gcd(a,b);
}

void gcdLcmTest(){
	int a = 10, b = 12;
	cout << gcd(a,b) << "\n";
	cout << lcm(a,b) << "\n";
	
}

int main(){
	cout << "\n===gcdLcmTest===\n";
	gcdLcmTest();
	return 0;
}

