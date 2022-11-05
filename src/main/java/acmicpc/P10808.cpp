#include<iostream>
#include<string>

using namespace std;

const int N = 'z'+1;
int wd[N];
 
int main(){
	// #미정 #구현
	fill(wd, wd + N, 0);
	string input;
	cin >> input;
	
	for(int i = 0 ; i < input.length() ; i++) wd[input.at(i)]++;
	for(int i = 'a' ; i < N ; i++) cout << wd[i] << ' ';
	
	return 0;
}
