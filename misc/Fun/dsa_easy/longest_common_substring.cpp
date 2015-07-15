#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longest_common_substring(string s1,string s2,int startx,int starty,int m,int n){
	int table[m+1][n+1];
	int result=0;

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
				table[i][j]=0;
			else if(s1[i-1]==s2[j-1]){
				table[i][j]=table[i-1][j-1]+1;
				if(table[i][j] > result){
					result = table[i][j];
					startx = i;
					starty = j;
				}
		    }
			else
				table[i][j]=0;
		}
	}


	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}




	string res = s1.substr(startx-result,result);
	return res;
}


int main(){
	vector<string> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		v.push_back(x);
	}

	int startx,starty;
	string res;
	res = longest_common_substring(v[0],v[1],startx,starty,v[0].length(),v[1].length());		

	for(int i=2;i<v.size();i++)
	res = longest_common_substring(res,v[i],startx,starty,res.length(),v[i].length());

	cout<<res<<endl;
	return 0;
}