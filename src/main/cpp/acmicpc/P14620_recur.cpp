#include<iostream>
#include<algorithm>
using namespace std;
const int max_n = 11;
int n, g[max_n][max_n], visited[max_n][max_n];
int flower = 3;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int minValue;

int calculateSum(){
	int sum = 0;
	for(int i=0;i<max_n; i++){
		for(int j=0;j<max_n; j++){
			if(visited[i][j]) sum += g[i][j];
		}
	}
	return sum;
}

bool isVisited(int x, int y){
	if(visited[x][y]) return 0;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if(visited[nx][ny]) return 0;
	}
	return 1;
}

void memoVisited(int x, int y){
	visited[x][y] = 1;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		visited[nx][ny] = 1;
	}
}

void resetVisited(int x, int y){
	visited[x][y] = 0;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		visited[nx][ny] = 0;
	}
}

bool isConflict(int x, int y){
	if(visited[x][y]) return 1;
	
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if(visited[nx][ny] ) return 1;
	}
	return 0;
}

void recurForBrute(int x, int y, int cnt){
	if(x < 0 || y < 0 || x >= n || y >= n) return;
	if(cnt == flower){
		minValue = min(minValue,calculateSum());
		return;
	}
	for(int i=1; i< n-1 ; i++){
		for(int j=1; j< n-1 ; j++){
			if(isConflict(i,j)) continue;
			memoVisited(i,j);
			recurForBrute(i,j,cnt+1);
			resetVisited(i,j);
		}
	}
}

/*
¸ÊÀÇ Å©±â, ²ÉÀÇ °³¼ö 
6 3 
1 0 2 3 3 4
1 1 1 1 1 1
0 0 1 1 1 1
3 9 9 0 1 99
9 11 3 1 0 3
12 3 0 0 0 1



6
1 0 2 3 3 4
1 1 1 1 1 1
0 0 1 1 1 1
3 9 9 0 1 99
9 11 3 1 0 3
12 3 0 0 0 1
*/
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//	cin >> n >> flower;
	cin >> n ;
	for(int i=0; i<n; i++){		
		for(int j=0; j<n; j++){
			cin >> g[i][j]; 
		}
	}
	minValue = 200 * flower * 5 + 1;
	recurForBrute(1,1,0);
	cout << minValue;
	
	return 0;
}

