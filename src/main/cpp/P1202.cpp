#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;

int N,K,m,v;
vector<pair<int,int>> gems;
//pair<int,int> gems[MAX_N];

void pq_test(){
	// 기본정렬과 반대
	 
	priority_queue<int> pq;
	pq.push(100);
	pq.push(1);
	pq.push(50);
	while(pq.size() != 0){
		cout << pq.top() << ",";
		pq.pop();
	}
		
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	// #그리디 
	// 가방에는 최대 한 개의 보석만 넣을 수 있다.
	// 작은 가방으로 정렬되어 있기에 이전 가방에 들어가는 보석은 다음가방에 당연히 들어간다.
	// 작은 보석부터 넣되 제일 비싼걸 넣는다.
	// 비싼보석부터 채워 넣으면 다시 앞의 보석을 찾아야하는 경우가 생긴다. (TLE원인)  
	cin >> N >> K;
	vector<pair<int,int>> gems(N); //미리 초기화 
	for(int i=0; i<N;i++){
		// 무게, 가치  
		cin >> gems[i].first >> gems[i].second;
	}
	
	
	int bags[K];
	for(int i=0; i<K;i++){
		cin >> bags[i];
	}
	
	// 보석 정렬 
	sort(gems.begin(), gems.end());
	// 가방 정렬 
	sort(bags, bags + K);
	
	priority_queue<int> pq;
	
	ll answer = 0;
	int idx = 0;
	for(int c : bags){
		while(idx < N && gems[idx].first <= c) pq.push(gems[idx++].second);
		// 하나씩 넣기
		if(pq.size()){
			answer += pq.top(); pq.pop();
		} 
	}
	
	cout << answer << "\n";
	
//	for(pair<int,int> i : gems){
//		if(i.first != 0) cout << i.first << "," << i.second << ",";
//	}
//	cout << "\n";
//	
//	for(int i : bags){
//		if(i != 0) cout << i << "\n";
//	}
}


void TimeLimitExceed(){
	
	// #그리디 
	// 가방에는 최대 한 개의 보석만 넣을 수 있다.
	// 가격이 비싼거 먼저 넣기. 가방에 안들어가면 그다음 비싼걸로 넣기 
	// 가방은 최대무게 작은거 부터 사용하기 (fraction 최소화되도록)
	
	cin >> N >> K;
	
	for(int i=0; i<N;i++){
		cin >> m >> v;
		gems.push_back({v,m});
	}
	
	int sold_out[N+1];
	fill(sold_out, sold_out + N+1, 0);
	
	int bags[K];
	for(int i=0; i<K;i++){
		cin >> bags[i];
	}
	
	// 보석 정렬 
	sort(gems.begin(), gems.end(),greater<pair<int,int>>());
	// 가방 정렬 
	sort(bags, bags + K);
	
	ll answer = 0;
	for(int c : bags){
		int idx = 0;
		int gems_size = gems.size();
		while(sold_out[idx] == 1 || (gems[idx].second > c && idx < gems_size)) idx++;
		if(idx == gems_size) cout << "no solution" << "\n";
		answer += gems[idx].first;
		sold_out[idx] = 1;
	}
	
	cout << answer << "\n";
//	
//	for(pair<int,int> i : gems){
//		if(i.first != 0) cout << i.first << "," << i.second << ",";
//	}
//	cout << "\n";
//	
//	for(int i : bags){
//		if(i != 0) cout << i << "\n";
//	}
}
