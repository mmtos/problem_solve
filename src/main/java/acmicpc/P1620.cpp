#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;
int main(){
	// #입출력효율 : endl 사용하지 말것, sync 및 tie 제거하면 빨라짐 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
//	unordered_map<string, int> m;
//	unordered_map<int, string> rm;
	map<string, int> m;
	map<int, string> rm;
	int n, p;
	cin >> n >> p;
	for(int i=1; i<=n; i++){
		string t; 
		cin >> t;
		
//		m.insert({t, i});
//		rm.insert({i, t});
		m[t] = i;
		rm[i] = t;
//		m.emplace(t,i);
//		rm.emplace(i,t);
	}
	for(int i=0; i<p; i++){
		string t;
		cin >> t;
//		if(all_of(t.begin(),t.end(),::isdigit)){
		if(isdigit(*t.begin())){
			int num = stoi(t);
//			cout << rm[num] << endl;
//			cout << rm.find(num) -> second << endl;
//			cout << rm.find(num) -> second << "\n";
			cout << rm[num] << "\n";
		}else{
//			cout << m[t] << endl;
//			cout << m.find(t) -> second << endl;
//			cout << m.find(t) -> second << "\n";
			cout << m[t] << "\n";
		}	
	}
	
	return 0;
}

int main_fail(){
	// n^2
	int n, p;
	cin >> n >> p;
	vector<string> v(n+1);
	v.push_back("X");
	for(int i=1; i<=n; i++){
		cin >> v[i];
	}
	for(int i=0; i<p; i++){
		string t;
		cin >> t;
		//https://java2blog.com/check-if-string-is-number-cpp/
		//https://www.freecodecamp.org/news/string-to-int-in-c-how-to-convert-a-string-to-an-integer-example/
		if(all_of(t.begin(),t.end(),::isdigit)){
			int num = stoi(t);
			cout << v[num] << "kk" << endl;
		}else{
			cout << find(v.begin(),v.end(),t) - v.begin() << "kk" << endl;
		}
		
	}
	
	return 0;
}

