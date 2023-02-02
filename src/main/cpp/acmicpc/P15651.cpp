#include <iostream>

using namespace std;

int N, M;
int a[10];
//int visited[10]; // �ߺ� �����ϹǷ� �ʿ����. ������ �� �þ. 

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
	//#��Ʈ��ŷ #NM 
	//�ߺ��ִ� �ڿ��� ����
	cin >> N >> M;
	back_track(0);
	return 0;
}
