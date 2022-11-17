#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>

using namespace std;

int N,p,d;
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	priority_queue<pair<int,int>> pq;
	//pq.pop(); // 데이터 없는 경우 예외 발생  
	pq.push({5,3});
	pq.push({4,5});
	pq.push({4,7});
	pq.push({4,8});
	int x,y;
	while(!pq.empty()){
		tie(x,y) = pq.top();pq.pop();
		cout << x << "," << y << "\n";
	}
	
	
	priority_queue<int> pq2;
	int a = 3; 
	//a = pq2.top(); // 데이터 없는 경우 예외 발생
	cout << a;
}
