#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int power(int a,int b){
	int temp = 1;
	for(int i=1;i<=b;i++)
		temp = temp * a;
	return temp;
}

vector<int> split(int num){
	vector<int> v;
	while(num > 0){
		v.push_back(num%10);
		num = num/10;
	}
	return v;
}

int main(){
	int maxval = power(9,5);
	maxval = maxval * 10;
	cout<<maxval<<endl;
	int mainsum = 0;
	for(int num = 1;num<=maxval;num++){
		vector<int> v = split(num);
		if(v.size() > 1){
		int temp = 0;
		for(int i=0;i<v.size();i++) temp = temp + power(v[i],5);
		if(temp  == num){
			mainsum = mainsum + num;
			cout<<"iam"<<" "<<num<<" "<<temp<<endl;
			for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
			cout<<endl;
			}
		}
	}
	cout<<mainsum<<endl;
	return 0;
}