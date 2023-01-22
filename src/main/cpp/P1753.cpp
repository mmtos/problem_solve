#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

#define W first
#define V second 

const int INF = 1e9, MAX_V = 20002;
int d[MAX_V], v, e, start, from, to, wei;
vector<pii> g[MAX_V];

int main(){
	// #다익스트라 
	cin >> v >> e >> start;
	while(e--){
		cin >> from >> to >> wei;
		g[from].push_back({wei,to});
	}
	fill(d,d + MAX_V, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
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
	for(int i=1;i<=v;i++){
		if(d[i] == INF) cout << "INF" << "\n";
		else cout << d[i] << "\n";
	}
	return 0;
}
