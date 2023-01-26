#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
#define E first;
#define S second;
 
int N,s,e;
vector<pii> v;

int main(){
	// #그리디 #TSP(task scheduling problem)
	// time_table 배열(start~end 1로 표시)에 체크하는 방법 -> 최대 시간 INT_MAX로 메모리 초과 
	// 점화식 세우기도 애매함.
	// 그리디: 회의 종료시각순으로 정렬해서 가능한걸 집어 넣는다.
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
			//배정가능 
			ans++;
			last = end; 
		}
	}
	cout << ans;
	
	return 0;
}
