#include <string>
#include <iostream>
using namespace std;

int n, evil[10001];
 
int main(){
	// #완탐 #브루트
	// 최대 666만개 해볼만 하다. -> 오래걸림 
	cin >> n; 
	int index = 1; 
	int count = 1;
	string temp;
	while(index < 10001){
		count++;
		temp = to_string(count);
		if(temp.find("666") != string::npos)
			evil[index++] = count;
	}	 
	cout << evil[n];
	return 0;
}

