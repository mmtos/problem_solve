#include<bits/stdc++.h>
using namespace std;

void rotateTest(){
	vector<int> v;
	for (int i=1; i<10; ++i) v.push_back(i);
	
	vector<int>::iterator middle = v.begin();
	
	int rotateCount = 2;
	for(int i = 0; i < rotateCount ; i++){
		//middle�� front�� �̵�. front�� ������ middle�������� ���Ҵ� �ڷ� ����
//		rotate(v.begin(),v.begin()+ 1, v.end()); // �������� rotate 
//		rotate(v.begin(),v.end() - 1 , v.end()); // �������� rotate

		auto subStart = v.begin() + 2;
		auto subEnd = v.begin() + 6;
		rotate(subStart,subEnd - 1 , subEnd); //  �Ϻθ� �������� rotate
 
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

