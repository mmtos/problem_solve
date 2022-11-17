#include<bits/stdc++.h>
using namespace std;

void pointerTest(){
	string a = "abcd";
	string * b = &a;
	cout << b << "\n";
	cout << *b << "\n";
}

void fn1(int idx){
	// call by value
	cout << idx << " in fn1\n";
	idx = 100;
}

void fn2(int &idx){
	// call by refer
	cout << idx << " in fn2\n";
	idx = 3;
}

void callByReferenceTest(){
	int idx = 1;
	fn1(idx);
	cout << idx << "\n";
	fn2(idx);
	cout << idx << "\n";
}


int main(){
	cout << "\n===pointerTest===\n";
	pointerTest();
	cout << "\n===callByReferenceTest===\n";
	callByReferenceTest();
	
	return 0;
}

