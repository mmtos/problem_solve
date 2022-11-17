#include<bits/stdc++.h>
using namespace std;
struct Point{
	int y, x;
	Point(int y, int x) : y(y), x(x){}
	Point(){y = -1; x = -1; }
	bool operator < (const Point & a) const{
		// ��������
		return x > a.x;
	}
};

// heap and priority queue 
// ���ͽ�Ʈ��, �׸��� 
void pqTest(){
	priority_queue<int,vector<int>,greater<int>> pq;
	pq.push(3);
	pq.push(31);
	pq.push(63);
	pq.push(8482);
	pq.push(22);
	cout << pq.top() << "\n";
} 

void pqTest2(){
	//�켱����ť�� Ŀ���� ������ ���� ���� �ݴ��� ����
	priority_queue<Point> pq; 
	pq.push({1, 1});
	pq.push({2, 2});
	pq.push({3, 3});
	pq.push({4, 4});
	pq.push({5, 5});
	pq.push({6, 6});
	cout << pq.top().x << "\n"; //1
	
	vector<Point> v;
	v.push_back({1, 1});
	v.push_back({2, 2});
	v.push_back({3, 3});
	v.push_back({4, 4});
	v.push_back({5, 5});
	v.push_back({6, 6});
	sort(v.begin(), v.end());
	cout << v[0].x << "\n"; //6
} 

int main(){
	cout << "\n===pqTest===\n";
	pqTest();
	cout << "\n===pqTest2===\n";
	pqTest2();
	return 0;
}


