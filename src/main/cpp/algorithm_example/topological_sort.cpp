#include <queue>
#include <vector>
#include <iostream>

using namespace std;

const int NODE_SIZE = 7;
vector<int> adj[NODE_SIZE];
int indeg[NODE_SIZE], rst[NODE_SIZE];
int top = -1;

void build_graph(){
	adj[0].push_back(1);
	indeg[1]++;
	adj[2].push_back(1);
	indeg[1]++;
	adj[2].push_back(3);
	indeg[3]++;
	adj[3].push_back(1);
	indeg[1]++;
	adj[3].push_back(4);
	indeg[4]++;
	adj[4].push_back(5);
	indeg[5]++;
	adj[6].push_back(5);
	indeg[5]++;
}
 
int main(){
	// https://blog.encrypted.gg/1020
	// 위상정렬 ( 사이클이 없어야함 )  
	// 방향 그래프의 선후관계를 지키면서 그래프 내 정점들을 나열 하는 방법
	build_graph();
	queue<int> zero_indeg_q;
	for(int i=0;i<NODE_SIZE;i++){
		if(indeg[i] == 0) zero_indeg_q.push(i);
	}
	
	while(!zero_indeg_q.empty()){
		int orphan = zero_indeg_q.front(); 
		zero_indeg_q.pop();
		rst[++top] = orphan;
		for(int next:adj[orphan]){
			indeg[next]--;
			if(!indeg[next]) zero_indeg_q.push(next);
		}
	}
	 
	for(int i=0;i<NODE_SIZE;i++) cout << rst[i] << " ";
	return 0;
} 
