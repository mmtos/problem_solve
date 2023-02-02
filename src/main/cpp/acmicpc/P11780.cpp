#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

const int INF = 1e7+1, MAX_N = 102;
int n,m,a,b,c,d[MAX_N][MAX_N], path[MAX_N][MAX_N];


void print_d(){
	for(int i=1; i<=n; i++){
		for(int j=1;j<=n;j++){
			// i에서 j로 가는길이 없는 경우 0을 출력. 
			if(d[i][j] == INF) cout << 0;
			else cout << d[i][j];
			cout << " ";
		}
		cout << "\n";
	}
}

void print_path(){
	deque<int> dq;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << path[i][j];
			cout << " ";
		}
		cout << "\n";
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!path[i][j] || path[i][j] == INF) cout << 0 << "\n";
			else{
				int temp = i;
				while(temp != j){
					dq.push_back(temp);
					temp = path[temp][j];
				}
				dq.push_back(j);
				cout << dq.size() << " ";
				for(int k:dq) cout << k << " ";
				dq.clear();
				cout << "\n";
			}
		}	
	}	
}

int main(){
	// #플로이드 #경로복원 
	cin >> n >> m;
	fill(&d[0][0],&d[0][0] + MAX_N*MAX_N, INF);
	int temp = n+1;
	while(temp--) d[temp][temp] = 0;
	while(m--){
		cin >> a >> b >> c;
		// 여러개의 간선이 있을 수 있음 
		d[a][b] = min(d[a][b],c);
		// a -> b로 가기위한 경로중 처음으로 거쳐가는 정점(끝 정점 포함)
		path[a][b] = b; 
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i == j || i == k || j == k) continue;
				if(d[j][k] > d[j][i]+d[i][k]){
					d[j][k] = d[j][i]+d[i][k];
//					path[j][k] = i; // 또다른 중간경로가 있을수 있기때문에 바로 i로 업데이트하면 안됨   
					path[j][k] = path[j][i];
				}
			}
		}
	}
	print_d();
	print_path();
	
	return 0; 
} 
