#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

#define W first
#define V second 

const int INF = 1e9 + 10, MAX_N = 1002;
int d_matrix[MAX_N][MAX_N];
int N, M, X, from, to, wei;
vector<pii> g[MAX_N];

void dijk(int start){
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int* d = d_matrix[start]; 
	d[start] = 0;
	pq.push({d[start],start});
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(d[cur.V] != cur.W) continue;
		for(auto nxt : g[cur.V]){
			if(d[nxt.V] <= d[cur.V] + nxt.W) continue;
			d[nxt.V] = d[cur.V] + nxt.W;
			pq.push({d[nxt.V],nxt.V});
		}
	}
}
int main(){
	// #다익스트라 
	cin >> N >> M >> X;
	while(M--){
		cin >> from >> to >> wei;
		g[from].push_back({wei,to});
	}
	fill(&d_matrix[0][0],&d_matrix[0][0] + MAX_N * MAX_N, INF);
	for(int start=1; start<=N;start++){
		dijk(start);
	}
	int max_value = -1e9;
	for(int i=1;i<=N;i++){
		max_value = max(max_value,d_matrix[i][X] + d_matrix[X][i]);
	}
	cout << max_value;
	return 0;
}
