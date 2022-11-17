#include<bits/stdc++.h>
using namespace std;

void vectorSumTest(){
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = accumulate(v.begin(), v.end(),0);
	cout << sum << '\n';
}

void vectorMaxMinTest(){
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto max = max_element(v.begin(), v.end());
	cout << *max << '\n';
	
	auto min = min_element(v.begin(), v.end());
	cout << *min << '\n';
}

//[Error] declaration of 'a' as multidimensional array 
//must have bounds for all dimensions except the first
void change(int a[][5]){
	a[0][4] = 999;
}

void array2DmodifyTest(){
	int a[3][5] = {
	{ 1, 2, 3, 4, 5 },
	{ 6, 7, 8, 9, 10 },
	{ 11, 12, 13, 14, 15 }
	};
	change(a);
	cout << a[0][4] << "\n";
}


void print2DArray(vector<vector<int>> &vv){
	for(vector<int> v : vv){
	cout << "[";
		for(int i : v){
			cout << i << ", ";
		}
		cout << "]\n";
	}
	cout << "\n";
	cout << "\n";
	
}

void rotateCounterClockwise(vector<vector<int>> &key){
	int m = key.size();
	if( m == 0 ) return;
	vector<int> v = key[0];
	int n = v.size();
	
	// n,m matrix
	vector<vector<int>> temp(n, vector<int>(m, 0));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			// 
			temp[n-j-1][i] = key[i][j];
		}
	}
	key = temp;
	return;
}

void rotateClockwise(vector<vector<int>> &key){
	int m = key.size();
	if( m == 0 ) return;
	vector<int> v = key[0];
	int n = v.size();
	
	// n,m matrix
	vector<vector<int>> temp(n, vector<int>(m, 0));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			// 
			temp[j][m-i-1] = key[i][j];
		}
	}
	key = temp;
	return;
}

void matrixRotateTest(){
	vector<vector<int>> vv = {
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 }
	};
	print2DArray(vv);
	rotateCounterClockwise(vv);
	print2DArray(vv);
	rotateClockwise(vv);
	print2DArray(vv);
}

int main(){
	cout << "\n===vectorSumTest===\n";
	vectorSumTest();
	cout << "\n===vectorMaxMinTest===\n";
	vectorMaxMinTest();
	cout << "\n===array2DmodifyTest===\n";
	array2DmodifyTest();
	cout << "\n===matrixRotateTest===\n";
	matrixRotateTest();
	return 0;
}

