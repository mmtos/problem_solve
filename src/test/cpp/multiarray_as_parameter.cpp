#include<bits/stdc++.h>
using namespace std;

template<typename T, size_t S1, size_t S2>
void printArrayForStaticArray(T (&arr)[S1][S2]){
	// it works for automatic (usually stack-living) arrays only 
	// i.e. the dimensionality should be known at compile time.
	cout << "\n=====" << __func__ << "=====\n";
	cout << sizeof(arr) << '\n';
	for(int i= 0 ; i < S1 ;i++) {
		for(int j= 0 ; j < S2 ;j++) {
			cout << arr[i][j] << ",";
		}
		cout << "\n";
	}
}

void printArrayForDynamicArray(int *dArr, size_t rows, size_t cols){
	cout << "\n=====" << __func__ << "=====\n";
	cout << sizeof(dArr) << '\n';
	for(int i= 0 ; i < rows ;i++) {
		for(int j= 0 ; j < cols ;j++) {
			cout << *(dArr + i * rows + j) << ",";
		}
		cout << "\n";
	}
}

void staticMultiDimensionalArrayTest(){
	cout << "\n=====" << __func__ << "=====\n";
	int staticArr[3][3] = {{1,2,3}, {4,5,6},{7,8,9}};
	cout << sizeof(staticArr) << '\n'; // 3*3*4
	printArrayForStaticArray(staticArr);
}

void dynamicMultiDimensionalArrayTest(){
	cout << "\n=====" << __func__ << "=====\n";
	int n = 3;
	int m = 3;
	//int dynamicArr[n][m] = {{1,2,3}, {4,5,6},{7,8,9}}; //컴파일 불가능 
	int dynamicArr[n][m];
	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			dynamicArr[i][j] = n*i + j +1 ;
		}	
	}
	cout << "\n sizeof dynamicArr:" << sizeof(dynamicArr) << '\n'; // 1?
	
	// [Error] no matching function for call to 'printArrayForStaticArray(int [n][m])'
	// printArrayForStaticArray(dynamicArr);
	
	printArrayForDynamicArray(&dynamicArr[0][0],n,m);
}
int main(){
	//https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
	staticMultiDimensionalArrayTest();
	dynamicMultiDimensionalArrayTest();
	return 0;
}
