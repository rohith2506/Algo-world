/*
Problem statement:-
if a=1 ,b=2,z=26
Given string,find all possible codes that string can generate
for example 1123
->aabc(1,1,2,3)
-->(11,2,3)
-->(1,12,3)
-->(11,23)
and so on...

recursive method:some problems...:-(
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <ctime>
#define gc getchar_unlocked
using namespace std;

struct compute{
	int xco;
	int yco;
	string gen;
	};

string func(string str,int start,int depth){
	string temp = str.substr(start,depth);
	int num =0;
	string gen_str="";
	for(int i=0;i<temp.length();i++)
		num = (num*10)+((int)(temp[i])-48);

	char x = (char)(num+96);
	gen_str+=x;
	return gen_str;
}

vector<vector<string> > v;


void precompute(string str){
	int n = str.length();
	for(int i=0;i<n-1;i++){
		string temp  = func(str,i,1);
		string temp2 = func(str,i,2);
		//cout<<temp<<" "<<temp2<<endl;
		vector<string> temp_main;
		temp_main.push_back(temp);
		temp_main.push_back(temp2);
		v.push_back(temp_main);
		}
	vector<string> temp;
	string gen="";
	temp.push_back(func(str,n-1,1));
	temp.push_back(gen);
	v.push_back(temp);
}

void go(string str){
	stack<compute> stk;
	int x=0;int y=0;
	compute p;
	p.xco=x;
	p.yco=y;
	p.gen = v[x][y];
	stk.push(p);
	cout<<"#"<<p.gen<<endl;
	p.xco=x;
	p.yco=y+1;
	p.gen=v[x][y+1];
	stk.push(p);
	cout<<"#"<<p.gen<<endl;
	int len = str.length();

	while(!stk.empty()){
//		cout<<"iam here"<<endl;
		p = stk.top();
		if(p.xco==len-1 )
			cout<<p.gen<<endl;
		
		if(p.yco==0 && x<len-1){
			compute temp;
			temp.xco=p.xco+1;
			temp.yco=0;
			temp.gen=p.gen+v[temp.xco][temp.yco];
			cout<<"##"<<temp.gen<<endl;
			stk.push(temp);	
	
			temp.xco=p.xco+1;
			temp.yco=1;
			temp.gen=p.gen+v[temp.xco][temp.yco];
			cout<<"##"<<temp.gen<<endl;
			stk.push(temp);
			}
		if(p.yco==1 && x<len-2){
                  	  compute temp;
                          temp.xco=p.xco+2;
                          temp.yco=0;
                          temp.gen=p.gen+v[temp.xco][temp.yco];
                          cout<<"##"<<temp.gen<<endl; 
                          stk.push(temp);
  
                          temp.xco=p.xco+2;
                          temp.yco=1;
                          temp.gen=p.gen+v[temp.xco][temp.yco];
                          cout<<"##"<<temp.gen<<endl;
                          stk.push(temp);
//		          sleep(1);
			}
		stk.pop();
		}
	}	
			

int main(){
	string str;
	cin>>str;
	precompute(str);
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
				}
		cout<<endl;
		}
	cout<<v[3][1]<<endl;
	go(str);
	return 0;
	}

