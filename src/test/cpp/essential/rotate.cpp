#include<bits/stdc++.h>
using namespace std;

void rotateTest(){
	vector<int> v;
	for (int i=1; i<10; ++i) v.push_back(i);
	
	vector<int>::iterator middle = v.begin();
	
	int rotateCount = 2;
	for(int i = 0; i < rotateCount ; i++){
		//middle이 front로 이동. front를 포함한 middle전까지의 원소는 뒤로 붙음
//		rotate(v.begin(),v.begin()+ 1, v.end()); // 좌측으로 rotate 
//		rotate(v.begin(),v.end() - 1 , v.end()); // 우측으로 rotate

		auto subStart = v.begin() + 2;
		auto subEnd = v.begin() + 6;
		rotate(subStart,subEnd - 1 , subEnd); //  일부만 우측으로 rotate
 
	}
	
	
	for(vector<int>::iterator it=v.begin(); it!=v.end();++it){
		cout << ' ' << *it;
	}
	cout << '\n';
}

int main(){
	cout << "\n===rotateTest===\n";
	rotateTest();
	return 0;
}

