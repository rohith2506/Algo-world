/*
Implemented using naive approach
@Author : Rohit
*/

#include <iostream>
#include <stdio.h>
#include <queue>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

struct topic_point{
	double x;
	double y;
}pt;

struct dist{
	int index;
	double distance;
};


bool operator<(const dist &a, const dist &b){
	return a.distance < b.distance;
}


double calculate_distance(double x1,double y1,double x2,double y2){
	return sqrt(((x1-x2)*(x1-x2)) + ((y1-y2) * (y1-y2)));
}


vector<int> solvefortopic(vector<topic_point> v,double resx,double resy,int n){

	set<dist> s;
	set<dist>::iterator it;
		
	for(int i=0;i<v.size();i++){
		double Distance = calculate_distance(v[i].x,v[i].y,resx,resy);
		dist d;
		d.index = i;
		d.distance = Distance;
		s.insert(d);
	}

	vector<int> result;

	int temp = 0;

	for(it = s.begin(); it!=s.end() && temp < n ; it++){
		dist d = (*it);
		result.push_back(d.index);
		temp++;
		}
	return result;
}


bool notpresent(int qid, vector<int> result){	
	for(int i=0;i<result.size();i++){
		if(result[i] == qid)
			return false;
		}
	
	return true;
}
		
vector<int> solvefortopic2(vector<vector<int> > topics, vector<topic_point> v,double resx,double resy,int n){
	
	set<dist> s;
        set<dist>::iterator it;

        for(int i=0;i<v.size();i++){
                double Distance = calculate_distance(v[i].x,v[i].y,resx,resy);
                dist d;
                d.index = i;
                d.distance = Distance;
                s.insert(d);
        }

//	for(it=s.begin();it!=s.end();it++)
//		cout<<(*it).index<<" "<<(*it).distance<<endl;

        vector<int> result;
        int temp = 0;

	for(it = s.begin(); it!=s.end(); it++){
		dist d = (*it);
		int j ;
		for(j=topics[d.index].size()-1;j>=0;j--){
//			cout<<topics[d.index][j]<<" ";
                	if(notpresent(topics[d.index][j],result))
                        	result.push_back(topics[d.index][j]);
                	if(result.size() == n)
				break;
                	}
//		cout<<endl;
//		cout<<j<<endl;
		if(j != -1)
			break;
		}

	return result;
}
		
			
int main(){
	int T,Q,N;
	cin>>T>>Q>>N;

	vector<topic_point> v;
	
	for(int i=0;i<T;i++){
		topic_point pt;
		int id;
		cin>>id;
		double xco,yco;
		cin>>xco>>yco;
		pt.x = xco;
		pt.y = yco;
		v.push_back(pt);
		}

	vector<vector<int> > questions;

	for(int i=0;i<Q;i++){
		vector<int> temp;
		int id;
		cin>>id;
		int number;
		cin>>number;
		for(int j=0;j<number;j++){
			int topicid;
			cin>>topicid;
			temp.push_back(topicid);
			}
		questions.push_back(temp);
	}


	vector<vector<int> > topics;

	for(int i=0;i<T;i++){
		vector<int> temp;
		topics.push_back(temp);
		}


	for(int i=0;i<topics.size();i++){
		for(int j=0;j<questions.size();j++){
			for(int k=0;k<questions[j].size();k++){
				if(questions[j][k] == i)
					topics[i].push_back(j);
					}
				}
			}


/*	for(int i=0;i<topics.size();i++){
		for(int j=0;j<topics[i].size();j++){
			cout<<topics[i][j]<<" ";
			}
		cout<<endl;
		}
*/
	
	for(int i=0;i<N;i++){
		char ch;
		cin >> ch;

		if(ch == 't'){
		
			int res;
			cin>>res;

			double resx,resy;
			cin>>resx>>resy;

			vector<int> RESULT = solvefortopic(v, resx, resy, res);
			
			for(int i=0;i<RESULT.size();i++)
				cout<<RESULT[i]<<" ";
				cout<<endl;

			//hola this is completed..:-)
		}

		else{
		
			int res;
			cin>>res;

			double resx,resy;
			cin>>resx>>resy;

			vector<int> RESULT = solvefortopic2(topics, v, resx, resy, res);
		
			for(int i=0;i<RESULT.size();i++)
				cout<<RESULT[i]<<" ";
				cout<<endl;
			}	
		}

	return 0;
}
