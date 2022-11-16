#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int tc, clo;
map<string,int> m;
 
int combi(vector<int> v,int start){
	if(v.size() == start) return 1;
	int nextCase = combi(v,start+1); //메모필수 
	return nextCase * (v[start] + 1);
}

void solve(){
	cin >> clo;
	for(int i=0; i< clo; i++){
		string clo_name, clo_sort;
		cin >> clo_name >> clo_sort;
		m[clo_sort]++;
	}
	vector<int> v;
	
	for(auto p : m){
		v.push_back(p.second);
	}
	int answer = combi(v,0) -1;
	cout << answer << "\n";
} 

int main(){
    //#조합 #메모이제이션 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> tc;
	for(int i=0; i<tc; i++){
		solve();
		m.clear();
	}
	return 0;
}
