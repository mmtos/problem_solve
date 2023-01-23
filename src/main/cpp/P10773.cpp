#include<stack>
#include<iostream>

using namespace std;
int K;
int main(){
	// #Ω∫≈√ 
	stack<int> stk;
	cin >> K; 
	int next;
	while(K--){
		cin >> next;
		if(next) stk.push(next);
		else stk.pop();
	}
	int sum = 0;
	while(!stk.empty()) {
		sum += stk.top(); stk.pop();
	}
	cout << sum;
	return 0;
}

