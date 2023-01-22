#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alpha[2][27];

int main(){
	// #배열 랜덤접근 
	string s;
	int c = 2;
	while(c--) {
		cin >> s;
		for(int i=0;i<s.size();i++){
			alpha[c][s[i]-'a']++;
		}
	}
	int answer = 0;
	for(int i=0;i<27;i++){
		if(alpha[0][i] != alpha[1][i]) answer += abs(alpha[0][i] - alpha[1][i]);
	}
	cout << answer;
		
}
