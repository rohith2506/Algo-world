#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

class IDNumberVerification
{
public:

   int powe(int x,int y){
		int res=1;
		for(int i=0;i<y;i++)
			res=res*x;	
		return res;
		}
		
	string verify(string id, vector <string> regionCodes)
	{
		string x=id.substr(0,6);
		int flag=1;
		for(int i=0;i<regionCodes.size();i++){
			if(regionCodes[i]!=x)
				flag=0;
				}
		if(flag==0){
			cout<<"iam here 1"<<endl;
			return "INVALID";
			}
		else{
				flag=0;
				x=id.substr(6,8);
				int year=0,month=0,day=0;
				
				for(int i=0;i<4;i++){
					year=(year*10)+((int)(x[i])-'0');
					}
				for(int i=4;i<6;i++){
					month=(month*10)+((int)(x[i])-'0');
					}
				for(int i=6;i<8;i++){
					day=(day*10)+((int)(x[i])-'0');
					}
				
				if(year%4==0 || year%400==0){
						if(month>=0 && month<=12){
							if(month==1 || month==3 || month==5 || month==7 || month==8 ||month==10 || month==12){
									if(day>=1 && day<=31)
											flag=1;
											}
							else{
									if(month==2){
											if(day>=1 && day<=29)
												flag=1;
												}
									else{
									if(day>=1 && day<=30)
											flag=1;
										}
								}
						}
				  }
						   			
				else{
						if(month>=0 && month<=12){
							if(month==1 || month==3 || month==5 || month==7 || month==8 ||month==10 || month==12){
									if(day>=1 && day<=31)
											flag=1;
											}
							else{
									if(month==2){
											if(day>=1 && day<=28)
												flag=1;
												}
									else{
									if(day>=1 && day<=30)
											flag=1;
										}
								}
						}
					}
			
				if(flag==0){
					cout<<"iam here 2"<<endl;
					return "INVALID";
					}
					
				else{
						x=id.substr(14,3);
						int male=0;
						for(int i=0;i<x.length();i++){
							male=male*10+((int)(x[i])-'0');
							}
						
						if(male==0){
							cout<<"iam here 3"<<endl;
							return "INVALID";
							}
						else if(male%2==0){
								int len=id.length();
								long int res=0;
								int p;
								if(id[len-1]=='X')
										p=10;
								else
										p=(int)(id[len-1])-'0';
								res=p;	
								for(int i=0;i<id.length()-1;i++){
										res=res+(int)(id[i])-'0')*powe(2,len);
										len--;
										}
								if(res%11==1)
									return "FEMALE";
								else{
									cout<<"iam here 4"<<endl;
									return "INVALID";
									}
								}
						else{
								int len=id.length();
								long int res=0;
								int p;
								if(id[len-1]=='X')
										p=10;
								else
										p=(int)(id[len-1])-'0';
								res=p;	
								for(int i=0;i<id.length()-1;i++){
										res=res+(int)(id[i])-'0')*powe(2,len);
										len--;
										}
								cout<<res<<endl;
								if(res%11==1)
									return "MALE";
								else{
									cout<<"iam here 5"<<endl;
									return "INVALID";	
									}
							}
					}
				}		
		}
};


// Edited by VimCoder 0.3.5
// http://github.com/chazmcgarvey/vimcoder

