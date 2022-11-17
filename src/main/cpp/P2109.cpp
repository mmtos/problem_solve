#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

int N,p,d;
int x,y;

void wrongSolve(){
	// 틀린 풀이 
	int maxD = -1;
	priority_queue<pair<int,int>> pq;
	for(int i=0; i<N ; i++){
		cin >> p >> d;
		maxD = max(maxD, d);
		pq.push({p,d * -1});
	}
	int answer = 0;
	for(int i=0; i<maxD && pq.size(); i++){
		tie(x,y) = pq.top(); pq.pop();
		cout << x << "|" << y << ", ";
		if(-y >= i){
			answer = answer + x;
		}
	}
	cout << answer;
} 

void verboseSolve(){
	cin >> N;
	if(N == 0) {
		cout << 0;
		return 0;
	}
	priority_queue<pair<int,int>> pq;
	for(int i=0; i<N; i++){
		cin >> p >> d;
		pq.push({d * -1, p});
	}
	int day = 1;
	priority_queue<int> answerq;
	while(pq.size()){
		tie(x,y) = pq.top(); pq.pop();
		
//		cout << x << "|" << y << ", ";
		if(-x >= day){
			answerq.push(-y);
			day++;
		}else if(answerq.size()) {
			int z = answerq.top();
			if(y > -z){
				answerq.pop();
				answerq.push(-y);
			}
		}
	}
	
	int answer = 0;
	while(answerq.size()){
		answer = answer - answerq.top(); answerq.pop();
	}
	cout << answer;
}
/*
7
20 1
2 1
10 3
100 2
8 2
5 20
50 10

4
30 1
20 2
50 3
90 3
*/
int main(){
	// #그리디 
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	verboseSolve();
	
	return 0;
}
