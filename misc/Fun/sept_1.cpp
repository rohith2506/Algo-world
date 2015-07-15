#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int max3=0;
		int max5=0;

		int temp3=0,temp5=n;
		
		do{
			if(temp5%5==0){
				if(temp3>max3){
					max3=temp3;
					max5=temp5;
				}
				else if(temp3>=max3){
						max3=temp3;
						max5=std::max(temp5,max5);
				}
				else{}
			}
			temp3=temp3+3;
			temp5=temp5-temp3;
		}while(temp3<=n);

		temp5=0;
		temp3=n;
	
		do{
			if(temp3%3==0){
				if(temp3>max3){
					max5=temp5;
					max3=temp3;
				}
				else if(temp3>=max3){
						max3=temp3;
						max5=std::max(temp5,max5);
				}
				else{}
			}
			temp5=temp5+5;
			temp3=temp3-temp5;
		}while(temp5<=n);

		if(max5 ==0 && max3 == 0)
			cout<<"-1"<<endl;
		else{
		//	cout<<max3<<" "<<max5<<endl;
			for(int i=0;i<max3;i++)
				cout<<"5";
			for(int i=0;i<max5;i++)
				cout<<"3";
			cout<<endl;
		}
	}
	return 0;
}