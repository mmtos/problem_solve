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

// 1��, 3��, 4�� = 8��  
// 2 3 ~ 10 1 /  9 10 1 3 4 5 6 7 8 / 10 1 3 4 5 7 8 / 5 7 8 10 1 3 4 
int main(){
	// #��  
	// �տ��� �ι�° �������� ȸ�� 1ȸ
	// �ڿ��� �ι�° �������� ȸ�� 2ȸ ó���� ���� 
	// ������ ȸ���ϵ� �ڷ� ȸ���ϵ� �������� ���� ���� �տ����� ����� �Ȱ���. 
	// �ּ� ȸ���� ��� ã�� (�Ѵ� �غ���)
	
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
