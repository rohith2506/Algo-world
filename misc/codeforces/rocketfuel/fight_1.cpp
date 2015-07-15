#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
long int MAX = 2000001*15;

using namespace std;

int power(int a,int b){
	int temp = 1;
	for(int i=0;i<b;i++) temp = temp * a;
	return temp;
}

struct players{
	int points;
	int effort;
};

struct players_2{
	int points;
	int effort;
	char game;
	bool operator() (players_2 i,players_2 j) { return (i.points>j.points);}
}plrs;

vector<int> binary(int num){
	vector<int> v;
	while(num > 0){
		v.push_back(num%2);
		num = num/2;
	}
	return v;
}

long int mini(long int a,long int b){
	if (a < b)
		return a;
	else
		return b;
}

int main(){
	int n,k;
	cin >> n >> k;
	int Max = power(2,n);

	vector<players> v;
	for(int i=0;i<n;i++){
		players p;
		cin >> p.points;
		cin >> p.effort;
		v.push_back(p);
	}

	long int mineffort = MAX;
	for(int i=0;i<Max;i++){
		int temp_effort = 0;
		long int temp_points = 0;
		vector<players_2> v2;
		for(int j=0;j<n;j++){
			players_2 p;
			p.points = v[j].points;
			p.effort = v[j].effort;
			p.game  = 'W';
			v2.push_back(p);
		}
		vector<int> binary_form = binary(i);
			
		for(int j=0;j<binary_form.size();j++){
			if(binary_form[j] == 1){
				v2[j].points = v2[j].points - 1;
				temp_points = temp_points + 1;
				temp_effort =  temp_effort + v2[j].effort;
				v2[j].game = 'L';
			}
		}

		for(int j=0;j<v2.size();j++){
			if(v2[j].game == 'W')
				v2[j].points = v2[j].points + 1;
		}

		sort(v2.begin(), v2.end(),plrs);

//		cout<<"Points tally"<<endl;
//		for(int j=0;j<v2.size();j++)
//			cout<<v2[j].points<<" "<<v2[j].effort<<" "<<v2[j].game<<endl;


		int rank = 1;
		for(int j=v2.size()-1;j>=0;j--){
			if(v2[j].points > temp_points)
				rank = rank + 1;
			else if(v2[j].points == temp_points  && v2[j].game =='W')
				rank = rank + 1;
		}

//		cout << temp_points << " " << temp_effort << endl;
//		cout << rank << endl;

//		cout<<endl;
//		cout<<endl;

		if(rank <= k)
			mineffort = mini(temp_effort,mineffort);
	}
	if(mineffort == MAX)
		cout<<"-1"<<endl;
	else
		cout<<mineffort<<endl;
	return 0;
}
