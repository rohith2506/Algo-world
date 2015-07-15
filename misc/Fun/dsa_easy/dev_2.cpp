#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int go(vector<int> v1,int N,int dist){
vector<int> v;
v.push_back(0);
for(int i=0;i<v1.size();i++)
	v.push_back(v1[i]);
v.push_back(dist);
int M = N - 1;
sort(v.begin(),v.end()); 
vector<int> diff;
for(int i=0;i<v.size()-1;i++)
	diff.push_back(v[i+1] - v[i]);

int max = (v[v.size()-1]-v[0])/M; 
vector<int> result(v);
int count ;
for (int i = 0; i < v.size()-1; i++){
    count = count + diff[i];
    if (v.size() - i == M - 1 || count >= max){ 
        result.push_back(count);
        count = 0;
        M--;
    }
}
int maxi = 0;
for(int i=0;i<result.size();i++)
	maxi = std::max(maxi,result[i]);
return maxi;
}

int main(){
	int n;
	cin >> n;
	vector<int> v1(n);
	for(int i=0;i<n;i++)
		cin >> v1[i];
	int N;
	cin >> N;
	int dist;
	cin >> dist;
	cout << go(v1,N,dist) << endl;
	return 0;
}
