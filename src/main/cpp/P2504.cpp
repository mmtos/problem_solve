#include <iostream>
#include <stack>

using namespace std;

const int p = 0;
const int m = 1;
int oper_mode = p;
bool prev_pair = false;

int main(){
	//#스택(짝맞추기) #답지 
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	stack<int> ST;
	stack<int> OP;
	cin >> s;
	int val = 1; // 곱해질값 
	int sum = 0;
	for(int i=0;i<s.size();i++){
		if(s[i] == '('){
			val *= 2;
			ST.push(s[i]);
		}else if(s[i] == '['){
			val *= 3;
			ST.push(s[i]);
		}else if(s[i] == ')'){
			if(ST.empty() || ST.top() != '('){
				cout << 0;
				return 0;
			}
			// top은 s[i-1]과 다를 수 있다.  
			if(s[i-1] == '(') sum += val;
			ST.pop();
			val /= 2;
		}else if(s[i] == ']'){
			if(ST.empty() || ST.top() != '['){
				cout << 0;
				return 0;
			}
			if(s[i-1] == '[') sum += val;
			ST.pop();
			val /= 3;
		}
	}
	if(!ST.empty()) {
		cout << 0;
		return 0;
	}
	cout << sum;
	return 0;
	 
//	while(!OP.empty()){
//		cout << OP.top() << " ";
//		OP.pop();
//	}
	// 2 3 3 * + 2 * 3 2 * +
	// 22 3 2 * +
	// 22 6 +
	// 28
	// prev matched 
	
	// 값을 같이 가지고 있는다 ?
	//  ( 2 ( 2 ) [ 3 [ 3 ] ] ) ( 2 [ 3 ] )
	// 2(2()3[3[]])2(3[])
	// 2(
	// stk = 1 
	// 2(2(
	// stk = 2
	// 2(2()
	// 2(
	// stk = 1 temp = 2
	// 2(3[
	// stk = 2
	// 2(3[3[ 
	// stk = 3
	// 2(3[3[]
	// 2(3[
	// stk = 2 
	// 2(3[]
	// 2(
	// 2()
	// . 
	// 2(
	// 2(3[
	// 2(3[]
	// 2(
	// 2()
	// .
//	cout << (int) '+'; // 43
}
