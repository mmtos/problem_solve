#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e7+1, MAX_N = 102;
int n,m,a,b,c,d[MAX_N][MAX_N];

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
int main(){
	// #플로이드 
	// 인접행렬을 사용 
	cin >> n >> m;
	fill(&d[0][0],&d[0][0] + MAX_N*MAX_N, INF);
	int temp = n+1;
	while(temp--) d[temp][temp] = 0;
	while(m--){
		cin >> a >> b >> c;
		// 여러개의 간선이 있을 수 있음 
		d[a][b] = min(d[a][b],c);
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i == j || i == k || j == k) continue;
//				d[j][k] = min(d[j][k], d[j][i]+d[i][k]);
				// 상수시간 최적화 
				if(d[j][k] > d[j][i]+d[i][k]) d[j][k] = d[j][i]+d[i][k];
			}
		}
//		cout << "\n====" << i <<  "====\n" ;
//		print_d();
	}
	print_d();
	return 0; 
} 
