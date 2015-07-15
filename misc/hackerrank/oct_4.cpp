#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#define long int li;
using namespace std;

struct missile{
	int time;
	int frequency;
};

bool check(vector<missile> &hackerx,missile m){
	for(int i=0;i<hackerx.size();i++){
		int diff = abs(m.frequency-hackerx[i].frequency);
		if(diff <= abs(m.time - hackerx[i].time)){
			hackerx[i].time = m.time;
			hackerx[i].frequency =m.frequency;
			return true;
			}
		}
	return false;
}
	
int main(){
	int n;
	scanf("%d",&n);
	vector<missile> v;
	for(int i=0;i<n;i++){
		missile m;
		scanf("%d",&m.time);
		scanf("%d",&m.frequency);
		v.push_back(m);	
		};
	
	vector<missile> hackerx;
	hackerx.push_back(v[0]);
	for(int i=1;i<v.size();i++){
		if(check(hackerx,v[i])){			
		}
		else
			hackerx.push_back(v[i]);
		}
	
	cout<<hackerx.size()<<endl;
	return 0;
}
			
