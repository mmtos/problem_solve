#include<iostream>
#include<string>

using namespace std;
const int max_nm = 102;
int n, m;
int g[max_nm][max_nm],visited[max_nm][max_nm];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};

void dfs(int x, int y, int level){
	if(x < 0 || y < 0 || x >= n || y >= m || g[x][y] == 0 ) return;
	visited[x][y] = level;
	for(int i=0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] == 0 || visited[nx][ny] != 0){
			continue;
		}
		visited[nx][ny] = visited[x][y] + 1;
		dfs(nx,ny,level + 1);
	}
}

/*
7 7
1011111
1110001
1000001
1000001
1000001
1000001
1111111
*/
int main(){
	// #DFS 실패 
	// 구현방법1 돌다리도 두들겨 보고 가는 방법
	// https://blog.naver.com/jhc9639/222289089015
	// 도착지점까지 갈수 있는 최소의 칸수를 구해야 하는데,
	// DFS로 한 경우 어떤 경로를 먼저 선택하느냐에 따라 최소가 아닌 칸수가 나올 수 있다    
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j=0; j<m; j++){
			g[i][j] = s[j] - '0';
		}	
	}
	dfs(0,0,1);
	cout << visited[n-1][m-1];
	return 0;
}
