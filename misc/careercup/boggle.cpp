#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;


bool check(vector<vector<char> > v,string str){
		
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].size();j++){
					   int index=0;
					   stack<int> stkx;
					   stack<int> stky;

					   stkx.push(i);
					   stky.push(j);

					   while(!stkx.empty()){
					   		int x = stkx.top();
					   		int y = stky.top();
					   		
					   		stkx.pop();
					   		stky.pop();
//					   		cout<<i<<" "<<j<<endl;
					   		if(v[x][y]==str[index]){
					   			//cout<<v[x][y]<<endl;
					   			index++;
					   			//we got out letter..lets apply dfs here
					   			for(int k=-1;k<2;k++){
					   				for(int l=-1;l<2;l++){
					   					if(k==0 && l==0){}
					   					else{
					   					if(x+k>=0 && x+k<4 && y+l>=0 && y+l<4 && v[x+k][y+l]==str[index]){
					   						stkx.push(x+k);
					   						stky.push(y+l);
					   						}
					   					}
					   				}
					   			}

					   			if(index == str.length())
					   				return true;
					   		}
					   	}
					}		
			}

		return false;
		}


int main(){
	vector<vector<char> > v;

	for(int i=0;i<4;i++){
		vector<char> temp;
		for(int j=0;j<4;j++){
			char x;
			cin>>x;
			temp.push_back(x);
		}
		v.push_back(temp);
	}

	int n;
	do{
		string str;
		cin>>str;

		if(check(v,str))
			cout<<"This word is in board"<<endl;
		else
			cout<<"This word is not in board"<<endl;
	}while(1);
	return 0;
}
