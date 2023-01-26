#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

const int MX = 51;
int N,M, ord[MX];

void print_dq(deque<int> & DQ){
	cout << "\n=====" << __func__ << "=====\n";
	for(auto x : DQ) cout << x << " ";
	cout << "\n";
}

void left_shift(int count, deque<int> & DQ){
	while(count--){
		DQ.push_back(DQ.front());
		DQ.pop_front();
	}	
}

void right_shift(int count, deque<int> & DQ){
	while(count--){
		DQ.push_front(DQ.back());
		DQ.pop_back();
	}
}

int find_min_rotate_count(int target, deque<int> & DQ){
	auto fi = find(DQ.begin(),DQ.end(),target);
	int left_count = fi - DQ.begin();
	if(left_count == 0) return 0;
	int right_count = DQ.end() - fi;
	if(left_count <= right_count) return left_count;
	else return -right_count;
}

// 1번, 3번, 4번 = 8번  
// 2 3 ~ 10 1 /  9 10 1 3 4 5 6 7 8 / 10 1 3 4 5 7 8 / 5 7 8 10 1 3 4 
int main(){
	// #덱  
	// 앞에서 두번째 뽑으려면 회전 1회
	// 뒤에서 두번째 뽑으려면 회전 2회 처음과 끝값 
	// 앞으로 회전하든 뒤로 회전하든 뽑으려는 수가 가장 앞에오면 결과는 똑같다. 
	// 최소 회전을 어떻게 찾지 (둘다 해볼까)
	
	cin >> N >> M;
	for(int i=0; i<M;i++) cin >> ord[i];
	deque<int> DQ(N);
	for(int i=1; i<=N;i++) DQ[i-1] = i;
	int answer = 0;
	for(int i=0;i<M;i++){
		int found = find_min_rotate_count(ord[i],DQ);
		if(found >= 0){
			left_shift(found,DQ);
			answer += found;
		}else{
			right_shift(-found,DQ);
			answer += -found;
		}
		DQ.pop_front();
	}
	cout << answer << "\n";
	return 0;
}
