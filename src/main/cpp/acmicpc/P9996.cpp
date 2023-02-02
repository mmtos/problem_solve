#include<string>
#include<iostream>
#include<regex>
using namespace std;

int main(){
	// #Á¤±Ô½Ä 
	string da = "DA";
	string ne = "NE";
	
	int n;
	cin >> n;
	
	string pattern;
	cin >> pattern;
	pattern.insert(pattern.find('*'),".");
	
	regex r(pattern);
	for(int i=0; i<n; i++){
		string p;
		cin >> p;
		if(regex_match(p, r) != 0) cout << da << '\n';
		else cout << ne << '\n';	
	}
	
}
