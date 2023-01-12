#include <string>
#include <tuple>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

const string insertOper = "I";
const string deleteOper = "D";
 

pair<string, int> toPair(string operation){
	string a,b;
	int pos = operation.find(" ");
	if(pos != string::npos){
		a = operation.substr(0,pos);
		b = operation.substr(pos+1, operation.end()- operation.begin());
		
	}
	return {a, stoi(b)};
}
vector<int> solution(vector<string> operations) {
	
	string oper;
	int num;
	deque<int> d;
	
    for(string operation : operations){
		tie(oper, num) = toPair(operation);
		if(oper.compare(insertOper) == 0 ){
			d.push_back(num);
			sort(d.begin(),d.end());
		}else if(oper.compare(deleteOper) == 0 ){
			if(d.size() == 0 ) continue;
			if(num == -1){
				d.pop_front();
			}else {
				d.pop_back();
			}
		}
	}
    if(d.size() == 0) return {0,0};
    return {d.back(), d.front()};
}

int main(){
	string oper;
	int num;
	deque<int> d;
	
	//vector<string> operations = {"I -23","D -1","D 1","D -1","I 2242"};
	vector<string> operations = {"I -23","I 2242", "D -1"};
	vector<int> answer = solution(operations);
	
	for(int a : answer ) cout << a << ",";
	return 0;
}

