#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void boundTest(){
	vector<int> v;
	int a[5] = {1,2,2,2,3};
	for(int i =0; i < 5 ;i++){
		v.push_back(a[i]);
	}	
	int x = 2;
	auto upperboundPointer = upper_bound(v.begin(),v.end(),x);
	auto lowerboundPointer = lower_bound(v.begin(),v.end(),x);
	printf("%p\n",upperboundPointer);
	int upperIdx = (int) (upperboundPointer - v.begin());
	int lowerIdx = (int) (lowerboundPointer - v.begin());
	int count = upperIdx - lowerIdx;
	printf("%d의 갯수 : %d, 시작되는 점 : %d 끝나는 점 : %d\n", x, count, lowerIdx, upperIdx);
	printf("lowerbound 값 : %d upperbound값 : %d\n",*lowerboundPointer, *upperboundPointer);
}

void boundOfNotExistElementTest(){
	int a[5] = {1, 2, 3, 5, 6};
	int x = 4;
	int lowerBoundIdx = (int) ( lower_bound(a, a+5,x) - a );
	int upperBoundIdx = (int) ( upper_bound(a, a+5,x) - a );
	printf("x : %d, lowerBoundIdx : %d, value: %d\n", x, lowerBoundIdx, a[lowerBoundIdx]);
	printf("x : %d, upperBoundIdx : %d, value: %d\n", x, upperBoundIdx, a[upperBoundIdx]);
	
	int x2 = 0;
	lowerBoundIdx = (int) ( lower_bound(a, a+5,x2) - a );
	upperBoundIdx = (int) ( upper_bound(a, a+5,x2) - a );
	printf("x : %d, lowerBoundIdx : %d, value: %d\n", x2, lowerBoundIdx, a[lowerBoundIdx]);
	printf("x : %d, upperBoundIdx : %d, value: %d\n", x2, upperBoundIdx, a[upperBoundIdx]);
	
	int x3 = 8;
	lowerBoundIdx = (int) ( lower_bound(a, a+5,x3) - a );
	upperBoundIdx = (int) ( upper_bound(a, a+5,x3) - a );
	printf("x : %d, lowerBoundIdx : %d, value: %d\n", x3, lowerBoundIdx, a[lowerBoundIdx]);
	printf("x : %d, upperBoundIdx : %d, value: %d\n", x3, upperBoundIdx, a[upperBoundIdx]);
	
}

int main(){
	std::cout << "\n===boundTest===\n";
	boundTest();
	std::cout << "\n===boundOfNotExistElementTest===\n";
	boundOfNotExistElementTest();
	return 0;
}

