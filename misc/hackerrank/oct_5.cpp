#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,m;
		cin>>a>>b>>m;
		int c = a;
		int d = b;
		
		int cnt = 1;
		int flag = 0;

		while(1){
			if(a == 0 && b == 0){
				flag = 1;
				break;
			}
			else if(a == 1 && b == 0)
				break;
			else{
				int x = ((a*c) + (5*b*d))%m;
				int y = ((a*d) + (b*c))%m;
				
				a = x;
				b = y;
				cnt++;
			    }
			}

		if(flag == 1)
			cout<<"-1"<<endl;
		else
			cout<<cnt<<endl;
		}

	return 0;
}
