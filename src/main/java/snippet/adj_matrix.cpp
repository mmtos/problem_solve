#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int n, m;
void printMatrix(int *dArr, size_t rows, size_t cols){
	for(int i= 0 ; i < rows ;i++) {
		for(int j= 0 ; j < cols ;j++) {
			cout << *(dArr + i*rows + j) << ",";
		}
		cout << "\n";
	} 
}

/*
4 6
101111
101010
101011
111011
*/
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	int a[n][m];
	int* startPointer = &a[0][0];
	fill(startPointer,startPointer + n*m, 0);
	printMatrix(startPointer,n,m);
	
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j=0; j<m; j++){
			a[i][j] = s[j] - '0';	
		}	
	}
	
	printMatrix(startPointer,n,m);
	return 0;
}
