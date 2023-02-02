#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

#include <queue>

using namespace std;
typedef pair<int,int> pii;

const int MAX_N = 101;
int M, N, K, ldx, ldy, rux, ruy, ret;
int visited[MAX_N][MAX_N], graph[MAX_N][MAX_N];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void drawing(pii ld, pii ru){
	// 직사각형 색칠하기 
	for(int i=ld.first; i<ru.first; i++){
		for(int j=ld.second; j<ru.second; j++){
			cout << i << ":" << j << ",";
			graph[i][j] = 1;
		}
	}
	cout <<"\n";
}

void dfs(int x, int y){
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];	
		if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		if(visited[nx][ny] || graph[nx][ny]) continue;
		visited[nx][ny] = 1;
		ret++;
		dfs(nx,ny);
	}
}

void dfs_solution(){
	vector<int> answer; 
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j] != 0) continue;
			if(graph[i][j] == 1) continue;
			visited[i][j] = 1;
			ret++;
			dfs(i,j);
			answer.push_back(ret);
			ret = 0;
		}	
	}
	int area_count = answer.size();
	sort(answer.begin(),answer.end());
	cout << area_count << "\n";
	for(int i=0; i<area_count;i++){
		cout << answer[i];
		if(i != area_count -1) cout << " ";
	}
	cout << "\n";
} 

void bfs_solution(){
	queue<pii> q;
	vector<int> answer; 
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(visited[i][j] != 0) continue;
			if(graph[i][j] == 1) continue;
			
			q.push({i,j}); 
			visited[i][j] = 1;
			int x,y;
			while(!q.empty()){
				pii node = q.front(); q.pop(); ret++;
				tie(x,y) = node;
				for(int k=0; k<4; k++){
					int nx = x + dx[k];
					int ny = y + dy[k];	
					if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					if(visited[nx][ny] || graph[nx][ny]) continue;
					visited[nx][ny] = 1;
					q.push({nx,ny});
				}
			}
			answer.push_back(ret);
			ret = 0;
		}	
	}
	int area_count = answer.size();
	sort(answer.begin(),answer.end());
	cout << area_count << "\n";
	for(int i=0; i<area_count;i++){
		cout << answer[i];
		if(i != area_count -1) cout << " ";
	}
	cout << "\n";
} 

int main(){
	// # DFS #플러드필(연결컴포넌트) #리뷰 
	// 영역의 넓이까지 구해야함. 노드 방문할때마다 +1씩 해주기  
	// dfs, bfs 둘다 써도 될듯 ?
	cin >> N >> M >> K;
	for(int i=0; i<K; i++){
		cin >> ldx >> ldy >> rux >> ruy;
		drawing({ldx,ldy},{rux,ruy});
	}
	
	for(int j=0; j<N; j++){
		for(int i=0; i<M; i++){
			cout << graph[i][j] << ",";
		}
		cout <<"\n";
	}
	
	dfs_solution();
	
	fill(&visited[0][0], &visited[0][0] + MAX_N * MAX_N, 0);
	
	bfs_solution();
	
	return 0;
}
