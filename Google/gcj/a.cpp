#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	ifstream fin;
	int smax,ans,num;
	string str;
	
	for(int t = 1 ;t<=T;++t)
	{
		ans = num = 0;
		cin>>smax>>str;
		for(int i=0;i<=smax;++i)
		{
			if(num<i)
			{
				ans+=i-num;
				num=i;
			}
			num+= (int)str[i]-'0';

		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	} 
}