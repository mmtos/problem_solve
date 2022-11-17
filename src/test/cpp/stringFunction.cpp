#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string gStr = "this is global variable";

// erase, length (length vs size ?) 
vector<string> split(string input, string delimiter){
	vector<string> ret;
	ll pos = 0;
	string token = "";
	while((pos = input.find(delimiter)) != string::npos){
		cout << "POS : " << pos << '\n';
		token = input.substr(0,pos);
		ret.push_back(token);
		input.erase(0,pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}

void splitTest(){
	// 한글은 문자배열상에서 한글자에 2자리씩 차지하고 있음.  
	string s = "안녕하세요 큰돌이는 킹갓제너럴 천재입니다 정말이에요!";
	string d = " ";
	vector<string> a = split(s, d);
	string s2 = "aaaa bbb ccccc ee ddddddddd!";
	vector<string> c = split(s2, d);
	// 4 3 5 2 띄어쓰기를 찾아 해당 첫번째 인덱스를 반환한다.
	// 문자열이 erase되기 때문에 aaaa, bb 이런식으로 되는 것도 생각.
	for(string b : a) {
		cout << b << "\n";
	}
}

int stringToInt(string target){
	return atoi(target.c_str());
} 

void stringToIntTest(){
	cout << stringToInt("123") << "\n";
	cout << stringToInt("abc") << "\n";
}

//reverse find substr begin end 
int main(){
	cout << gStr << "\n";
	if(gStr.find("is") != string::npos){
		// 가장 처음에 찾은 index를 return 
		cout << gStr.find("is") << "\n";
		cout << gStr.find("that") << "\n";
		cout << string::npos << "\n";
	}
	
	cout << gStr.substr(8,6) << "\n";
	reverse(gStr.begin(),gStr.end());
	cout << gStr << "\n";
	
	splitTest();
	stringToIntTest();
}
