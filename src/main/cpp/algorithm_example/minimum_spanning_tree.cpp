#include <queue>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <functional>

using namespace std;
typedef tuple<int,int,int> tiii;

int v,e; 
tiii edge[7];
// 정점은 5개이며 1부터 시작 
vector<int> p(6,-1);

void build_graph(){
	// 무방향  cost a b 순  
	edge[0] = make_tuple(3,1,3);
	edge[1] = make_tuple(3,1,4);
	edge[2] = make_tuple(4,1,2);
	edge[3] = make_tuple(8,2,5);
	edge[4] = make_tuple(3,3,4);
	edge[5] = make_tuple(5,3,5);
	edge[6] = make_tuple(6,4,5);	
	sort(edge,edge+7);
}

int find(int x){
	cout << "x: "<< x << " p[x]: " << p[x] << "\n"; 
	if(p[x] < 0) return x;
	// p[x]가 정점번호를 가지고 있다면(즉 양수인 경우)
	// 재귀적으로 root 정점을 찾아서 root번호를 가지고 있게 만듬  
	return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){
	cout << "\n=====" << __func__ << "=====\n";
	cout << "input (u,v) : " << u << "," << v << "\n";
	//이미 동일한 그룹인 경우 0 리턴 
	u = find(u); v = find(v);
	cout << "root (u,v) : " << u << "," << v << "\n";
	cout << "rank of (u,v) : " << p[u] << "," << p[v] << "\n";
	if(u == v) return 0;
	//union by rank, rank는 음수로 표현되며 작을수록 랭크가 높다?  
	if(p[u] > p[v]) swap(u,v);
	p[u] += p[v];
	p[v] = u;
	return 1; 
	
} 

// 비용 작은 간선부터 포함시키기 
void cruskal(){
	cout << "\n=====" << __func__ << "=====\n";
	int cnt = 0;
	build_graph();
	for(int i=0;i<7;i++){
		int cost, a, b;
		tie(cost,a,b) = edge[i];
		if(!is_diff_group(a,b)) continue;
		cout << cost << ' ' << a << ' ' << b;
		cnt++;
		if(cnt == 5-1 ) break;
	}
} 

bool chk[6]; // 정점이 최소신장트리에 포함되어있는지 여부
typedef pair<int,int> pii;
vector<pii> adj[6];

void build_adj_graph(){
	// cost, to 양방향 ?
	adj[1].push_back({4,2});
	adj[1].push_back({3,3});
	adj[1].push_back({3,4});
	adj[2].push_back({8,5});
	adj[3].push_back({3,4});
	adj[3].push_back({5,5});
	adj[4].push_back({6,5});
}
 
void frim(){
	cout << "\n=====" << __func__ << "=====\n";
	build_adj_graph();
	priority_queue<tiii,vector<tiii>,greater<tiii>> pq;
	chk[1] = 1;
	cout << 1 << "\n";
	for(pii e : adj[1]) pq.push(make_tuple(e.first, 1, e.second));
	while(!pq.empty()){
		int cost, curr, next;
		tiii next_min_edge = pq.top(); pq.pop();
		tie(cost,curr, next) = next_min_edge;
		if(chk[next]) continue;
		chk[next] = 1;
		cout << "cost: " << cost << " direction : "<< curr << "->" << next << "\n";
		for(pii e : adj[next]) pq.push(make_tuple(e.first, next, e.second));
	}
}

int main(){
	// https://blog.encrypted.gg/1024
	// 최소신장트리
	cruskal();
	frim();
	return 0;
}
