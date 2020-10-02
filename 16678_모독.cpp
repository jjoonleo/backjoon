#include<stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int N,a_in,sum = 0, sum2 = 0;
	vector<int> a;
	scanf("%d",&N);
	for(int i = 1; i <= N ; i++){
		scanf("%d",&a_in);
		a.push_back(a_in);
		sum+=a_in;
	}
	sort(a.begin(), a.end());  
	for(int i = 0; i < a.size() ; i++){
		printf("%d\n",a[i]);
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= i; j++){
			for(int x= 0; x < N; x++){
				if(a[x] < i)
				else sum2 += a[x] - j;
			}
		}
	}
}
