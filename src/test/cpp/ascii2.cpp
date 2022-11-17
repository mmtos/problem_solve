#include<iostream>
using namespace std;

int main(){
	// 'A': 65, 'a' : 97, '0' : 48, '1' : 49 
	for(short i = 0; i < 500 ; i++){
		char c = i;
		cout << i << ',' << c << '\n';
	}
	return 0;
}
