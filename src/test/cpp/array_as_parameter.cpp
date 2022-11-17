#include<bits/stdc++.h>
using namespace std;

void printArray1(int arr[]){
	cout << "\n=====" << __func__ << "=====\n";
	//포인터로만 전달되어 array size 정보를 잃는다  
	cout << sizeof(arr) << '\n';
}
void printArray2(int *arr){
	cout << "\n=====" << __func__ << "=====\n";
	//포인터로만 전달되어 array size 정보를 잃는다 
	cout << sizeof(arr) << '\n';
}
void printArray3(int arr[5]){
	cout << "\n=====" << __func__ << "=====\n";
	//포인터로만 전달되어 array size 정보를 잃는다 
	cout << sizeof(arr) << '\n';
	
	// 가능 
	for(int i= 0 ; i <5 ;i++) cout << arr[i] << ",";
	
	// 불가능 
//	for(int i : arr){
//		cout << i << ",";
//	}
}

//https://stackoverflow.com/questions/5724171/passing-an-array-by-reference
void printArray4(int (&arr)[5]){
	cout << "\n=====" << __func__ << "=====\n";

	cout << sizeof(arr) << '\n';
	for(int i= 0 ; i <5 ;i++) cout << arr[i] << ",";
	cout << "\n";
	for(int i : arr){
		cout << i << ",";
	}
}

//https://stackoverflow.com/questions/5724171/passing-an-array-by-reference
template<typename T, size_t S>
void printArray5(T (&arr)[S]){
	cout << "\n=====" << __func__ << "=====\n";
	cout << sizeof(arr) << '\n';
	for(int i= 0 ; i < S ;i++) cout << arr[i] << ",";
	cout << "\n";
	for(int i : arr){
		cout << i << ",";
	}
}

void arrayReferenceTest(){
	cout << "\n=====" << __func__ << "=====\n";
	int a[] = {1,2,3,4,5};
	cout << sizeof(a) << '\n';
	printArray1(a);
	printArray2(a);
	printArray3(a);
	printArray4(a);
	printArray5(a);
}

int main(){
	arrayReferenceTest();
	return 0;
}
