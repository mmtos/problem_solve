#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T,W, memo[1004][2][34], jadu[1004];

int solution(int idx, int tree, int cnt){
	// idx : �ð� 
	// tree : ���� ��ġ  
	// cnt : ���� ������ ���� Ƚ�� -1�� ���� �� �ְ� �س��� 
	
	// �ִ밪�� ���ؾ��ϴ� �������� -1000,000,000�� ���ع����� �ǹ̰� ������ 
	if(cnt < 0) return -1e9;
	if(idx == T) return cnt >= 0 ? 0 : -1e9;
	if(memo[idx][tree][cnt] != -1) return memo[idx][tree][cnt];
	// tree^1 ���  
	memo[idx][tree][cnt] = max(solution(idx+1,tree^1,cnt-1), solution(idx+1,tree,cnt)) + (tree == (jadu[idx] - 1));
	return memo[idx][tree][cnt];
	 
} 

int main(){
	// #DP-bottom up
	// �� W��ŭ �������� �ʾƵ� ��
	// W�� ��� ó������? 
	
	// ��Ʈ����ŷ ����:  ~k = -(k+1)
	// 3���� �̻��϶� �ʱ�ȭ ���� �ϱ� <cstring>�� ���ԵǾ�����. 
	memset(memo,-1,sizeof(memo));
	cin >> T >> W;
	for(int i=0; i<T; i++){
		cin >> jadu[i];
	}
	cout << max(solution(0,1,W-1), solution(0,0,W));
	return 0;
}
