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
	// abs�� <cstdlib>�� ���� 
	return abs(a.first - b.first) + abs(a.second - b.second);
} 

int solution(vector<pii> selected_chikens){
	//��� 
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
				// ��Ʈ��ŷ ����ġ�� 
				if(sum > min_value){
					// ������ clean up 
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
	// �����  
	open(selected_chikens);
	
	// ��Ʈ��ŷ ��� 
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
	// #BFS #��Ʈ��ŷ #���Ʈ #���� #���� 
	// ���� Ǯ�̴� BFS , ��Ʈ��ŷ �ʿ� ���� ��������. ���� ��� ġŲ������ �Ÿ��� ���ѵ� �ּҸ� ���ϴ� ���  
	// BFSó�� �������� BFS�� �ƴϾ���. http://boj.kr/5b5feb84a65f44c19188df5fbe697fe6
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
	
	// 13���� M�� ����..  M���� ����� �ϴ� �����Ų��. ��� ����� ���� ���� �˻�
	// Ž�� ���� �̹� ������ ����ġŲ�Ÿ��� �Ѿ�ٸ� �ش� ���̽��� ����(��Ʈ��ŷ)
	cout << combi(0,vector<pii>()) << "\n";
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
