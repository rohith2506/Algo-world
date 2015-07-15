#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	int t,c,n,m;
	cin>>t;
	while(t--){
		cin>>c>>n>>m;
		int total = 0;
		total = total + (c/n);
		int q = c/n;
		if(q < m)
			cout<<total<<endl;
		else{
			while(q/m > 0){
				total = total +  q/m;
				q = q%m;
				q = q + 1;
				}
				
			cout<<total<<endl;
		   }
           }
        return 0;
	}	
