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
// ������ 5���̸� 1���� ���� 
vector<int> p(6,-1);

void build_graph(){
	// ������  cost a b ��  
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
	// p[x]�� ������ȣ�� ������ �ִٸ�(�� ����� ���)
	// ��������� root ������ ã�Ƽ� root��ȣ�� ������ �ְ� ����  
	return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){
	cout << "\n=====" << __func__ << "=====\n";
	cout << "input (u,v) : " << u << "," << v << "\n";
	//�̹� ������ �׷��� ��� 0 ���� 
	u = find(u); v = find(v);
	cout << "root (u,v) : " << u << "," << v << "\n";
	cout << "rank of (u,v) : " << p[u] << "," << p[v] << "\n";
	if(u == v) return 0;
	//union by rank, rank�� ������ ǥ���Ǹ� �������� ��ũ�� ����?  
	if(p[u] > p[v]) swap(u,v);
	p[u] += p[v];
	p[v] = u;
	return 1; 
	
} 

// ��� ���� �������� ���Խ�Ű�� 
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

bool chk[6]; // ������ �ּҽ���Ʈ���� ���ԵǾ��ִ��� ����
typedef pair<int,int> pii;
vector<pii> adj[6];

void build_adj_graph(){
	// cost, to ����� ?
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
	// �ּҽ���Ʈ��
	cruskal();
	frim();
	return 0;
}
