#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>

using namespace std;

const int max_nm = 51;
int tc, n, m, k, g[max_nm][max_nm], visited[max_nm][max_nm];
int bx, by; // 배추의 위치 
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(int x, int y){
	cout << x << "," << y << "\n";
	visited[x][y] = 1;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] == 0 || visited[nx][ny]) continue;
		dfs(nx,ny);	
	}
}
/*
1
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
*/
int main(){
	// #DFS 
	// 테케 여러개일때 전역변수 초기화 잘하자.. 
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> tc;
	for(int t=0; t<tc; t++){
		queue<pair<int,int>> q;
		cin >> n >> m >> k;
		fill(&visited[0][0], &visited[0][0] + max_nm*max_nm,0 );
		fill(&g[0][0], &g[0][0] + max_nm*max_nm,0 );
		for(int i=0; i<k; i++){
			cin >> bx >> by;
			g[bx][by] = 1;
			q.push({bx,by});
		}
		int answer = 0;
		while(q.size()){
			int x,y;
			tie(x,y) = q.front(); q.pop();
			if(visited[x][y]) continue;
			dfs(x,y);
			
			answer++;
		}
		cout << answer << '\n';
	}
	return 0;
}
