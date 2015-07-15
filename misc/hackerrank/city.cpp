#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#define INF 100000.0
using namespace std;

struct data{
	int idx;
	int cost;
};

int gcd (int n1, int n2) {
    return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
}

vector<int> go(vector<vector<int> > v,int index){
	stack<data> stk;
	data d;
	d.idx  = index;
	d.cost = 0;
	stk.push(d);
	int visited = 1;
	int cst,total;
	while(!stk.empty()){
		data dt = stk.top();
		stk.pop();
//		cout<<dt.idx<<" "<<dt.cost<<endl;
		if(dt.idx == index && visited!=1)
			break; 
		if(visited == 1){
			double tempcst = INF;
			int temp_idx,temp_cst;
			for(int j=0;j<v.size();j++){
				if(j!=dt.idx && j!=index){
	//				cout<<j<<" "<<v[dt.idx][j]<<endl;
					int tempsum = dt.cost + v[dt.idx][j];
					double avg = tempsum/(1.0*visited);
					if(avg < tempcst){
						tempcst = avg;
						temp_cst = tempsum;
						temp_idx = j;
					}
				}
			}
			cst = temp_cst;
			total = visited;
			data dt2;
			dt2.idx = temp_idx;
			dt2.cost = temp_cst;
			stk.push(dt2);
		}
		else{
			double tempcst = INF;
			int temp_idx,temp_cst;
			for(int j=0;j<v.size();j++){
				if(j!=dt.idx){
					int tempsum = dt.cost + v[dt.idx][j];
					double avg = tempsum/(1.0*visited);
					if(avg < tempcst){
						tempcst = avg;
						temp_cst = tempsum;
						temp_idx = j;
					}
				}
			}
			cst = temp_cst;
			total = visited;
			data dt2;
			dt2.idx = temp_idx;
			dt2.cost = temp_cst;
			stk.push(dt2);
		}
		visited++;
	}
	vector<int> res;
	int gcdnum = gcd(cst,total);
	cst = cst/gcdnum;
	total = total/gcdnum;
	res.push_back(cst);
	res.push_back(total);
	return res;
}


int main(){
		int n;
		cin >> n;
		vector<vector<int> > v(n,vector<int>(n));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> v[i][j];
			}
		}
		double minimum = INF;
		vector<int> main_res;
		for(int i=0;i<n;i++){
			vector<int> res = go(v,i);
			double res2 = res[0]/(1.0*res[1]);
//			cout<<res[0]<<" fugfb "<<res[1]<<endl;
			if(res2 < minimum){
				minimum = res2;
				main_res = res;
			}
		}
		cout<<main_res[0]<<"/"<<main_res[1]<<endl;
	return 0;
}