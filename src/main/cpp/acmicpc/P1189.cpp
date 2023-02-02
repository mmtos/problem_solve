#include <cstdio>
using namespace std;

int R,C,K;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int graph[5][5];
int visited[5][5];

int findWay(int x, int y, int dist){
	// (R-1 , 0) => (0, C-1)
	if(x == 0 && y == (C-1) && dist == K) return 1;
	int answer = 0;
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || nx >= R || ny < 0 || ny >= C || graph[nx][ny] == 'T' || visited[nx][ny] != 0) continue;
		visited[nx][ny] = 1;
		answer += findWay(nx,ny,dist+1);
		visited[nx][ny] = 0; //초기화 
	}
	return answer;
}

int main(){
	// #브루트 # DFS 
	int trash;
	scanf("%d %d %d\n", &R,&C,&K);
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			scanf("%c",&graph[i][j]);
		}
		scanf("%c",&trash);
	}
	
	visited[R-1][0] = 1;
	printf("%d\n", findWay(R-1, 0,1));
	
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			printf("%c",graph[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
