#include <iostream>
#include <string>

using namespace std;

const int Q_SIZE = 10050; 
int C, head = 0, tail = 0, size = 0, a[Q_SIZE];

int size_q(){
	return tail - head;	
}

bool empty(){
	return size_q() == 0;
}

void push(int num){
	a[tail++] = num; 
}

int pop(){
	if(empty()) return -1;
	return a[head++];
}

int front(){
	if(empty()) return -1;
	return a[head];
}

int back(){
	if(empty()) return -1;
	return a[tail-1];
}

int main(){
	// #ť 
	cin >> C;
	string cmd;
	int num;
	int result;
	while(C--){
		cin >> cmd;
		if(cmd.compare("push") == 0){
			cin >> num;
			push(num); 
		}else if(cmd.compare("pop") == 0){
			result = pop();
			cout << result << "\n";
		}else if(cmd.compare("size") == 0){
			result = size_q();
			cout << result << "\n";
		}else if(cmd.compare("empty") == 0){
			result = empty();
			cout << result << "\n";
		}else if(cmd.compare("front") == 0){
			result = front();
			cout << result << "\n";
		}else if(cmd.compare("back") == 0){
			result = back();
			cout << result << "\n";
		}
	}
	return 0;
} 
