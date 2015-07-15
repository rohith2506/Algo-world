#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;

struct values{
	string name;
	int xco;
	int yco;
	int price;
	int decay;
};

struct result{
	int xco;
	int yco;
	int rent;
	int dist;
};

struct comp{
    bool operator()(const result& r1,const result& r2){
      	if(r1.dist < r2.dist)
      		return true;
};

int calc(int xpos,int ypos,vector<values> amenities){
	int temp_amt = 0;
	for(int i=0;i<amenities.size();i++){
		int l = abs(amenities[i].xco-xpos) + abs(amenities[i].yco-ypos);
		int val = (amenities[i].price - (l * amenities[i].decay));
		if(val<0) val = 0;
		temp_amt = temp_amt + val;
	}
	return temp_amt;
}

int main(){
	int amount;
	scanf("%d",&amount);
	int sz;
	scanf("%d",&sz);

	vector<vector<bool> > empty;

	for(int i=0;i<sz;i++){
		vector<bool> temp;
		for(int j=0;j<sz;j++)
			temp.push_back(true);
		empty.push_back(temp);
	}

	int pxco,pyco;
	scanf("%d%d",&pxco,&pyco);
	empty[pxco][pyco]=false;
	int cxco,cyco;
	scanf("%d%d",&cxco,&cyco);
	empty[cxco][cyco]=false;

	int num;
	scanf("%d",&num);
	vector<values> amenities;

	for(int i=0;i<num;i++){
		values v;
		cin>>v.name>>v.xco>>v.yco>>v.price>>v.decay;
		empty[v.xco][v.yco]=false;
		amenities.push_back(v);
	}

	vector<result> res;

	for(int i=0;i<empty.size();i++){
		for(int j=0;j<empty[i].size();j++){
			if(empty[i][j] == true){
				int temp_amount = calc(i,j,amenities);
				cout<<temp_amount<<endl;
				if(temp_amount < amount){
					result r;
					r.xco = i;
					r.yco = j;
					r.rent = temp_amount;
					int val1 = abs(pxco-i) + abs(pyco-j);
					int val2 = abs(cxco-i) + abs(cyco-j);
					r.dist = abs(val1 - val2);
					res.push_back(r);
				}
			}
		}
	}

	if(res.size()>0){
		int sze = res.size();
		sort(res.begin(),res.end(),comp());

		for(int i=0;i<res.size();i++)
			cout<<res[i].xco<<" "<<res[i].yco<<" "<<res[i].rent<<" "<<res[i].dist<<endl;

		printf("(%d,%d) : %d\n",res[res.size()-1].xco,res[res.size()-1].yco,res[res.size()-1].rent);
	}
	else
		printf("NO\n");
	return 0;
}