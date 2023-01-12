#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solution(int price, int money, int count)
{
    ll answer = -1;
    ll rest = money;
    for(int i=1; i<=count; i++){
        rest -= i*price;
    }
    if(rest > 0) return 0;
    return -rest;
}

int main(){
	return 0;
}

