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
	
	//���ڿ��� ������ ���ڿ�Ҹ� a[0], a[1]... �迭ó�� ������ �� �ֽ��ϴ�
	char s1 = s[1];
	char s2 = s[1] + 1;
	cout << s1 << "\n";
	
	// Ÿ���� Ȯ������ ���� 
	cout << s1 + 1 << "\n";
	
	// ���� ������ C++ �Ǵ� C������ �ش� ���� ��ü�� �ƴ� �ƽ�Ű(ASCII) ��(0���� 127 ������ ����)���� ����Ǿ� �����˴ϴ�.
	cout << s2 << "\n";
	return s;
}

// �Լ��� ������ ���� �׻� ȣ��Ǵ� ���� �κп� ������ �ؾ� �մϴ�
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
