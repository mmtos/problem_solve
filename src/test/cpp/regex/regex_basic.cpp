#include<string>
#include <iostream>
#include <regex>

using namespace std;

int main(){
	string pattern = "a*d";
	cout << pattern.find('*');
	pattern.insert(pattern.find('*'),".");
	cout << pattern;
	regex r(pattern);
	cout << boolalpha << regex_match("afdfaffd", r) << '\n';
	return 0;
}
