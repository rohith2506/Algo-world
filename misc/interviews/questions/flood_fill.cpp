#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <fstream>

using namespace std;

void flood_fill(vector<vector<int> > str, vector<vector<int> > v){

}



int main(){
	ifstream fin;
	fin.open("in.txt");
	string line;
	vector<vector<char> > v;
	while(std::getline(fin,line)){
		vector<char> temp;
		for(int i=0;i<line.length();i++)
			temp.push_back(line[i]);
		v.push_back(temp);
	}

	vector<vector<int> > v2(v.size(), vector<int>(v[0].size()));
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			if(v[i][j] == '1')
				v2[i][j] = 1;
			else if(v[i][j] == '0')
				v2[i][j] = 0;
			else
				v2[i][j] = -1;
		} 
	}

	flood_fill(v,2);
	return 0;
}