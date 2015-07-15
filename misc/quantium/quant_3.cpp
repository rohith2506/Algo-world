#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;



int main(){
	int k;
	string str;
	cin>>k>>str;

	int len=str.length();
	int i,j,x,l,m,mismatch,count,r;
	count=0;

 for(i=0;i<len-1;i++)
   for(j=i+1;j<len;j++)
   {  
   	 mismatch=0;
     for (r=0; r<len-j; ++r)
	{
     if (str[i+r] != str[j+r])
     {
           ++mismatch;
           if (mismatch > k)
                break;
      }
      ++count;
 	}
  }
	cout<<count<<endl;
	return 0;
}
