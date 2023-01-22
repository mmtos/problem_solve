#include <iostream>
using namespace std;

int N;
char rt, l, r;
int lc[27], rc[27];

void pre(int sub_root){
	cout << (char) (sub_root+'A'-1);
	if(lc[sub_root]) pre(lc[sub_root]);
	if(rc[sub_root]) pre(rc[sub_root]);
}
void in(int sub_root){
	if(lc[sub_root]) in(lc[sub_root]);
	cout << (char) (sub_root+'A'-1);
	if(rc[sub_root]) in(rc[sub_root]);
}
void post(int sub_root){
	if(lc[sub_root]) post(lc[sub_root]);
	if(rc[sub_root]) post(rc[sub_root]);
	cout << (char) (sub_root+'A'-1);
}
int main(){
	// #트리순회 #형변환 
	cin >> N;
	int temp_n = N;
	
	while(--temp_n){
		cin >> rt >> l >> r;
		if(l != '.') lc[rt-'A'+1] = l-'A'+1;
		if(r != '.') rc[rt-'A'+1] = r-'A'+1;	
	}
//	for(int i=1;i<=26;i++){
//		cout << lc[i];
//	}
//	cout << "\n";
//	for(int i=1;i<=26;i++){
//		cout << rc[i];
//	}
//	cout << "\n";
	pre(1);
	cout << "\n";
	in(1);
	cout << "\n";
	post(1);
}
