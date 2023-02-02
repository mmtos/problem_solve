#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int top = -1;
	int max;
	scanf("%d", &max);
	int a[max];
	fill(a, a+max, -999);
	
	for(int i=0; i < max ; i++){
		char s[6];
		int d;
		scanf("%s", s);
		if(strcmp(s, "push") == 0){
			scanf("%d", &d);
			top = top + 1;
			a[top] = d;
		}else if(strcmp(s, "pop") == 0){
			if(top == -1){
				printf("%d\n", -1);			
			}else{
				printf("%d\n",a[top]);
				top = top - 1;
			}
		}else if(strcmp(s, "size") == 0){
			printf("%d\n",top+1);
		}else if(strcmp(s, "empty") == 0){
			printf("%d\n", 1 - bool(top+1));
		}else if(strcmp(s, "top") == 0){
			if(top == -1){
				printf("%d\n", -1);			
			}else{
				printf("%d\n",a[top]);
			}
		}
	}
	
	return 0;
	
}
