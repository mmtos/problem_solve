#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void printDouble(){
	double a = 1.23456789;
	cout << a << "\n"; // 1.23457
	cout.precision(7);
	cout << a << "\n"; // 1.234568
}

void printfNumber(){
	double a = 1.23456789;
	int b = 2;
	printf("%.6lf\n",a);
	printf("%02d\n",b);
}

void printfString(){
	//c_str : string ���� ������ �����ּ�.
	string s = "�����ٶ�";
	//printf("%s\n",s); 
	printf("%s\n",s.c_str()); 
}

void alphavetToNumber(){
	// a ~ z , 0 ~25
	char a = 'a';
	char z = 'z';
	cout << (int) a - 97 << "\n";
	cout << (int) a - 'a' << "\n";
	cout << (int) z - 'a' << "\n";
}

int main(){
	printDouble();
	printfNumber();
	printfString();
	alphavetToNumber();
	return 0;
}



