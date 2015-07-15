#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int t=0;
	cin>>t;
	double C,F,X;
	double tame;
	for(int z=1;z<=t;z++)
	{
		cin>>C>>F>>X;
		tame=0.0;
		double num_cookie=0.0;
		double curr=2.0;
		double tp,tn;
		while(1)
		{
			tp=tame+X/curr;
			tn=tame + C/curr + X/(curr+F);
			if(tp>tn)
				{
					tame=tame+C/curr;
					curr=curr+F;
				}
			else break;
		}
		printf("case #%d: %.7f\n",z,tp);
	}
return 0;
}