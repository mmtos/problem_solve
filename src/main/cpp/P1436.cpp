#include <string>
#include <iostream>
using namespace std;

int n, evil[10001];
 
int main(){
	// #��Ž #���Ʈ
	// �ִ� 666���� �غ��� �ϴ�. -> �����ɸ� 
	cin >> n; 
	int index = 1; 
	int count = 1;
	string temp;
	while(index < 10001){
		count++;
		temp = to_string(count);
		if(temp.find("666") != string::npos)
			evil[index++] = count;
	}	 
	cout << evil[n];
	return 0;
}

