#include <iostream>
#include <vector>

using namespace std;
int N, from, to;
vector<int> adj[100001];
int parent[100001];

void dfs(int sub_root){
	for(int next: adj[sub_root]){
		if(parent[sub_root] == next) continue;
		parent[next] = sub_root;
		dfs(next);
	}	
}

int main(){
	// #Æ®¸® 
	cin >> N;
	int temp = N;
	while(--temp){
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	parent[1] = 0;
	dfs(1);
	
	for(int i=2;i<=N;i++) cout << parent[i] << "\n";
	
	return 0;
}
