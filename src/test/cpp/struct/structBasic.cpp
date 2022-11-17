#include<bits/stdc++.h>
using namespace std;

struct Point{
	int y, x;
	Point(int y, int x) : y(y), x(x){}
	Point(){
		y = -1; x = -1;
	}
	
	// 정렬을 위한 연산자 오버로딩 
	bool operator < (const Point & a ) const{
		if(x == a.x) return y < a.y;
		return x < a.x;
	}
};

// 커스텀 비교. x 내림차순 
bool customCmp(const Point & a, const Point & b){
	return a.x > b.x;
}

void pointTest(){
	vector<Point> v;
	for(int i = 10; i >= 1; i--){
		Point a = {i, i};
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for(auto it : v) cout << it.y << " : " << it.x << '\n';
	sort(v.begin(), v.end(), customCmp);
	for(auto it : v) cout << it.y << " : " << it.x << '\n';
} 

int main(){
	cout << "\n===pointTest===\n";
	pointTest();
	return 0;
}


