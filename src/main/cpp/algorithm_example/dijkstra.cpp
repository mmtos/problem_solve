#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>

using namespace std;
typedef pair<int,int> pii;

#define W first
#define V second 

const int INF = 1e9;
int confirmed[6], min_distance[6], pre[6];
vector<pii> graph[6];

bool all_confirmed(){
	for(int i=0; i<6; i++){
	    if(confirmed[i] == 0 ) return false;
	}
	return true;
}

void dijk_naive(int start){
	cout << "\n=====" << __func__ << "=====\n";
	min_distance[start] = 0;
	confirmed[start] = 1;
	int v, w;
	while(!all_confirmed()){
		for(int i=0; i < graph[start].size(); i++){
			tie(v,w) = graph[start][i];
			min_distance[v] = min(min_distance[v], 	min_distance[start] + w);
		}
		int min_value = INF;
		for(int i=0; i<6; i++){
			if(confirmed[i]) continue;
			min_value = min(min_value, min_distance[i]);
		}
		int next = find(min_distance , min_distance + 6, min_value) - min_distance;
		confirmed[next] = 1;
		start = next;
	}
	for(int i=0; i<6; i++){
	    cout << confirmed[i] << ", distance : " << min_distance[i] << "\n";
	}
}

void dijk_min_heap(int start){
	cout << "\n=====" << __func__ << "=====\n";
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	min_distance[start] = 0;
	pq.push({0,start});
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(cur.W != min_distance[cur.V]) continue; // 다른 정점에서 cur로 가는 경우 min값보다 클 수 있음. 
		for(int i=0; i<graph[cur.V].size();i++){
			auto next = graph[cur.V][i];
			if(min_distance[next.V] <= min_distance[cur.V] + next.W) continue;
			min_distance[next.V] = min_distance[cur.V] + next.W;
			pq.push({min_distance[next.V], next.V});
		}
	}
	for(int i=0; i<6; i++){
	    cout << i << ", distance : " << min_distance[i] << "\n";
	}
}

void dijk_with_path_building(int start){
	cout << "\n=====" << __func__ << "=====\n";
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	min_distance[start] = 0;
	pq.push({0,start});
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(cur.W != min_distance[cur.V]) continue; // 다른 정점에서 cur로 가는 경우 min값보다 클 수 있음. 
		for(int i=0; i<graph[cur.V].size();i++){
			auto next = graph[cur.V][i];
			if(min_distance[next.V] <= min_distance[cur.V] + next.W) continue;
			min_distance[next.V] = min_distance[cur.V] + next.W;
			pre[next.V] = cur.V; // 이전 노드 추가 
			pq.push({min_distance[next.V], next.V});
		}
	}
	
	for(int i=0; i<6; i++){
	    cout << i << ", distance : " << min_distance[i] << "\n";
	    cout << i << ", prev_node_in_shortest_path : " << pre[i] << "\n";
	}
}

void find_shortest_way(int from, int dest){
	deque<int> path;
	int start = dest;
	path.push_front(dest);
	while(start != from){
		path.push_front(pre[start]);
		start = pre[start]; 	
	}
	for(int i : path){
		cout << i << " -> ";
	}
	cout << "\n";
	
}

void clear_variables(){
	for(int i=0;i<6;i++) graph[i].clear();
	for(int i=0;i<6;i++) min_distance[i] = INF;
	for(int i=0;i<6;i++) pre[i] = -1;
}
void build_graph(){
	graph[0].push_back({1,3});
	graph[0].push_back({2,2});
	graph[0].push_back({3,5});
	graph[1].push_back({2,2});
	graph[1].push_back({4,8});
	graph[2].push_back({3,2});
	graph[3].push_back({4,6});
	graph[4].push_back({5,1});
}

void build_graph_weight_first(){
	graph[0].push_back({3,1});
	graph[0].push_back({2,2});
	graph[0].push_back({5,3});
	graph[1].push_back({2,2});
	graph[1].push_back({8,4});
	graph[2].push_back({2,3});
	graph[3].push_back({6,4});
	graph[4].push_back({1,5});
}

int main(){
	// #다익스트라 
	// 0번 정점 부터 다익스트라 알고리즘 시작 
	clear_variables();
	build_graph();
	dijk_naive(0); // O(V^2+E)
	
	clear_variables();
	build_graph_weight_first();
	dijk_min_heap(0); // O(ElogE)
	
	clear_variables();
	build_graph_weight_first();
	dijk_with_path_building(0); // 경로 복원을 위한 처리 추가 
	find_shortest_way(3,5);
	return 0;
}
