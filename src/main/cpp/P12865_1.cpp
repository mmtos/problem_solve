#include <iostream>
#include <algorithm>
#include <tuple>
#include <cstring>

using namespace std;

const int MAX_N = 101;
pair<int,int> stuffs[MAX_N];
int N,K,w,v;
// ����: 1. ��ǰ ��ȣ(��ǰ�� �� -1 ) 2. �ش� ��ǰ�� �賶�� ���ԵǾ����� ���� 3.  
// �� : �ش� �κй��������� �ִ� ��ġ  
int memo[MAX_N][2];

int solution(int end_stuff_num, int is_contain, int remaining) {
	cout << end_stuff_num << " " << is_contain << " " <<  remaining << "\n";
	if(remaining < 0) return -1e9;
	if(end_stuff_num < 0) return 0;
	int & ret = memo[end_stuff_num][is_contain];
	if(~ret) return ret;	
	
	remaining = remaining - is_contain * stuffs[end_stuff_num].first;
	return ret = max(solution(end_stuff_num - 1, 0, remaining), solution(end_stuff_num - 1, 1, remaining)) + is_contain * stuffs[end_stuff_num].second;
	
}

int main(){
	// # DP Ʋ�� Ǯ�� 
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> w >> v;
		stuffs[i] = {w,v}; 	
	}
	memset(memo, -1, sizeof(memo));
	
	memo[0][0] = 0;
	memo[0][1] = stuffs[0].second;
	
	cout << max(solution(N-1,0,K), solution(N-1,1,K)) << "\n";
	
	for(int i=0;i<=N;i++){
		cout << stuffs[i].first << "," << stuffs[i].second << "\n";
	}
	for(int i=0;i<N;i++){
			cout << i << ": ("<< memo[i][0] << "," << memo[i][1] << ")\n";
		}
	return 0;
}
