#include <list>
#include <iostream>
#include <string>

using namespace std;
/*
dmih
7
B
B
P x
L
B
B
B
*/
int main(){
	// #연결리스트
	string s;
	int M;
	cin >> s >> M;
	list<int> char_list;
	for(int i=0;i<s.size();i++){
		char_list.push_back(s[i]);
	}
	auto cursor = char_list.end();
	while(M--){
		char oper;
		char add_char;
		cin >> oper;
		if(oper == 'L' && cursor != char_list.begin()) cursor--;	
		else if (oper == 'D' && cursor != char_list.end()) cursor++;
		else if(oper == 'B' && cursor != char_list.begin()) {
			cursor--;
			cursor = char_list.erase(cursor);
		}
		else if(oper == 'P'){
			cin >> add_char;
			char_list.insert(cursor,(int) add_char);
		}
	}
	for(int c : char_list){
		cout << (char) c;
	}
	return 0; 
}
