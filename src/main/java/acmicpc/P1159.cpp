#include<string>
#include<iostream>
#include<map>
using namespace std;

int main(){
	int n;
	cin >> n;
	map<string, int> m;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		m[s.substr(0,1)]++; 
	} 
	int f = 0;
	for(pair<string,int> i : m){
		if(i.second >= 5){
			cout << i.first;
			f++;
		}
	}
	if(f == 0){
		cout << "PREDAJA";
	}
	return 0;
}
