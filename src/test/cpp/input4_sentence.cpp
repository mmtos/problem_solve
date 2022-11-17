#include<bits/stdc++.h>
using namespace std;

void getOneLine(){
	// 예시 가나 다라 마바사 
	string s;
	
	// scanf("%s", &s); // 에러  
	// cin >> s; //가나 만 받음 
	getline(cin, s);
	cout << s << '\n';
}

void getMultipleLine(){
	/*
	2
가나 다라 마바사
아자차 카 타파하

	*/
	int lineCount;
	string s;
	
	cin >> lineCount;
	
	// 남은 개행문자 제거 
	getline(cin, s);
	
	for(int i=0; i<lineCount; i++){
		getline(cin, s);
		cout << s << '\n';
	}
}


int main(){
	/* 문장 받기 */
	//getOneLine();
	getMultipleLine();
	return 0;
	 
} 
