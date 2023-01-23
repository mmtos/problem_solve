#include<stack>
#include<iostream>
#define X first
#define Y second
using namespace std;
const int MX = 500002;
int N;
typedef long long ll;
void lecture_answer(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	stack<pair<int, int>> S;
	ll ans = 0;
	// 앞에서 부터 순회 
	while (N--) {
		int h;
		cin >> h;
		int cnt = 1;
		while (!S.empty() && S.top().X <= h) {
			ans += S.top().Y;
            if (S.top().X == h) cnt += S.top().Y;
			S.pop();
		}
		if (!S.empty()) ans++; 
		S.push({h, cnt});
	}
	cout << ans;
}

int main(){
	// #스택 
	lecture_answer();
	return 0;
} 
