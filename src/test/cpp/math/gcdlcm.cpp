#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(a == 0) return b;	
	//a �� b�� �ִ������� a�� b�� ���� ������ �� a ������ �ִ������� ����.
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

