#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <deque>

using namespace std;
typedef pair<int,int> pii;

#define W first
#define V second 

const int INF = 1e9 + 10, MAX_N = 1002;
int d[MAX_N], pre[MAX_N], start, dest;
int n, m, from, to, wei;
vector<pii> g[MAX_N];

int main(){
	// #다익스트라 #경로복원
	cin >> n >> m;
	while(m--){
		cin >> from >> to >> wei;
		g[from].push_back({wei,to});
	}
	cin >> start >> dest;
	fill(d,d + MAX_N, INF);
	fill(pre,pre + MAX_N, 0);
	
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
			pre[nxt.V] = cur.V;
		}
	}
	cout << d[dest] << "\n";
	deque<int> dq;
	dq.push_front(dest);
	int temp = dest;
	while(start != temp){
		dq.push_front(pre[temp]);
		temp = pre[temp];
	}
	int cities = dq.size(); 
	cout << cities << "\n";
	for(int i=0; i<cities; i++) {
		cout << dq[i];
		if(i != cities -1) cout << " ";
	} 
	return 0;
}
