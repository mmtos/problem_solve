#include<stack>
#include<iostream>
#include<algorithm>

using namespace std;
const int MAX_N = 1000002;
int N;
stack<int> stks[MAX_N];

void oom(){
	cin >> N;
	int temp;
	for(int i = 1; i <= N; i++){
		cin >> temp;
		stks[i].push(temp);
		for(int j=1;j<i;j++){
			if(stks[j].size() == 2) continue;
			if(stks[j].top() < temp) stks[j].push(temp); 
		}
	}
	for(int i = 1; i <= N; i++){
		if(stks[i].size() == 1) cout << -1 << " ";
		if(stks[i].size() == 2) cout << stks[i].top() << " ";
	}
}
int arr[MAX_N],nge[MAX_N];
void tle(){
	cin >> N;
	stack<int> stk;
	fill(nge,nge+MAX_N,-1);
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		stk.push(arr[i]);
	}
	int size, top;
	while(!stk.empty()){
		size = stk.size();
		top = stk.top(); 
		stk.pop();
		for(int i=1;i<=size;i++){
			if(arr[i] < top) nge[i] = top;
		}
	}
	for(int i=1;i<=N;i++){
		cout << nge[i] << " ";
	}
}

/*
4
7 4 5 8

4
9 4 5 8
*/
int main(){
	// #스택 #답지 
	ios::sync_with_stdio(0);
  	cin.tie(0);
  	cin >> N;
  	for(int i=1;i<=N;i++) cin >> arr[i];
	stack<int> stk;
	for(int i=N;i>0;i--){
		// arr[i] 보다 큰수가 나올때 까지 pop  
		while(!stk.empty() && stk.top() <= arr[i]) stk.pop();
		if(stk.empty()) nge[i] = -1;
		else nge[i] = stk.top();
		stk.push(arr[i]);
	}
	
  	for(int i=1;i<=N;i++) cout << nge[i] << " ";
	return 0;
}

