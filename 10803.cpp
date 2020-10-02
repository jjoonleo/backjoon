#include<stdio.h>
#include<iostream>
#include<vector>

#define INF 98765432

using namespace std;

int solve(int v, int h);
int cache[10001][100];
int cnt= 0;
void divisor(int x,int y, vector<int>&ret);
void* target;
int main(){
	for(int i = 0; i < 10001; i++){
		for(int j = 0; j < 100; j++){
			cache[i][j] = -1;
		}
	}
	int h,v;
	scanf("%d", &v);
	scanf("%d", &h);
	//v=9999,h=100;
	printf("%d",solve(v,h));
	
	
	return 0;
	
}

int solve(int v, int h){
	printf("-----------------\n");
	printf("v : %d, h : %d\n",v,h);
//	if(v<h)swap(v,h);
	if(v == 0 || h == 0){
		printf("******************0\n");
		return 0;
	}
    if(v%h==0){
		printf("******************%d\n", v/h);
		cnt++;
		if(cnt > 10) goto *target;
		return v/h;
	}
//	if(v>h*3) return solve(v-h,h)+1;
	
	int& ret= cache[v][h];
	if(ret != -1 ) return ret;
	//else if(cache[h][v]!= -1&&v<=100)return cache[h][v];
	int best = INF;
	vector<int> di;
	
	divisor(h,v,di);
	for(int i = 0; i < di.size(); i++){
		for(int j = 0; j < di.size(); j++){
			printf("%d \n",di[j]);
		}
		printf("v : %d, h : %d\n", v - di[i],h);
		best = min(best, solve(v-di[i], h)+h/di[i]);
	}
	printf("\n");
	printf("second for v:%d,h:%d\n\n",v,h);
	divisor(v,h,di);
	for(int i = 0; i < di.size(); i++){
		for(int j = 0; j < di.size(); j++){
			printf("%d \n",di[j]);
		}
		printf("v : %d, h : %d  %d\n", v,h - di[i],di.size());
		best = min(best, solve(v, h - di[i])+v/di[i]);
	}
	printf("******************\n");
	
	return ret = best;
}
void divisor(int x,int y, vector<int>&ret){
	int j = 0;
	ret.resize(0);
	x>y?j = y:j = x;
	for(int i = j; i >= 2;i--){
		if(x%i==0){
			printf(" %d\n",i);
			ret.push_back(i);
			
		}
	}
	
}
