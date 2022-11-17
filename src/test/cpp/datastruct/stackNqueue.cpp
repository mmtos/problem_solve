#include<bits/stdc++.h>
using namespace std;

// 삽입 삭제에 O(1) 탐색에 O(n) 
//“교차하지 않고” 라는 문장이 나오면 스택을 사용할지 말지를 의심해봐야 합니다.
void stackTest(){
	stack<string> stk; 
	
	stk.push("ㄱ");
	stk.push("ㄴ");
	stk.push("ㄷ");
	stk.push("ㄹ");	
	stk.push("ㅁ");
	while(stk.size()){
		cout << stk.top() << "\n";
		stk.pop();
	} 
	
}

void queueTest(){
	queue<int> q;
	for(int i = 1; i <= 10; i++)q.push(i);
	while(q.size()){
		cout << q.front() << ' ';
		q.pop();
	}
}

// 앞 뒤로 꺼낼수 있음 
void dequeTest(){
	deque<int> dq;
	dq.push_front(1);
	dq.push_back(2);
	dq.push_back(3);
	
	cout << dq.front() << "\n";
	cout << dq.back() << "\n";
	cout << dq.size() << "\n";
	
	dq.pop_back();
	dq.pop_front();
	
	cout << dq.front() << "\n";
	cout << dq.back() << "\n";
	cout << dq.size() << "\n"; 
}

int main(){
	cout << "\n===stackTest===\n";
	stackTest();
	cout << "\n===queueTest===\n";
	queueTest();
	cout << "\n===dequeTest===\n";
	dequeTest();
	return 0;
}


