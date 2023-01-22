#include <iostream>

using namespace std;

int N,X;
int main(){
	// #±¸Çö 
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> X;
	int temp;
	while(N--){
		cin >> temp;
		if(temp < X) cout << temp << " ";
	}
	
	return 0;
}
