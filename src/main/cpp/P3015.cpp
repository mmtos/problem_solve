#include<stack>
#include<iostream>
#include<algorithm>

using namespace std;
const int MX = 500002;
int N;
// left_wise_first_big, right_wise_first_big, right_wise_same
int arr[MX], lb[MX],rb[MX],rs[MX];
typedef long long ll;

void first_answer(){
	cin >> N;
	for(int i=0;i<N;i++) cin >> arr[i];
	stack<int> s;
	for(int i=0;i<N;i++){
		while(!s.empty() && s.top() < arr[i]) s.pop();
		if(s.empty()) lb[i] = -1;
		else lb[i] = s.top();
		s.push(arr[i]);
	}
	
	while(!s.empty()) s.pop();
	
	for(int i=N-1;i>=0;i--){
		while(!s.empty() && s.top() <= arr[i]) s.pop();
		if(s.empty()) rb[i] = -1;
		else rb[i] = s.top();
		s.push(arr[i]);
	}
	
	ll answer = 0;
//	while(!s.empty()) s.pop();
//	
//	for(int i=N-1;i>=0;i--){
//		while(!s.empty() && s.top() != arr[i]) s.pop();
//		if(s.empty()) rs[i] = -1;
//		else rs[i] = s.top();
//		s.push(arr[i]);
//	}
//	ll temp = 0;
	for(int i=0;i<N;i++){
		if(~lb[i]) answer++;
		if(~rb[i]) answer++;	
//		if(~rs[i]) {
//			temp++;
//		}else{
//			answer += (temp * (temp+1)) / 2; 
//			temp = 0;
//		}
	}
	cout << answer << "\n";
	for(int i=0;i<N;i++) cout << lb[i] << " ";
	cout << "\n";
	for(int i=0;i<N;i++) cout << rb[i] << " ";
	cout << "\n";
	for(int i=0;i<N;i++) cout << rs[i] << " ";
}

#define X first
#define Y second

void lecture_answer(){
	// https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x05/solutions/3015.cpp
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	stack<pair<int, int>> S;
	long long ans = 0;
	// 앞에서 부터 순회 
	while (n--) {
		int h;
		cin >> h;
		int cnt = 1;
		while (!S.empty() && S.top().X <= h) {
			// 1. 동일한 키가 연속해서 나오는 경우
			// 2. 더 큰 키가 나오는 경우
			ans += S.top().Y; // 새로운 점을 끝점으로 하는 순서쌍(거리 1,2,... cnt칸) 추가 
			if (S.top().X == h) cnt += S.top().Y; // 숫자가 몇번이나 연속해서 나왔는지 저장
			S.pop();
		}
		// {3, 2} {2, 1} 
		// 더 작은 키가 나오는 경우 이전의 큰키는 보존하고, 스택에 쌓인다 
		if (!S.empty()) ans++; // 시작점의 키가 더 큰 순서쌍 추가 ( 1개만 추가된다, 시작점이 더 크기때문에  시작점 앞의 사람들은 보이지 않는다) 
		S.push({h, cnt});
	}
	cout << ans;
} 
/*
7 2 4 1 2 2 5 1 
답 10 

4 2 2 2 2
답 6 

4 3 3 2 3
답 4

5 1 2 3 4 5
답 4 

5 5 4 3 2 1 
답 4 

5 1 1 1 4 5
답 7

10 2 2 2 2 2 3 3 3 3 3
답 25  
*/

// a a 1쌍 
// a a a  3쌍
// a a a a 6쌍
// a a a a a 10쌍 
int main(){
	// #스택 #답지 
	// 처음에 분할정복으로 풀려고 시도했으나 실패 
//	first_answer();
	lecture_answer();
	return 0;
} 
