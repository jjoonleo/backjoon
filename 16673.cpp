#include<stdio.h>

int main(){
	int C, K, P;
	int ret = 0;
	scanf("%d %d %d",&C,&K,&P);
	
	for(int i = 1; i <= C; i++){
		ret+=i*K+i*i*P;
	}
	printf("%d",ret);
}
