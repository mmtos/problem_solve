#include <iostream>
#include <tuple>
#include <string>

using namespace std;
typedef pair<int,int> pii;
const int MAX_N = 65;
int N, m[MAX_N][MAX_N];

string zip(pii lu, pii rd,int size){
	bool zippable = true;
	int temp = m[lu.first][lu.second];
	if(size == 1) return to_string(temp);
	
	for(int i=lu.first;i<rd.first;i++){
		for(int j=lu.second;j<rd.second;j++){
			if(temp != m[i][j]) {
				zippable = false;
				break;	
			}
		}	
	}
	if(zippable) return to_string(temp) ;
	int half = size/2;
	return "(" 
	+ zip(lu,{rd.first - half,rd.second - half},half)  
	+ zip({lu.first,lu.second + half},{rd.first - half ,rd.second},half)
	+ zip({lu.first + half,lu.second},{rd.first ,rd.second - half},half)
	+ zip({lu.first + half,lu.second + half},rd,half)
	+ ")";
}

int main(){
	// #분할정복 #리뷰 
	// 맵이 나오지만 BFS DFS는 아니다. 
	cin >> N;
	string s;
	for(int i=0;i<N;i++){
		cin >> s;
		for(int j=0;j<N;j++){
			m[i][j] = s[j] - '0'; 
		}	
	}
	
	cout << zip({0,0},{N,N},N) << "\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << m[i][j]; 
		}	
		cout << "\n";
	}
	
	return 0;
}
