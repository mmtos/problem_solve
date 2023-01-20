#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

int N, M, graph[51][51], visited[51][51], min_value = 1e9;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

vector<pii> houses, chikens;

void close(vector<pii> selected_chikens){
	for(int i=0; i < selected_chikens.size(); i++){
		graph[selected_chikens[i].first][selected_chikens[i].second] = 0;
	}
}

void open(vector<pii> selected_chikens){
	for(int i=0;i < selected_chikens.size(); i++){
		graph[selected_chikens[i].first][selected_chikens[i].second] = 2;
	}
}

int distance(pii a, pii b){
	// abs는 <cstdlib>에 있음 
	return abs(a.first - b.first) + abs(a.second - b.second);
} 

int solution(vector<pii> selected_chikens){
	//폐업 
	close(selected_chikens);
	queue<pii> q;
	int sum = 0;
	for(pii house : houses){
		q.push(house);
		int x = house.first;
		int y = house.second;
		visited[x][y] = 1;
		while(!q.empty()){
			tie(x,y) = q.front(); q.pop();
			if(graph[x][y] == 2){
				sum += distance(house,{x,y});
				// 백트래킹 가지치기 
				if(sum > min_value){
					// 종료전 clean up 
					open(selected_chikens);
					fill(&visited[0][0],&visited[0][0]+51*51,0);
					return 1e9;
				} 
				while(!q.empty()) q.pop();
				break;
			}
			for(int i=0;i<4;i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if( nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;
				visited[nx][ny] = visited[x][y] + 1;
				q.push({nx,ny}); 
			}
		}
		fill(&visited[0][0],&visited[0][0]+51*51,0);
	} 
	// 재오픈  
	open(selected_chikens);
	
	// 백트래킹 대비 
	min_value = min(min_value, sum);
	return sum;
}

int combi(int start_index, vector<pii> selected_chikens){
	if(selected_chikens.size() == chikens.size() - M){
		for(int i=0;i < selected_chikens.size() ; i++){
			cout << selected_chikens[i].first << "," << selected_chikens[i].second << "\t"; 
		}
		cout << "\n";
		return solution(selected_chikens);
	}
	int answer = 1e9;
	for(int i = start_index; i< chikens.size(); i++){
		selected_chikens.push_back(chikens[i]);
		answer = min(answer, combi(i+1,selected_chikens));
		selected_chikens.pop_back();
	}
	return answer;
}
int main(){
	// #BFS #백트래킹 #브루트 #조합 #구현 
	// 강의 풀이는 BFS , 백트래킹 필요 없이 구현했음. 집과 모든 치킨집과의 거리를 구한뒤 최소만 취하는 방식  
	// BFS처럼 생겼지만 BFS가 아니었음. http://boj.kr/5b5feb84a65f44c19188df5fbe697fe6
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> graph[i][j];
			if(graph[i][j] == 1){
				houses.push_back({i,j});
			}else if(graph[i][j] == 2){
				chikens.push_back({i,j});
			}
		}
	}
	
	// 13개중 M개 선택..  M개만 남기고 일단 폐업시킨다. 모든 경우의 수에 대해 검사
	// 탐색 도중 이미 이전의 도시치킨거리를 넘어선다면 해당 케이스는 종료(백트래킹)
	cout << combi(0,vector<pii>()) << "\n";
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
