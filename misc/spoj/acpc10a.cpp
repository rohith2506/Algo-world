#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main(){

	int a,b,c;
	cin>>a>>b>>c;

	while(a!=0 || b!=0 || c!=0){
		if(2*b == (a+c)){
			int term = a + 3*(b-a);
			cout<<"AP"<<" "<<term<<endl;
		}
		else{
			int term = a * pow(b/a,3);
			cout<<"GP"<<" "<<term<<endl;
		}
		
		cin>>a>>b>>c;
	}

	return 0;
}
			
			
