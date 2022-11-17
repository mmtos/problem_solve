
#include<iostream>
#include<queue>
using namespace std;

int main(){
	queue<int> q; 
	q.push(1);
	q.push(2);
	cout << q.front();
	cout << q.back();
	queue<int> copy_q;
	 
	copy_q = q;
	q.pop();
	cout << copy_q.front();
	cout << copy_q.back();
	
	return 0; 
}
