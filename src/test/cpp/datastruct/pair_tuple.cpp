#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v){
	for(int i : v){
		cout << i << " ";
	}
	cout << "\n";
}

void printVector(vector<pair<int,int>> &v){
	for(auto i : v){
		cout << i.first << ":" <<  i.second << ", ";
	}
	cout << "\n";
}

void makePairTest(){
	int a,b;
	pair<int,int> pi = {1, 2};
	printf("%d %d",pi.first,pi.second);
	
	tie(a,b) = pi;
	printf("%d %d",a,b);
	cout << '\n';
}

void makeTupleTest(){
	int a,b,c;
	tuple<int, int, int> tl;
	tl = make_tuple(1,2,3);
	tie(a,b,c) = tl;
	printf("%d %d %d",a,b,c);
	cout << '\n';
	
	int d,e,f,g;
	tuple<int, int, int, int> tl2 = make_tuple(1,2,3,4);
	d = get<0>(tl2);
	e = get<1>(tl2);
	f = get<2>(tl2);
	g = get<3>(tl2);
	printf("%d %d %d %d",d,e,f,g);
	cout << '\n';
}

// sort  array나 vector와 같은 컨테이너를 정렬할때 사용 
void sortTest(){
	// [first , last)
	vector<int> a;
	for(int i=5; i>=1; i--) {
		a.push_back(i);	
	}
	printVector(a);
	
	sort(a.begin(), a.end());
	printVector(a);
	
	sort(a.begin(), a.end(), greater<int>());
	printVector(a);
	
	sort(a.begin(), a.end(), less<int>());
	printVector(a);
}

bool cmp(pair<int,int> a, pair<int,int> b){
	// true인 경우 첫번째 인자가 더 앞에 정렬된다. 
	return a.first > b.first;
}
void sortWithCustomFnTest(){
	vector<pair<int,int>> a;
	for(int i=10; i>=1; i--) {
		a.push_back({i, 10-i});	
	}
	
	printVector(a);
	
	sort(a.begin(), a.end());
	printVector(a);
	
	sort(a.begin(), a.end(), cmp);
	printVector(a);
}

int main(){
	makePairTest();
	makeTupleTest();
	sortTest();
	sortWithCustomFnTest();
	return 0;
}
