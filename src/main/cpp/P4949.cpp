#include <iostream>
#include <stack>

using namespace std;

int main(){
	//#스택(짝맞추기) 
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	while(true){
		getline(cin,s);
		if(s == ".") break;
		stack<char> ST;
		for(int i=0;i<s.size();i++){
			if(s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']') continue;
			//cout << s[i] << " ";
			if(ST.empty()){
				ST.push(s[i]);
			}else{
				if(ST.top() == '(' && s[i] == ')'){
					ST.pop();
				}else if(ST.top() == '[' && s[i] == ']'){
					ST.pop();
				}else{
					ST.push(s[i]);
				}
			}
		}
		if(ST.empty()) cout << "yes" <<"\n";
		else cout <<"no" << "\n";	
	}
	return 0;
	
}
