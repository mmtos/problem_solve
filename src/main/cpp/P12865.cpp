#include <iostream>
#include <algorithm>
#include <tuple>
#include <cstring>

using namespace std;

const int MAX_N = 101;
pair<int,int> stuffs[MAX_N];
int N,K,w,v;
// ����: 1. ��ǰ ��ȣ(��ǰ�� ��) : 0(N��), 1(N-1��) .. N-1(1��) 2. �ش� ��ǰ�� �賶�� ���ԵǾ����� ���� 
// �� : �ش� �κй��������� �ִ� ��ġ  
int memo[MAX_N][2];


/*
4 7
7 1000
1 2000
1 1
1 1

4 7
7 3000
1 200
1 1
1 1

4 7
2 300
4 200
3 500
5 400

800 (0�� 2�� ��ǰ) 

2 2
2 10
2 20

2 4 
1 2
4 1

*/

int solution(int start_stuff_num, bool is_contain, int remaining) {
	if(remaining < 0) return -1e9;
	if(start_stuff_num >= N) return 0;
	int & ret = memo[start_stuff_num][is_contain];
	if(~ret) return ret;	
	return ret = max(
	solution(start_stuff_num + 1, 0, remaining)
	, solution(start_stuff_num + 1, 1, remaining - stuffs[start_stuff_num+1].first) + stuffs[start_stuff_num+1].second
	);
	
}

int main(){
	// # DP 
	// 1. �׸��� �ƴ� ��Ž�� ���� : ��ġ�� ū�ͺ��� �ְų�, ���԰� ������ ���� �־ �ݷʰ� ����.  
	// 2. DP�� ������ �� �ִ� ����  
	// - �� ���� ���Կ� ���� sub problem�� main problem�� ������ �����ϴ�. 
	// - ������ ������ sub problem�� �信 ������ ���� �ʴ´�.
	// - �ִ� 2^100�� ����� ���� �߻��Ѵ�.(�ð����⵵ O(2^n) 1024^10 = 10^30 => ��û ũ��.
	
	// sub problem ������.. �� ���� ��ǰ�� �� 
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> w >> v;
		stuffs[i] = {w,v}; 	
	}
	// ��ǰ�� �ּҰ�ġ�� 1�̹Ƿ� memo�� -1�� �ʱ�ȭ
	memset(memo, -1, sizeof(memo));
	
//	memo[N-1][0] = 0;
//	memo[N-1][1] = stuffs[N-1].second;
	
	// 0�� ������ ���Ե� ��� , ���Ե��� �ʴ� ���  
	cout << max(solution(0,0,K), solution(0,1,K - stuffs[0].first) + stuffs[0].second) << "\n";
	
	for(int i=0;i<=N;i++){
		cout << stuffs[i].first << "," << stuffs[i].second << "\n";
	}
	for(int i=0;i<N;i++){
			cout << i << ": ("<< memo[i][0] << "," << memo[i][1] << ")\n";
		}
	return 0;
}
