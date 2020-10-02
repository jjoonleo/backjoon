#include <iostream>
#include <vector>
#include<stack>
#include<utility>
#include<algorithm>
using namespace std;
bool compare(pair<int, int>a,pair<int,int>b){
	return a.first<b.first;
}
bool compare2(pair<int, int>a,pair<int,int>b){
	return a.second>b.second;
}
int main() {
	vector<pair<int,int> > v;
	stack<int> s;
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int a,b,c,d;
		char ch;
		cin >> a >> ch >> b >> c >> ch >> d;
		v.push_back(make_pair(a*100+b,c*100+d));
	}
	stable_sort(v.begin(),v.end(),compare2);
	stable_sort(v.begin(),v.end(),compare);
	s.push(v[0].second);
	for(int i = 1; i < N; i++){
		if(v[i].first > s.top())
			//s.pop();
		s.push(v[i].second);
	}
	for(int i = 0; i < N; i++){
		int top = s.top();
		if(!s.empty())
			s.pop();
		if(s.top() <top){
			printf("No\n");
			return 0;
		}
	}printf("Yes\n");
	/*for(int i = 0; i < N; i++){
		printf("%d/%d\n",v[i].first,v[i].second);
	}	*/
}
