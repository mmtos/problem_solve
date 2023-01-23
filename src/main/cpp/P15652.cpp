#include <iostream>

using namespace std;

int N, M, a[10];

void back_track(int idx){
	if(idx == M){
		for(int i=0;i<M;i++) cout << a[i] << " ";
		cout << "\n";
		return;
	}
	for(int i=0; i<N; i++){
		if(a[idx-1] > i+1) continue;
		a[idx] = i+1;
		back_track(idx+1); 
	}
}

int main(){
	//#백트래킹 #NM 
	//중복있는 자연수 순열, 비내림차순 
	cin >> N >> M;
	back_track(0);
	return 0;
}
