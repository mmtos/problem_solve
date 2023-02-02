#include<bits/stdc++.h>
using namespace std;
vector<int> dwarfs;
vector<int> notFound = {}; //empty vector
int N = 9;

int sumOfArray(vector<int> v){
	return accumulate(v.begin(), v.end(),0);
}

// 경우의 수를 리턴하는게 아니라 조건에 맞는 특정 케이스를 리턴
// 여기서 재귀는 병렬로 실행되는게 아니라 DFS방식으로 순차적으로 실행됨. 
vector<int> combi(vector<int> v, int k, int start) {
	if(v.size() == k && sumOfArray(v) == 100) return v;
	if(v.size() == k) return notFound; 
	if(start == N) return notFound; // k개보다 적게 선택한 케이스. 
	
	for(int i = start ; i < N ; i++){
		v.push_back(dwarfs[start]);
		vector<int> includeCase = combi(v, k, start +1);
		if(includeCase.size() != 0) return includeCase;
		
		v.pop_back();
		return combi(v, k, start +1);
	}
	//합이 100인 부분 수열은 반드시 존재한다.   
}
 
int main(){
	//#조합 #브루트포스 
//	int a[N];
//	for(int i=0; i < N ; i++ ) {
//		cin >> a[i];
//		dwarfs.push_back(a[i]);
//	}
	
	int input;
	while(dwarfs.size() < N && cin >> input) dwarfs.push_back(input);
	vector<int> selected;
	vector<int> answer = combi(selected,7,0);
	sort(answer.begin(), answer.end());
	for(auto i = answer.begin(); i != answer.end() ; i++ ) cout << *i << '\n';
	return 0;
}
