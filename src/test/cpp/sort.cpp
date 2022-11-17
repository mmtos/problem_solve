#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

void basicVectorSortTest(){
	cout << "\n=====" << __func__ << "=====\n";
	vector<pair<int,int>> v;
	
	v.push_back({1, 30});
	v.push_back({2, 20});
	v.push_back({3, 50});
	v.push_back({3, 90});
	
	
	cout << "default sort" << "\n";
	sort(v.begin(),v.end());
	for(auto p : v){
		cout << p.first << ":" << p.second << "\n";
	}
	
	cout << "reverse sort" << "\n";
	reverse(v.begin(),v.end());
	for(auto p : v){
		cout << p.first << ":" << p.second << "\n";
	}
}

//https://8156217.tistory.com/11
void basicPriorityQueueSortTest(){
	cout << "\n=====" << __func__ << "=====\n";
	// #functional
	priority_queue<pair<int,int>> pq;
	pq.push({1, 30});
	pq.push({2, 20});
	pq.push({3, 50});
	pq.push({3, 90});
	
	cout << "default sort" << "\n";
	while(pq.size()){
		auto p = pq.top(); pq.pop();
		cout << p.first << ":" << p.second << "\n";
	}
	
	priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> pq2;
	
	pq2.push({1, 30});
	pq2.push({2, 20});
	pq2.push({3, 50});
	pq2.push({3, 90});
	
	cout << "greater sort" << "\n";
	while(pq2.size()){
		auto p = pq2.top(); pq2.pop();
		cout << p.first << ":" << p.second << "\n";
	}
	
	priority_queue<pair<int,int> ,vector<pair<int,int>>, less<pair<int,int>>> pq3;
	
	pq3.push({1, 30});
	pq3.push({2, 20});
	pq3.push({3, 50});
	pq3.push({3, 90});
	
	cout << "less sort" << "\n";
	while(pq3.size()){
		auto p = pq3.top(); pq3.pop();
		cout << p.first << ":" << p.second << "\n";
	}
}

struct cmp{
	bool operator()(pair<int, int>&a, pair<int, int>&b) {
    	if (a.first == b.first) {
        	return a.second < b.second;
    	}
    	return a.first > b.first;  
	}
};

void customPriorityQueueSortTest(){
	cout << "\n=====" << __func__ << "=====\n";
	
	priority_queue<pair<int,int> ,vector<pair<int,int>>, cmp> pq;
	
	pq.push({1, 30});
	pq.push({2, 20});
	pq.push({3, 50});
	pq.push({3, 90});
	// 오름차순 내림차순으로 정렬 
	while(pq.size()){
		auto p = pq.top(); pq.pop();
		cout << p.first << ":" << p.second << "\n";
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	basicVectorSortTest();
	basicPriorityQueueSortTest();
	customPriorityQueueSortTest();
	return 0;
}
