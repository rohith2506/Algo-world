#include <iostream>
#include <vector>
#define MAX 16

using namespace std;

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

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++) v[i]=i+1;

	vector<vector<int> > v1;
	split(v1,v);
	for(int i=0;i<v1.size();i++){
		for(int j=0;j<v1[i].size();j++){
			cout<<v1[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}