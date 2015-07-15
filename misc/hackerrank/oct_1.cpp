#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,c,m;
		scanf("%d%d%d",&n,&c,&m);
		int cnt = 0;	
		int wrappers = 0;
		while(n >= c){
			n = n - c;
			cnt++;
			wrappers++;
			if(wrappers == m){
				wrappers = 1;
				cnt++;
				}
			}
		cout<<cnt<<endl;
		}
	return 0;
	}						
