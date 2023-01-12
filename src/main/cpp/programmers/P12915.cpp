#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    auto cmpLambda = [=](string a, string b){
        if(a[n] == b[n]) return a < b;
        return a[n] < b[n];
    };
    sort(strings.begin(), strings.end(), cmpLambda);
    return strings;
}
int main(){
	return 0;
}

