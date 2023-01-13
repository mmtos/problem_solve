#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

void next_permutation_test(){
//	int a[] = {1,2,3,4};
//	next_permutation(&a, &a + 4);
	vector<int> a = {1,2,3,4};
	next_permutation(a.begin(), a.end());
	for(int b: a) cout << b << ",";
}

vector<int> solution(int n, ll k) {
    vector<int> answer;
    for(int i=1; i<=n; i++) answer.push_back(i);
    
    for(int i=1; i<k; i++) next_permutation(answer.begin(), answer.end());
    return answer;
}

ll dp[22];
ll factorial(int k){
	if(k == 0 || k == 1) return 1;
	if(dp[k] != 0) return dp[k];
	ll rst = k * factorial(k-1);
	dp[k] = rst;
	return rst;
}

vector<int> solution2(int n, ll k) {
	vector<int> v, answer;
    for(int i=1; i<=n; i++) v.push_back(i);
    for(int i=n; i>0; i--){
    	if(v.size() == 1){
	    	answer.push_back(v[0]);
	    	return answer;
		}
    	cout << k << "\n";
    	ll f = factorial(i-1);
    	int index = (k-1)/f;
    	cout << "index: " << index << "\n";
    	k = k - f * index;
	    answer.push_back(v[index]);
	    v.erase(v.begin()+index);
	}
	return answer;
}

int main(){
	// #순열(팩토리얼사용) 
	for(int b: dp) cout << b << ",";
	cout <<  "\n";
	cout << factorial(15) << "\n";
	for(int b: dp) cout << b << ",";
	cout <<  "\n";
	cout << factorial(14) << "\n";
	int n = 3;
	ll k = 5;
	vector<int> a = solution2(15,1307674367998LL);
	for(int b: a) cout << b << ",";
	
	return 0;
}
