#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;

int N,K,m,v;
vector<pair<int,int>> gems;
//pair<int,int> gems[MAX_N];

void pq_test(){
	// �⺻���İ� �ݴ�
	 
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
	// #�׸��� 
	// ���濡�� �ִ� �� ���� ������ ���� �� �ִ�.
	// ���� �������� ���ĵǾ� �ֱ⿡ ���� ���濡 ���� ������ �������濡 �翬�� ����.
	// ���� �������� �ֵ� ���� ��Ѱ� �ִ´�.
	// ��Ѻ������� ä�� ������ �ٽ� ���� ������ ã�ƾ��ϴ� ��찡 �����. (TLE����)  
	cin >> N >> K;
	vector<pair<int,int>> gems(N); //�̸� �ʱ�ȭ 
	for(int i=0; i<N;i++){
		// ����, ��ġ  
		cin >> gems[i].first >> gems[i].second;
	}
	
	
	int bags[K];
	for(int i=0; i<K;i++){
		cin >> bags[i];
	}
	
	// ���� ���� 
	sort(gems.begin(), gems.end());
	// ���� ���� 
	sort(bags, bags + K);
	
	priority_queue<int> pq;
	
	ll answer = 0;
	int idx = 0;
	for(int c : bags){
		while(idx < N && gems[idx].first <= c) pq.push(gems[idx++].second);
		// �ϳ��� �ֱ�
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
	
	// #�׸��� 
	// ���濡�� �ִ� �� ���� ������ ���� �� �ִ�.
	// ������ ��Ѱ� ���� �ֱ�. ���濡 �ȵ��� �״��� ��Ѱɷ� �ֱ� 
	// ������ �ִ빫�� ������ ���� ����ϱ� (fraction �ּ�ȭ�ǵ���)
	
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
	
	// ���� ���� 
	sort(gems.begin(), gems.end(),greater<pair<int,int>>());
	// ���� ���� 
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
