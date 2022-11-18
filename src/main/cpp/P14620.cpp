#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;
const int max_n = 11;
int n, g[max_n][max_n], visited[max_n][max_n];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

vector<pair<int,int>> v;

bool memoVisited(int x, int y){
	if(visited[x][y]) return 0;
	visited[x][y] = 1;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if(visited[nx][ny]) return 0;
		visited[nx][ny] = 1;
	}
	return 1;
}

void resetVisited(int x, int y){
	visited[x][y] = 0;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		visited[nx][ny] = 0;
	}
}

void resetVisited(){
	fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);
}

int calculateSum(int x, int y){
	int returnVal = g[x][y];
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		returnVal += g[nx][ny];
	}
	return returnVal;
}
/*
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
	cin >> n;
	for(int i=0; i<n; i++){		
		for(int j=0; j<n; j++){
			cin >> g[i][j]; 
		}
	}
	
	// 3개 점을 선택하는 조합.
	// 모든 경우에 대한 비용 계산
	for(int i=1; i< n-1 ; i++){
		for(int j=1; j< n-1 ; j++){
			v.push_back({i,j});
		}
	}
	int minValue = 200 * 15 + 1;
	for(int i=0; i< v.size() ; i++){
		for(int j=i+1; j< v.size() ; j++){
			for(int k=j+1; k< v.size() ; k++){
				pair<int,int> a = v[i];
				pair<int,int> b = v[j];
				pair<int,int> c = v[k];
				if(!memoVisited(a.first, a.second)) {
					resetVisited();
					continue;	
				}
				if(!memoVisited(b.first, b.second)) {
					resetVisited();
					continue;	
				}
				if(!memoVisited(c.first, c.second)) {
					resetVisited();
					continue;	
				}
				int sum = 0;
				sum += calculateSum(a.first, a.second);
				sum += calculateSum(b.first, b.second);
				sum += calculateSum(c.first, c.second);
				minValue = min(sum, minValue); 
				resetVisited();
			}
		}
	}
	
	cout << minValue;
	
	return 0;
}

