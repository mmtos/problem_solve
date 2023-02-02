#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int N; // N < õ�� - �ʹ� ũ�� 

int main(){
	// #�켱����ť
	cout << fixed;
	cout.precision(3);
	priority_queue<double, vector<double>, greater<double>> pq;
//	priority_queue<double, vector<double>, greater<double>> pq();
//	priority_queue<double> pq(); 

	cin >> N;
	for(int i=0; i<N; i++){
		double temp;
		cin >> temp;
		pq.push(temp);
	}
	for(int i=0;i<7;i++){
		cout << pq.top() << "\n"; pq.pop();
	}
	return 0;
}
