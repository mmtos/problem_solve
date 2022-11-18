#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cout << (-1 ^ (1 << 31)) << '\n';
	cout << (1 << 31) << '\n';
	cout << ~(1 << 31) << '\n';
	cout << (1 << 30) << '\n';
	return 0;
}
