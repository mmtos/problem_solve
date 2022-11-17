#include <bits/stdc++.h>
using namespace std;
int ret = 1;

void printGlobalRet(){
	cout << ret << "\n";
	return;
}

void printDoubleValue(double value){
	cout << value << "\n";
	return;
}
void printStringValue(string value){
	cout << value << "\n";
	return;
}

double rtnDouble(){
	return 1.2333;
}

string rtnString(){
	//char s[6] = "abcdef";
	string s = "abcdef";
	cout << s.size() << "\n";
	
	//문자열은 각각의 문자요소를 a[0], a[1]... 배열처럼 접근할 수 있습니다
	char s1 = s[1];
	char s2 = s[1] + 1;
	cout << s1 << "\n";
	
	// 타입이 확정되지 않음 
	cout << s1 + 1 << "\n";
	
	// 문자 변수는 C++ 또는 C에서는 해당 문자 자체가 아닌 아스키(ASCII) 값(0에서 127 사이의 정수)으로 저장되어 구현됩니다.
	cout << s2 << "\n";
	return s;
}

// 함수를 선언할 때는 항상 호출되는 위쪽 부분에 선언을 해야 합니다
int main(){
	cout << ret << "\n";
	double ret = rtnDouble();
	printDoubleValue(ret);
	printGlobalRet();
	
	string retString = rtnString();
	printStringValue(retString);
	cout << retString << "\n";
	
	return 0;
}
