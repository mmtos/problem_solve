#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;
typedef pair<int,int> pii;

const int MAX_N = 101;
int H,W, graph[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int x,y, dx = 0, dy = 1;

queue<pii> clouds;

int main(){
	// #BFS 전체를 탐색하지 않는 BFS  
	memset(visited,-1,sizeof(visited));
	
	cin >> H >> W;
	string s;
	for(int i=0; i<H; i++){
		cin >> s;
		for(int j=0; j<W; j++){
			graph[i][j] = s[j];
			if(graph[i][j] == 'c'){
				visited[i][j] = 0;
				clouds.push({i,j});
			}
		}
	}
	while(!clouds.empty()){
		tie(x,y) = clouds.front(); clouds.pop();
		int nx = x + dx;
		int ny = y + dy;
		if(ny >= W ) continue;
		if(visited[nx][ny] == -1){
			visited[nx][ny] = visited[x][y] + 1;
		}
		clouds.push({nx,ny});
	}
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	return 0; 
}
