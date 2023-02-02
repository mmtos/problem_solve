#include <iostream>
#include <algorithm>

using namespace std;

int N, M, o[10], a[10];
int visited[10]; // ����Ұ� 

void back_track(int idx){
	if(idx == M){
		for(int i=0;i<M;i++) cout << a[i] << " ";
		cout << "\n";
		return;
	}
	int tmp = 0; 
	for(int i=0; i<N; i++){
		if(a[idx-1] > o[i]) continue; 
		if(visited[i] == 1 || tmp == o[i]) continue; 
		a[idx] = o[i];
		tmp = o[i];
		visited[i] = 1;
		back_track(idx+1);
		visited[i] = 0; 
	}
}

int main(){
	// #��Ʈ��ŷ #NM
	// �ߺ��ִ� �ڿ��� �迭 ����(���� �Ұ�), �� ������ �� 
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> o[i];
	}
	// ����� ������
	sort(&o[0], &o[0] + N); 
	
	back_track(0);
	return 0;
}
