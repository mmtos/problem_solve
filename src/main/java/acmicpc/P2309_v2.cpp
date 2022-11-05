#include<bits/stdc++.h>
using namespace std;

vector<int> dwarfs;
vector<int> ans;
vector<int> dto;
int N = 9;

void combi(int k, int start) {
	if(dto.size() == k && accumulate(dto.begin(), dto.end(),0) == 100) ans = dto;
	if(dto.size() == k || start == N) return; 
	
	for(int i = start ; i < N ; i++){
		dto.push_back(dwarfs[start]);
		combi(k, start +1);
		if(ans.size() != 0) return; //이미 찾았으므로 종료  
		
		dto.pop_back();
		combi(k, start +1);
	}
}
 
int main(){
	//#조합 #브루트포스 
	int input;
	while(dwarfs.size() < N && cin >> input) dwarfs.push_back(input);
	combi(7,0);
	sort(ans.begin(), ans.end());
	for(auto i = ans.begin(); i != ans.end() ; i++ ) cout << *i << '\n';
	return 0;
}
