#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#include <map>
#include <stdlib.h>
#define gc getchar_unlocked

using namespace std;

struct st{
	long int fr;
	string str;
};

struct res{
	double quality;
	string song;
};


inline int FAST_IO(){
	register int N,C;

	while((C=gc()) < '0');

	do{
	N = (N << 1) + (N << 3) + C- '0';
	}while((C=gc())>='0');
	
	return N;
}



int compare(const void *x,const void *y){
  res *e1 = (res *)x;
  res *e2 = (res *)y;
    return (*e2).quality - (*e1).quality;
}



int main(){
	int n,m;
	n = FAST_IO();
	m = FAST_IO();
	string temp;
	st s;
	vector<st> v;
	for(int i=0;i<n;i++){
		long int f = FAST_IO();
		cin>>temp;
		s.fr = f;
		s.str = temp;
		v.push_back(s);
	}

	res r[n];

	for(int i=0;i<v.size();i++){
		long int temp = v[0].fr;

		r[i].quality = v[i].fr / double(temp/(i+1)) ;
		r[i].song = v[i].str;

	}


	qsort(r,n,sizeof(res),compare);

	//for(int i=0;i<n;i++)
	//	cout<<r[i].quality<<" "<<r[i].song<<endl;

	for(int i=0;i<m;i++){
		cout<<r[i].song<<endl;
		cout<<endl;
	}
	
	return 0;
}
