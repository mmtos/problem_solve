#include<bits/stdc++.h>
using namespace std;

void getOneLine(){
	// ���� ���� �ٶ� ���ٻ� 
	string s;
	
	// scanf("%s", &s); // ����  
	// cin >> s; //���� �� ���� 
	getline(cin, s);
	cout << s << '\n';
}

void getMultipleLine(){
	/*
	2
���� �ٶ� ���ٻ�
������ ī Ÿ����

	*/
	int lineCount;
	string s;
	
	cin >> lineCount;
	
	// ���� ���๮�� ���� 
	getline(cin, s);
	
	for(int i=0; i<lineCount; i++){
		getline(cin, s);
		cout << s << '\n';
	}
}


int main(){
	/* ���� �ޱ� */
	//getOneLine();
	getMultipleLine();
	return 0;
	 
} 
