#include <iostream>
#include <queue>

using namespace std;

int N;
const int MX = 4000001;
int visited[MX];

void greedy_fail(){
	cin >> N;
	queue<int> q;
	int ans = 0;
	
	// �ֿ켱������ 3���� ������ �׸��� ����� �Ұ��� ��  
	//10 -> 9 -> 3 -> 1 �� 3�� ���� ���� �� �ִ�.
	q.push(N);
	while(!q.empty()){
		int next = q.front(); q.pop();
		if(next == 1) break;
		if(next % 3 == 0) q.push(next / 3);
		else if(next % 2 == 0) q.push(next / 2);
		else q.push(next - 1);
		ans++;
	}
	cout << ans;
} 


int bfs(){
	// 1�� ���������ϴ� �׷����� ������ �� �ִ�.
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while(!q.empty()){
		int next = q.front(); q.pop();
		if(next == N) break;
		if(next > N) continue; // out of bound ����.. 
		// next�� ����� 3���� ������ �湮�Ѵ�.
		int a = next * 2;
		int b = next * 3;
		int c = next + 1;
		if(!visited[a]) {
			visited[a] = visited[next] + 1;
			q.push(a);
		}
		if(!visited[b]) {
			visited[b] = visited[next] + 1;
			q.push(b);
		}
		if(!visited[c]) {
			visited[c] = visited[next] + 1;
			q.push(c);
		}
	}
//	cout << visited[N] - 1 << "\n";
	return visited[N] - 1;
	//for(int i=0;i<=N;i++) cout << visited[i] << " ";
}

#include <algorithm>
int dp[MX];
int dynamic(){
	//dp[1] = 1; //������� �ߺ���.. 
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for(int i=4;i<=N;i++){
		if(dp[i]) continue;
		if(i % 3 == 0 && i % 2 == 0){
			dp[i] = min(dp[i/2], min(dp[i/3], dp[i-1])) + 1;
		}else if(i % 3 == 0){
			dp[i] = min(dp[i/3], dp[i-1]) + 1;
		}else if(i % 2 == 0){
			dp[i] = min(dp[i/2], dp[i-1]) + 1;	
		}else{
			dp[i] = dp[i-1] + 1;
		}
	}
//	cout << dp[N];
	return dp[N];
} 

int main(){
	// #BFS #DP #���� 
	cin >> N;
	//cout << bfs();
	cout << dynamic();
	return 0;
} 
