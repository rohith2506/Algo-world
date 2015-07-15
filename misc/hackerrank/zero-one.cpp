/*
Solution got it
but TLE
have to think about it later
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#define MAX 16
using namespace std;
#include <ctime>
#include <unistd.h>

void split(vector<vector<int> > &v1,vector<int> v){
	int num = v.size();
	int split_point = num/2;

	if(split_point > 0){
		if(v.size() <= MAX){
			v1.push_back(v);
			return ;
		}
		else{
			vector<int> temp1(v.begin(),v.begin()+split_point);
			vector<int> temp2(v.begin()+split_point,v.end());

			split(v1,temp1);
			split(v1,temp2);
		}
	}
}

vector<int> go(int n){
	vector<int> res;
	res.push_back(9);

	queue<vector<int> > q;
	q.push(res);

	while(!q.empty()){
		vector<int> temp_res = q.front();
		q.pop();
		long long int res1=0,res2=0,res3=0;
		if(temp_res.size()<=MAX){
			for(int i=0;i<temp_res.size();i++)
				res3 = (res3*10) + temp_res[i];
//			cout<<"res3 was: "<<res3<<endl;
			if(res3%n == 0) return temp_res;
			else{
				vector<int> push1(temp_res);
				vector<int> push2(temp_res);
				push2.push_back(0);
				push1.push_back(9);


//				for(int i=0;i<push2.size();i++)cout<<push2[i];
//				cout<<endl;

//				for(int i=0;i<push1.size();i++)cout<<push1[i];
//				cout<<endl;


				q.push(push2);
				q.push(push1);
			}
		}
		else{
	//		sleep(1);
			vector<vector<int> > v;

//			for(int i=0;i<temp_res.size();i++)
//				cout<<temp_res[i];
//			cout<<endl;


			int sz = temp_res.size()-1;
			split(v,temp_res);


//			for(int i=0;i<temp_res.size();i++)
//				cout<<temp_res[i];
//			cout<<endl;

		//	sleep(2);


			vector<long long int> result;
			for(int i=0;i<v.size();i++){
				long long int temp_num = 0;
				for(int j=0;j<v[i].size();j++){
					if(v[i][j] == 1)
						temp_num = temp_num + pow(10,sz);
					sz--;
				}
				result.push_back(temp_num);
			}


			int rem = 0;
			for(int i=0;i<result.size();i++)
				rem = rem + (result[i]%n);	

			if(rem%n == 0) return temp_res;
			else{
				vector<int> push1(temp_res);
				vector<int> push2(temp_res);
				push2.push_back(0);
				push1.push_back(9);
				
				for(int i=0;i<push2.size();i++)cout<<push2[i];
				cout<<endl;

				for(int i=0;i<push1.size();i++)cout<<push1[i];
				cout<<endl;

				q.push(push2);
				q.push(push1);
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> RESULT = go(n);
//		cout<<"iam here"<<endl;
	for(int i=0;i<RESULT.size();i++)cout<<RESULT[i];
		cout<<endl;
	}
	return 0;
}