#include<bits/stdc++.h>
using namespace std;
vector<int> dwarfs;
vector<int> notFound = {}; //empty vector
int N = 9;

int sumOfArray(vector<int> v){
	return accumulate(v.begin(), v.end(),0);
}

// ����� ���� �����ϴ°� �ƴ϶� ���ǿ� �´� Ư�� ���̽��� ����
// ���⼭ ��ʹ� ���ķ� ����Ǵ°� �ƴ϶� DFS������� ���������� �����. 
vector<int> combi(vector<int> v, int k, int start) {
	if(v.size() == k && sumOfArray(v) == 100) return v;
	if(v.size() == k) return notFound; 
	if(start == N) return notFound; // k������ ���� ������ ���̽�. 
	
	for(int i = start ; i < N ; i++){
		v.push_back(dwarfs[start]);
		vector<int> includeCase = combi(v, k, start +1);
		if(includeCase.size() != 0) return includeCase;
		
		v.pop_back();
		return combi(v, k, start +1);
	}
	//���� 100�� �κ� ������ �ݵ�� �����Ѵ�.   
}
 
int main(){
	//#���� #���Ʈ���� 
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
