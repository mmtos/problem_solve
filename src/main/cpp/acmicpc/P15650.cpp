#include <iostream>

using namespace std;

int N, M;
int a[10], visited[10];

void back_track(int idx){
	if(idx == M+1){
		for(int i=1;i<=M;i++) cout << a[i] << " ";
		cout << "\n";
		return;
	}
	for(int i=1;i<=N;i++){
		// 가지치기 a[0]=0라 건들 필요없음 
		if(visited[i] || a[idx-1] >= i) continue;
		a[idx] = i;
		visited[i] = 1;
		back_track(idx + 1);
		visited[i] = 0;
	}
}

int main(){
	//#백트래킹 #NM 
	//중복없는 자연수 순열, 오름차순 
	cin >> N >> M;
	back_track(1);
	return 0;
}
