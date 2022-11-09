#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<char> a;
	for(int i= 'A'; i <'Z'+1; i++) {
		char c = i;
		a.push_back(c);
	}
	for(int i= 'A'; i < 'A' + 13; i++) {
		char c = i;
		a.push_back(c);
	}
	for(int i= 'a'; i <'z'+1; i++) {
		char c = i;
		a.push_back(c);
	}
	for(int i= 'a'; i <'a'+13; i++) {
		char c = i;
		a.push_back(c);
	}
	string s;
	getline(cin, s);
	for(char c : s){
		auto it = find(a.begin(),a.end(),c);
		if( it != a.end()){
			cout << *(it + 13);
		}else{
			cout << c;	
		}
	}
	return 0;
}
