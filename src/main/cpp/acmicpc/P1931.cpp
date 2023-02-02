#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
#define E first;
#define S second;
 
int N,s,e;
vector<pii> v;

int main(){
	// #�׸��� #TSP(task scheduling problem)
	// time_table �迭(start~end 1�� ǥ��)�� üũ�ϴ� ��� -> �ִ� �ð� INT_MAX�� �޸� �ʰ� 
	// ��ȭ�� ����⵵ �ָ���.
	// �׸���: ȸ�� ����ð������� �����ؼ� �����Ѱ� ���� �ִ´�.
	cin >> N;
	while(N--){
		cin >> s >> e;
		v.push_back({e,s});
	}
	sort(v.begin(),v.end());
	int last = 0, ans = 0;
	for(pii mt : v){
		int start = mt.S;
		int end = mt.E;	
		if(start >= last){
			//�������� 
			ans++;
			last = end; 
		}
	}
	cout << ans;
	
	return 0;
}
