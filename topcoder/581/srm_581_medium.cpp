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

class SurveillanceSystem
{
public:
	string getContainerInfo(string str, vector <int> r, int l)
	{	
		//now i contain bool array
		int len = str.length();
		int a[len];
		
		for(int i=0;i<len;i++)
			a[i]=0;
		
		sort(r.begin(),r.end());
		
		for(int i=r.size()-1;i>=0;i--){
			int val = r[i];
			int temparr[len];

			cout<<val<<endl;

			for(int j=0;j<len;j++)
				temparr[j]=0;
			
			int count2=0;
				
			for(int j=0;j<len-l+1;j++){
				string str2 = str.substr(j,l);
				cout<<str2<<endl;
				int count = 0;
				for(int k=0;k<str2.length();k++){
						if(str2[k]=='X')
							count++;
							}	
				if(count == val){
					for(int k=j;k<j+l;k++)
						temparr[k]++;
					count2++;
						}
				}
							
			for(int j=0;j<len;j++)
				cout<<temparr[j]<<" ";
				cout<<endl;
				
			cout<<count2<<endl;
			
			for(int j=0;j<len;j++){
				if(temparr[j]==count2)
					temparr[j]=2;
				else if(temparr[j]==0)
					temparr[j]=0;
				else
					temparr[j]=1;
					}
			
				for(int j=0;j<len;j++)
				cout<<temparr[j]<<" ";
				cout<<endl;
				
			for(int j=0;j<len;j++)
				 a[j] = std::max(temparr[j],a[j]);
			
		    	for(int j=0;j<len;j++)
				cout<<a[j]<<" ";
				cout<<endl;		
		
		   }
		   
	   string res;
	   for(int i=0;i<len;i++){
	   		if(a[i]==2)
	   			res+="+";
	   		else if(a[i]==1)
	   			res+="?";
	   		else
	   			res+="-";
	   	}
	   	
		return res;	   	
	}
};

int main(){
	string s;
	cin>>s;
	vector<int> reports;

	int l;

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		reports.push_back(x);
	}

	cin>>l;

	SurveillanceSystem st;
	cout<<st.getContainerInfo(s,reports,l)<<endl;
	return 0;
}

// Edited by VimCoder 0.3.5
// http://github.com/chazmcgarvey/vimcoder

