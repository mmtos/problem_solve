#include<bits/stdc++.h>
using namespace std;

void convert(int n, int b){
	vector<int> v;
	
	while(n > 1){
		v.push_back(n % b); // 나머지를 계속 저장  
		n /= b;
	}
	
	if(n == 1) v.push_back(1);
	reverse(v.begin(), v.end());
	for(int a : v) {
		if(a >= 10) cout << char(a + 55); // 10진법 이상인 경우 문자롤 표시  
		else cout << a;
	}
	cout << "\n";
}

void baseTest(){
	convert(7, 2);
	convert(17, 3);
	convert(200, 16);
	
}
int main(){
	cout << "\n===baseTest===\n";
	baseTest();
	return 0;
}

