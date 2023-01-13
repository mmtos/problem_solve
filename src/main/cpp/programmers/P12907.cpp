#include <bits/stdc++.h>

using namespace std;
typedef long long ll; 

void popVector(vector<int> v){
	// 값 복사 
	if(v.size() > 0 ) v.pop_back();
}

void popVector2(vector<int> & v){
	//참조 전달 
	if(v.size() > 0 ) v.pop_back();
}

void vectorChangeTest(){
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	popVector2(v);
	for(int a: v ) cout << a << ",";
	
}

const int modular = 1000000007;

int solution(int n, vector<int> money) {
	// 효율성 실패  
	if(n == 0) return 1;
	if(n<0) return 0;
	if(money.size() == 0 ) return 0;
    int answer = 0;
    int k = money[0];
    money.erase(money.begin());
    for(int i=0; i<= n/k ;i++){
    	answer += solution(n-k*i, money) % modular;
	}
    return answer % modular;
}
 //나머지를 더한다?
 // (ax + b + cx+ d )% x =  ((a+c )x + b+d ) % x  = (b+d) % x    

int main(){
	// 거스름돈 가지수 세기
	// k원짜리를 0개 쓰는 경우
	// k원짜리를 1개 쓰는 경우
	// ...
	// k원짜리를 n/k개 쓰는 경우  
	// #DP 
	int n = 5;
	vector<int> money = {1,2,5};
	int answer =solution(n,money);
	cout << answer << "\n";
	return 0;
} 
