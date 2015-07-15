#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Robertherb{
	public:
		int getmax(int t,vector<int> a){
			int x=0,y=0;
			int dir=0;
			for(int i=0;i<t;i++){
				for(int j=0;j<a.size();j++){
					if(dir==0)
					  y+=a[j];
					else if(dir==1)
					  x+=a[j];
					else if(dir==2)
					  y-=a[j];
					else if(dir==3)
					  x-=a[j];
					else{}
					dir=(dir+a[j])%4;
					}
				}
			return (Math.abs(x)+Math.abs(y));
		}		
};
