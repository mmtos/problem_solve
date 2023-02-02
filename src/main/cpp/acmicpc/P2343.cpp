#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,m,lec[100010];
ll mid, low=1,high=0, answer = 1e15;

bool check2(){
	int num = 0;
	ll sum = 0;
	for(int i=0;i<n;i++){
		ll next = sum + lec[i];
		if(next >= mid) num++;
		if(num > m) return false;
		if(num == m){
			if(next > mid) return false;
		}else{
			if(next > mid){
				sum = lec[i];
			}else if(next == mid){
				sum = 0;
			}else{
				sum = next;
			}
		}
	}
	return true;
}

bool check(){
	int num = 0;
	ll sum = 0;
	for(int i=0;i<n;i++){
		if(sum > mid) return false;
		ll next = sum + lec[i];
		cout << "next : " << next << "\n";
		if(next > mid){
			num++;
			sum = lec[i];
		}else if(next == mid){
			num++;
			sum = 0;
		}else{
			sum = next;
		}
		
		if(i == n-1 && sum > 0) num++;
		if(num > m) return false;
		cout << "num : " << num << "\n";
	}
	return true;
}

int main(){
	// #이분탐색 : 블루레이 크기 최소값 구하기.
	cin >> n >> m;
	
	// 모든 강의의 길이를 더한 크기를 high로 봄
	for(int i=0; i<n; i++){
		cin >> lec[i];
		high += lec[i];
	}
	
	while(low<=high){
		mid = (low + high) / 2;
		cout << "low : " << low << ".. high : " << high  << "\n";
		cout << "mid : " << mid  << "\n";
		if(check()){
			high = mid -1;	
			answer = min(answer,mid);
		}else {
			low = mid + 1;
		} 
	}
	
	cout << answer << "\n";
	
	return 0;
}
