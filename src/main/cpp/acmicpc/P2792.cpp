#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, gem[300010], answer = 1e9 + 1;
int main(){
	// #이분탐색 
	cin >> n >> m;
	ll low = 1, high = 1, mid;
	for(int i=0; i<m; i++){
		cin >> gem[i];
		high = max(high, gem[i]);
	}
	
	while(low <= high){
		mid = (low + high) /2;
		int num = 0;
		for(int i=0; i<m; i++){
			num += gem[i] / mid;
			if(gem[i] % mid) num++;
		}
		
		if(n >= num){
			// 분배 가능한 경우 질투심을 낮춘다.
			high = mid - 1; 
			answer = min(answer,mid);
		}else{
			// 분배 불가능한 경우 질투심을 높인다. 
			low = mid + 1;
		}
	}
	cout <<  answer << "\n";
	return 0;
}
