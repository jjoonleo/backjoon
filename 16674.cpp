#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	int N;
	vector<int> v;
	int arr[4] = {0,};
	scanf("%d",&N);
	while(N > 9){
		v.push_back(N%10);
		
		N=N/10;
	}
	v.push_back(N);
	for(int i = 0; i<v.size(); i++){
		switch (v[i]){
			case 0:
				arr[0]++;
				break;
			case 1:
				arr[1]++;
				break;
			case 2:
				arr[2]++;
				break;
			case 8:
				arr[3]++;
				break;
		}
	}
	//printf("%d %d %d %d",arr[0],arr[1],arr[2],arr[3]);
	
	if(arr[0]+arr[1]+arr[2]+arr[3] == v.size()){
		if(arr[0] != 0 &&arr[1] != 0 && arr[2] != 0 && arr[3] != 0){
			if(arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3]){
				printf("8");
			}else{
				printf("2");
			}
		}else {
			printf("1");
		}
	}else/*(arr[0] == 0 || arr[1] == 0 || arr[2] == 0 || arr[3] == 0)*/
	{
		printf("0");
	}
}
