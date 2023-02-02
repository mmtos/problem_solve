#include <iostream>

using namespace std;

int N, M;
int a[10];
//int visited[10]; // 중복 가능하므로 필요없음. 가지가 더 늘어남. 

void back_track(int idx){
	if(idx == M){
		for(int i=0;i<M;i++) cout << a[i] << " ";
		cout << "\n";
		return;
	}
	for(int i=0; i<N; i++){
		a[idx] = i+1;
		back_track(idx+1); 
	}
}

int main(){
	//#백트래킹 #NM 
	//중복있는 자연수 순열
	cin >> N >> M;
	back_track(0);
	return 0;
}
