#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	//#´©ÀûÇÕ 
	int n, k;
	cin >> n >> k;
	vector<int> accSum;
	int beforeSum = 0;
	accSum.push_back(beforeSum);
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		if(i == 0) accSum.push_back(a);
		else accSum.push_back(accSum[i] + a);
	}
	vector<int> kSum;
	for(int i=0; i <= n-k ;i++) kSum.push_back(accSum[i+k] - accSum[i]);
	cout << *max_element(kSum.begin(), kSum.end());
	return 0; 
}
