/*
	This contains all header notations required for all c++ files written here.
	@Author: Rohith
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <map>
#include <stack>
#include <queue>
#define pb(x) push_back(x)
using namespace std;


template <typename T>
void print_vector(vector<T> v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename T>
void print_2d_vector(vector<vector<T> > v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
