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
	// �տ��� ���� ��ȸ 
	while (n--) {
		int h;
		cin >> h;
		int cnt = 1;
		while (!S.empty() && S.top().X <= h) {
			// 1. ������ Ű�� �����ؼ� ������ ���
			// 2. �� ū Ű�� ������ ���
			ans += S.top().Y; // ���ο� ���� �������� �ϴ� ������(�Ÿ� 1,2,... cntĭ) �߰� 
			if (S.top().X == h) cnt += S.top().Y; // ���ڰ� ����̳� �����ؼ� ���Դ��� ����
			S.pop();
		}
		// {3, 2} {2, 1} 
		// �� ���� Ű�� ������ ��� ������ ūŰ�� �����ϰ�, ���ÿ� ���δ� 
		if (!S.empty()) ans++; // �������� Ű�� �� ū ������ �߰� ( 1���� �߰��ȴ�, �������� �� ũ�⶧����  ������ ���� ������� ������ �ʴ´�) 
		S.push({h, cnt});
	}
	cout << ans;
} 
/*
7 2 4 1 2 2 5 1 
�� 10 

4 2 2 2 2
�� 6 

4 3 3 2 3
�� 4

5 1 2 3 4 5
�� 4 

5 5 4 3 2 1 
�� 4 

5 1 1 1 4 5
�� 7

10 2 2 2 2 2 3 3 3 3 3
�� 25  
*/

// a a 1�� 
// a a a  3��
// a a a a 6��
// a a a a a 10�� 
int main(){
	// #���� #���� 
	// ó���� ������������ Ǯ���� �õ������� ���� 
//	first_answer();
	lecture_answer();
	return 0;
} 
