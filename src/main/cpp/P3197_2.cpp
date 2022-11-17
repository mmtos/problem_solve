#include<iostream>
#include<queue>
#include<tuple>
#include<string>
#include<algorithm>
 
using namespace std;
const int max_nm =  1501;
int n, m, g[max_nm][max_nm], visited[max_nm][max_nm], visitedWater[max_nm][max_nm];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
pair<int,int> target;

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
	// #BFS
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
				water.push({i,j});
				visitedWater[i][j] = 1;
			}else if(s[j] == '.'){
				water.push({i,j});
				visitedWater[i][j] = 1;
			}
		}
	}
//	cout << l.front().first << "|" << l.front().second  << "\n";
//	cout << l.back().first << "|" << l.back().second  << "\n";
	target = l.back();
	int days = 0;
	queue<pair<int,int>> q;
	q.push(l.front());
	while(true){
		int x,y;
		queue<pair<int,int>> temp_q;
		while(q.size()){
			tie(x,y) = q.front(); q.pop();
			if(visited[x][y]) continue;
			visited[x][y] = 1;
			if(x == target.first && y == target.second){
				cout << days;
				return 0;	
			}
			for(int i=0; i<4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] == 1) continue;
				if( g[nx][ny] == 'X') {
					temp_q.push({nx,ny});
					continue;
				}
				q.push({nx,ny});
			}
		} 
		q = temp_q;
		
		queue<pair<int,int>> nextWater;
		while(water.size()){
			// bfs로 해야 바로직전에 얼음이 녹은곳에 다시 방문하지 않음 . 
			tie(x,y) = water.front(); water.pop();
			if(g[x][y] == 'X'){
				g[x][y] = '.';
				nextWater.push({x,y});
				continue;
			}
			for(int i=0; i<4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] == '.' || visitedWater[nx][ny] == 1) continue;
				visitedWater[nx][ny] = 1;			
				water.push({nx,ny});
			}
		}
		days++;
		water = nextWater;
	}
	return 0;
}
