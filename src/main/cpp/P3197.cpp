#include<iostream>
#include<queue>
#include<tuple>
#include<string>
#include<algorithm>
 
using namespace std;
const int max_nm =  1501;
int n, m, g[max_nm][max_nm], visited[max_nm][max_nm];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
pair<int,int> target;
 
int dfs(int x, int y){
	if(x == target.first && y == target.second) return 1;
	
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m 
		|| g[nx][ny] == 'X' || visited[nx][ny] == 1 ) continue;
		visited[nx][ny] = 1;
		return dfs(nx,ny);
	}
	return 0;
}

/*
10 2
.L
..
XX
XX
XX
XX
XX
XX
..
.L
*/
int main(){
	// #BFS : 얼음깨기 #DFS : 백조 연결 여부 확인
	// Fail: DFS에서 오래걸리는 걸로 보임 ..  
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	queue<pair<int,int>> l; 
	queue<pair<int,int>> water; 
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j=0; j<m; j++){
			g[i][j] = s[j];
			if(s[j] == 'L'){
				l.push({i,j});
			}else if(s[j] == '.'){
				water.push({i,j});
			}
		}
	}
	//cout << l.front().first << "|" << l.front().second  << "\n";
	//cout << l.back().first << "|" << l.back().second  << "\n";
	target = l.back();
	int days = 0;
	while(true){
		fill(&visited[0][0], &visited[0][0] + max_nm * max_nm, 0); 
		int x,y;
		tie(x,y) = l.front();
		visited[x][y] = 1;
		if(dfs(x,y)){
			cout << days;
			return 0;	
		}
		fill(&visited[0][0], &visited[0][0] + max_nm * max_nm, 0); 
		queue<pair<int,int>> nextWater;
		while(water.size()){
			// bfs로 해야 얼음 빠진곳에 다시 방문하지 않음 . 
			tie(x,y) = water.front(); water.pop();
			if(visited[x][y]) continue;
			visited[x][y] = 1;
			if(g[x][y] == 'X'){
				g[x][y] = '.';
				nextWater.push({x,y});
				continue;
			}
			for(int i=0; i<4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] == 1) continue;			
				water.push({nx,ny});
			}
		}
		days++;
		water = nextWater;
	}
	return 0;
}
