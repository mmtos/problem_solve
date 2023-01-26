#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

typedef tuple<int,int,int> tii;
const int MX = 10;
int N,M, g[MX][MX], answer = 1e9;
vector<tii> cctvs;

int check_dead_area_size(){
	int cnt = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(g[i][j] == 0) cnt++;
		}	
	}
	return cnt;
}
/*
4 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 2 6 0
0 0 0 0 0 0
19

4 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 6 0
0 0 2 0 0 0
14

4 6
5 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 6 0
0 0 2 0 0 0
7

4 6
0 0 0 0 0 0
0 4 0 0 0 0
0 0 0 0 6 0
0 0 2 0 0 0
10

2 2
6 6 
6 6

2 2
0 0
0 0

3 3
0 6 0
6 1 0
0 6 0

4 4
4 0 1 0
0 0 5 0
0 0 0 0
0 3 0 0
1

1 1
6

7 2
1 1
0 1
0 1
6 1
1 1
0 1
0 1

*/  
void check_right(int x,int y,int idx, int id){
	while(x < N){
		x++;
		if(g[x][y] == 6) break;
		// ��ĭ�� ���� ǥ��
		if(g[x][y] == 0) g[x][y] = 100 * idx + id;		
	}
}
void uncheck_right(int x,int y,int idx, int id){
	while(x < N){
		x++;
		if(g[x][y] == 6) break;
		if(g[x][y] == 100 * idx + id) g[x][y] = 0;	
	} 
}
void check_left(int x,int y,int idx, int id){
	while(x >= 0){
		x--;
		if(g[x][y] == 6) break;
		if(g[x][y] == 0) g[x][y] = 100 * idx + id;		
	}
}
void uncheck_left(int x,int y,int idx, int id){
	while(x >= 0){
		x--;
		if(g[x][y] == 6) break;
		if(g[x][y] == 100 * idx + id) g[x][y] = 0;	
	} 
}

void check_up(int x,int y,int idx, int id){
	while(y >= 0){
		y--;
		if(g[x][y] == 6) break;
		if(g[x][y] == 0) g[x][y] = 100 * idx + id;		
	}	
}

void uncheck_up(int x,int y,int idx, int id){
	while(y >= 0){
		y--;
		if(g[x][y] == 6) break;
		if(g[x][y] == 100 * idx + id) g[x][y] = 0;	
	}
}

void check_down(int x,int y,int idx, int id){
	while(y < M){
		y++;
		if(g[x][y] == 6) break;
		if(g[x][y] == 0) g[x][y] = 100 * idx + id;		
	}
}

void uncheck_down(int x,int y,int idx, int id){
	while(y < M){
		y++;
		if(g[x][y] == 6) break;
		if(g[x][y] == 100 * idx + id) g[x][y] = 0;	
	}  
}

void check_all_direction(int x,int y,int idx, int id){
	check_right(x,y,idx,id);
	check_left(x,y,idx,id);
	check_up(x,y,idx,id);
	check_down(x,y,idx,id);
} 

void uncheck_all_direction(int x,int y,int idx, int id){
	uncheck_right(x,y,idx,id);
	uncheck_left(x,y,idx,id);
	uncheck_up(x,y,idx,id);
	uncheck_down(x,y,idx,id);
} 

void solve(int idx){
	if(answer == 0) return;
	if(idx == cctvs.size()){
		answer = min(answer,check_dead_area_size());
		return;
	}
	tii cctv = cctvs[idx];
	int x,y,type;
	tie(x,y,type) = cctv;
	if(type == 1){
		int id = 7;
		//���� 
		check_left(x,y,idx+1,id);
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_left(x,y,idx+1,id);
		
		//���� 
		check_right(x,y,idx+1,id);
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_right(x,y,idx+1,id);
		
		//���� 
		check_up(x,y,idx+1,id);
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_up(x,y,idx+1,id);
		
		// ���� 
		check_down(x,y,idx+1,id);
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_down(x,y,idx+1,id);
		  
	}else if(type == 2){
		//������ 
		int id = 8;
		check_up(x,y,idx+1,id);
		check_down(x,y,idx+1,id);
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_up(x,y,idx+1,id);
		uncheck_down(x,y,idx+1,id);
		
		//�¿��� 
		check_left(x,y,idx+1,id);
		check_right(x,y,idx+1,id);
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_left(x,y,idx+1,id);
		uncheck_right(x,y,idx+1,id);
		
	}else if(type == 3){
		int id = 9;
		// ���
		check_up(x,y,idx+1,id);
		check_right(x,y,idx+1,id);
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_up(x,y,idx+1,id);
		uncheck_right(x,y,idx+1,id);
		
		// ����
		check_down(x,y,idx+1,id);
		check_right(x,y,idx+1,id);
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_down(x,y,idx+1,id);
		uncheck_right(x,y,idx+1,id);
		
		// ����
		check_down(x,y,idx+1,id);
		check_left(x,y,idx+1,id);
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_down(x,y,idx+1,id);
		uncheck_left(x,y,idx+1,id);
		
		// �»� 
		check_up(x,y,idx+1,id);
		check_left(x,y,idx+1,id);
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_up(x,y,idx+1,id);
		uncheck_left(x,y,idx+1,id);
		
	}else if(type == 4){
		int id = 10;
		//������ 
		check_all_direction(x,y,idx+1,id);
		uncheck_down(x,y,idx+1,id); 
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_all_direction(x,y,idx+1,id);
		
		// ������
		check_all_direction(x,y,idx+1,id);
		uncheck_left(x,y,idx+1,id); 
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_all_direction(x,y,idx+1,id);
		
		// ������
		check_all_direction(x,y,idx+1,id);
		uncheck_up(x,y,idx+1,id); 
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_all_direction(x,y,idx+1,id);
		
		// ������ 
		check_all_direction(x,y,idx+1,id);
		uncheck_right(x,y,idx+1,id); 
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_all_direction(x,y,idx+1,id);
	}else if(type == 5){
		int id = 11;
		check_all_direction(x,y,idx+1,id);
		solve(idx+1);
		if(answer == 0) return; 
		uncheck_all_direction(x,y,idx+1,id);
	}
//	else{
//		// �ǵ������� ��� �ʰ� ����. 
//	    cout << "kkk";
//	} 
}

int main(){
	//#��Ʈ��ŷ 
	// üũ�Լ��� �ε����� �߸��Ǿ����� ���Ѻ��� �迭�� ũ������ ſ�� ���� ã�� ������. 
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> g[i][j];
			if(g[i][j] != 0 && g[i][j] != 6){
				tii temp = make_tuple(i,j,g[i][j]);
				cctvs.push_back(temp);
			}
		}	
	}
	solve(0);
	cout << answer << "\n";
	return 0;
}
