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
	// �ѱ��� ���ڹ迭�󿡼� �ѱ��ڿ� 2�ڸ��� �����ϰ� ����.  
	string s = "�ȳ��ϼ��� ū���̴� ŷ�����ʷ� õ���Դϴ� �����̿���!";
	string d = " ";
	vector<string> a = split(s, d);
	string s2 = "aaaa bbb ccccc ee ddddddddd!";
	vector<string> c = split(s2, d);
	// 4 3 5 2 ���⸦ ã�� �ش� ù��° �ε����� ��ȯ�Ѵ�.
	// ���ڿ��� erase�Ǳ� ������ aaaa, bb �̷������� �Ǵ� �͵� ����.
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
		// ���� ó���� ã�� index�� return 
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
