#include<iostream>
#include<queue>
#include<tuple>
 
using namespace std;

struct cmp{
	bool operator()(pair<int,int> &a, pair<int,int> &b){
		if(a.first != b.first) return a.first > b.first;
		return a.second < b.second;
	}
};

/*
7
1 6
1 7
3 2
3 1
2 4
2 5
6 1
*/
// https://chanhuiseok.github.io/posts/ds-4/ 
// algorithm 의 sort : 퀵소트 응용 -> 최악 시간복잡도 O(n^2) 
// 우선순위 큐 (heap을 사용한) : 삽입연산 최악 시간복잡도 O(log2n) 
// 결론 : 정렬을 위해서 배열을 쓰는것 보단 우선순위를 쓰는게 유리할 수도 있다.  
int main(){ 
	// #그리디 #우선순위큐 
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, deadline, reward;
	cin >> n;
	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
	for(int i=0; i<n ;i++){
		cin >> deadline >> reward;
		pq.push({deadline, reward});
	}
	
	priority_queue<int, vector<int>, greater<int>> answerq;
	
	int time = 1;
	while(pq.size()){
		int x,y;
		tie(x,y) = pq.top(); pq.pop();
		if(x >= time){
			answerq.push(y);
			time++;
		}else if(answerq.size()){
			int a = answerq.top();
			if(a < y){
				answerq.pop();
				answerq.push(y);
			}
		}
	}
	
	int answer = 0;
	while(answerq.size()){
		answer += answerq.top();answerq.pop();
	}
	cout << answer;
	return 0;
}

