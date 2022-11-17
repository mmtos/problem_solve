#include<iostream>
#include<string>
#include<queue>
#include<tuple>
#include<algorithm>

using namespace std;
const int max_nm = 102;
int n, m;
int y, x;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};

void printMatrix(int *dArr, size_t rows, size_t cols){
	for(int i= 0 ; i < rows ;i++) {
		for(int j= 0 ; j < cols ;j++) {
			cout << *(dArr + i*rows + j) << ",";
		}
		cout << "\n";
	} 
}

/*
4 6
101111
101010
101011
111011 
*/
int main(){
	// #BFS 
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	int a[n][m];
	int visited[n][m];
	fill(&a[0][0],&a[0][0] + n*m,0);
	fill(&visited[0][0],&visited[0][0] + n*m,0);
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j=0; j<m; j++){
			a[i][j] = s[j] - '0';
		}	
	}
	queue<pair<int,int>> q; 
	visited[0][0] = 1;
	q.push({0,0});
	while(q.size()){
		tie(x,y) = q.front(); q.pop();
		for(int i=0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == 0 || visited[nx][ny] != 0){
				continue;
			}
			visited[nx][ny] = visited[x][y] + 1;
			q.push({nx,ny}); 
		}
	}
	cout << visited[n-1][m-1];
	return 0;
}
