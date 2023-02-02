#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	string s;
	cin >> s;
	string org = s;
	reverse(s.begin(),s.end());//in <algorithm>
	if(org.compare(s) == 0 ){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
