#include<bits/stdc++.h>
using namespace std;

void getInputToString(){
	/*
8 4
1000
0000
0111
0000
1000
0000
0111
0000
*/

	int n, m, a[10][10];
	string s;
	cin >> n >> m;
	cout << n << m << '\n';
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			// �ƽ�Ű���� ���ڷ� ��ȯ 
			a[i][j] = s[j] - '0';
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << a[i][j];
		}
		cout << '\n';
	}
}

void getInputToInt(){
	/*
8 4
1000
0000
0111
0000
1000
0000
0111
0000
*/

	int n, m, a[10][10];
	string s;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &a[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << a[i][j];
		}
		cout << '\n';
	}
}

void getCharInput(){
	/*
2 4
LLMM
MMLL
*/
	char a[10][10];
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &a[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << a[i][j];
		}
		cout << '\n';
	}
}

int main(){
	/* �پ��ִ� ���ڳ� ���� �ޱ� */
	getCharInput();
	return 0;
}



