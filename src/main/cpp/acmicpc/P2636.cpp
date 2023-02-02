#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <string>

using namespace std;
typedef pair<int,int> pii;

const int MAX_N = 101;
int R,C,r,c, graph[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

queue<pii> cz;

bool cz_exist(){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(graph[i][j] != 0) return true;
		}
	}	
	return false;
}

int main(){
	// #BFS 
	cin >> R >> C;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> graph[i][j];
		}
	}
	queue<pii> q;
	q.push({0,0});
	visited[0][0]=1;
	while(!q.empty()){
		tie(r,c) = q.front(); q.pop();
		for(int i=0; i<4; i++){
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr >= R || nr < 0 || nc >=C || nc < 0 || visited[nr][nc]) continue;
			visited[nr][nc] = visited[r][c] + 1;
			if( graph[nr][nc] == 1 ){
				cz.push({nr,nc});
				// 치즈를 만나면 더이상 탐색하지 않는다. 
				continue;
			}
			q.push({nr,nc});
		}
	}
	int remaining = cz.size();
	int melt_time = 0;
	while(cz_exist()){
		queue<pii> next_cz;
		while(!cz.empty()){
			tie(r,c) = cz.front(); cz.pop();
			// 이전에 방문처리 했으므로 0으로 바뀌어도 재방문 안함  
			graph[r][c] = 0;
			for(int i=0; i<4; i++){
				int nr = r + dr[i];
				int nc = c + dc[i];
				if(nr >= R || nr < 0 || nc >=C || nc < 0 || visited[nr][nc]) continue;
				visited[nr][nc] = visited[r][c] + 1;
				if( graph[nr][nc] == 1 ){
					next_cz.push({nr,nc});
					// 다음에 녹을 치즈를 만나면 더이상 탐색하지 않는다. 
					continue;
				}
				cz.push({nr,nc});
			}
		}
		if(next_cz.size() != 0){
			remaining = next_cz.size();
		}
		cz = next_cz;
		melt_time++;
	}
	
	cout << melt_time << "\n";
	cout << remaining << "\n";
	
	return 0; 
}
