#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 20000;
int TC, N, M, a[MX+1], b[MX+1];

/*
1
2 5
3 4
1 5 8 9 10

1
2 5
3 4
1 2 2 2 10

1
2 5
3 4
1 3 3 3 10

1
2 7
3 4
1 3 3 3 3 3 10

1
2 7
3 4
3 3 3 3 3 3 3
*/
void bi_srch(){
	// #이분탐색 #정렬
	cin >> TC;
	while(TC--){
		cin >> N >> M;
		for(int i=0; i<N; i++){
			cin >> a[i];
		}
		for(int i=0; i<M; i++){
			cin >> b[i];
		}
		sort(b,b+M);
		int ans = 0;
		for(int i=0;i<N;i++){
			int left=0, right=M-1, mid=0, found=-1;
			while(left<=right){
				mid = (left+right) / 2;
				if(a[i] > b[mid]){
					left = mid + 1;
					// B 집합 중복 고려.. 
					found = mid;
				}else{
					right = mid - 1;
				}
			}
			ans += found + 1;
		}	
		cout << ans << "\n";
	}
}

void use_bound(){
	// #정렬 #수학 # NlogN
	cin >> TC;
	while(TC--){
		cin >> N >> M;
		for(int i=0; i<N; i++){
			cin >> a[i];
		}
		for(int i=0; i<M; i++){
			cin >> b[i];
		}
		sort(b,b+M);
		int ans = 0;
		for(int i=0;i<N;i++){
			//동일크기는 먹지못함 
			int found = upper_bound(b,b+M,a[i]-1) - b;
			ans += found;
		}
		cout << ans << "\n";
	}
} 
int main(){
	use_bound();
	return 0;
} 
