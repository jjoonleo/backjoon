#include<stdio.h>

int rspToInt(char c){
	switch (c){
		case 82:
			return 0;
		case 83:
			return 1;
		case 80:
			return 2;
	}
}

int main(){
	const int R = 0, S = 1, P = 2;
	const int win[3] = { P, R, S};
	char arr[7];
	int MS[2], TK[2];
	for(int i = 0; i < 7; ++i){
		arr[i] = getchar();
	}
	MS[0] = rspToInt(arr[0]);
	MS[1] = rspToInt(arr[2]);
	TK[0] = rspToInt(arr[4]);
	TK[1] = rspToInt(arr[6]);
	
	if(MS[0] == MS[1]){
		if(TK[0] == win[MS[0]] || TK[1] == win[MS[0]]){
			printf("TK");
			return 0;
		}
	}
	if(TK[0] == TK[1]){
		if(MS[0] == win[TK[0]] || MS[1] == win[TK[0]]){
			printf("MS");
			return 0;
		}
	}
	printf("?");
}
