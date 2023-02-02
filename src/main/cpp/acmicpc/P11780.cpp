#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

const int INF = 1e7+1, MAX_N = 102;
int n,m,a,b,c,d[MAX_N][MAX_N], path[MAX_N][MAX_N];


void print_d(){
	for(int i=1; i<=n; i++){
		for(int j=1;j<=n;j++){
			// i���� j�� ���±��� ���� ��� 0�� ���. 
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
	// #�÷��̵� #��κ��� 
	cin >> n >> m;
	fill(&d[0][0],&d[0][0] + MAX_N*MAX_N, INF);
	int temp = n+1;
	while(temp--) d[temp][temp] = 0;
	while(m--){
		cin >> a >> b >> c;
		// �������� ������ ���� �� ���� 
		d[a][b] = min(d[a][b],c);
		// a -> b�� �������� ����� ó������ ���İ��� ����(�� ���� ����)
		path[a][b] = b; 
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i == j || i == k || j == k) continue;
				if(d[j][k] > d[j][i]+d[i][k]){
					d[j][k] = d[j][i]+d[i][k];
//					path[j][k] = i; // �Ǵٸ� �߰���ΰ� ������ �ֱ⶧���� �ٷ� i�� ������Ʈ�ϸ� �ȵ�   
					path[j][k] = path[j][i];
				}
			}
		}
	}
	print_d();
	print_path();
	
	return 0; 
} 
