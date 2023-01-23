#include <iostream>
#include <algorithm>

using namespace std;

int N, M, o[10], a[10];
int visited[10]; // 재사용불가 

void back_track(int idx){
	if(idx == M){
		for(int i=0;i<M;i++) cout << a[i] << " ";
		cout << "\n";
		return;
	}
	//초기화 안하면 우연히 같아질 수 있다. 
	// 공유변수가 아니라서,  매 재귀마다 따로따로 값이 저장된다.  
	int tmp = 0; 
	for(int i=0; i<N; i++){
		//if(a[idx-1] > o[i]) continue;
		// 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
		// 정렬되어 있다는 가정하에, 이전에 나왔던 값을 또 반복할 필요는 없다  
		if(visited[i] == 1 || tmp == o[i]) continue; 
		a[idx] = o[i];
		tmp = o[i];
		visited[i] = 1;
		back_track(idx+1);
		visited[i] = 0; 
	}
}

int main(){
	// #백트래킹 #NM #답지  
	// 중복있는 자연수 배열 세기(재사용 불가)  
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> o[i];
	}
	// 출력은 사전순
	sort(&o[0], &o[0] + N); 
	
	back_track(0);
	return 0;
}
