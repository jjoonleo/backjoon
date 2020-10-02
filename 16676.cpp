#include<stdio.h>
int main(){
	int N, cnt = 1;
	bool flag = true;
	
	scanf("%d", &N);
	
	for(int i = N; i >= 10; i/=10,cnt*=10);
	for(int i = N; ; i-=cnt,cnt/=10){
		//printf("%d - %d = %d\n", i, cnt, i / cnt);
		if(i / cnt > 1){
			flag = true;
			break;
		}
		if(i / cnt == 0){
			flag = false;
			break;
		}
		if(i < 10){
			break;
		}
	}
	cnt = 1;
	for(int i = N; i >= 10; i/=10,cnt++);
	if(flag)
		printf("%d",cnt);	
	else{
		
		printf("%d", cnt-1);
	}
}

