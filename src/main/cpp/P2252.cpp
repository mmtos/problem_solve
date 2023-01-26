#include <queue>
#include <vector>
#include <iostream>

using namespace std;

const int MX = 32001;
int a,b,N,M,indeg[MX];
vector<int> adj[MX];
vector<int> row_result;

int main(){
	// #위상정렬 
	cin >> N >> M; 
	for(int i=1;i<=M;i++){
		cin >> a >> b;
		adj[a].push_back(b);
		indeg[b]++;
	}
	queue<int> zero_indeg_q;
	for(int i=1;i<=N;i++){
		if(indeg[i] == 0) zero_indeg_q.push(i);
	}
	
	while(!zero_indeg_q.empty()){
		int orphan = zero_indeg_q.front(); 
		zero_indeg_q.pop();
		row_result.push_back(orphan);
		for(int next:adj[orphan]){
			indeg[next]--;
			if(!indeg[next]) zero_indeg_q.push(next);
		}
	}
	for(int i : row_result){
		cout << i << " ";
	}
	return 0;
} 
