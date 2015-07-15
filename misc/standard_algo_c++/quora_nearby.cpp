/*
Iam implementing this algorithm using heap
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define MAX 1000000000

using namespace std;


struct point{
	double x;
	double y;
	};

struct question_topics{
	vector<int> topiclist;
	};


int main(){
	int T,Q,N;
	scanf("%d%d%d",&T,&Q,&N);
	point p;
	//for each topic store a point too
	vector<point> pt;
	
	for(int i=0;i<T;i++){
		int tid;
		double xco,yco;
		scanf("%d",&tid);
		scanf("%f%f",&xco,&yco);
		p.x=xco;
		p.y=yco;
		pt.push_back(p);
		}

	//stored topics and their locations in vector pt

	
	question_topics q;
	
	vector<question_topics> qt;
	
	for(int i=0;i<Q:i++){
		int Qid;
		scanf("%d",&Qid);
		int number_of_topics;
		scanf("%d",&number_of_topics);
		vector<int> tlist;
		for(int j=0;j<number_of_topics;j++){
			int topic_id;
			scanf("%d",&topic_id);
			tlist.push_back(topic_id);
			}
		q.topiclist = tlist;
		qt.push_back(q);
		}

          
         for(int i=0;i<N;i++){
		char ch;
		int res;
		double x-co,y-co;
		cin>>ch;
		if(ch == 't'){
			//switch to topic  mode
			scanf("%d",&res);
			scanf("%f%f",&x-co,&y-co);
			}
		else{
			//switch to questions mode
			 scanf("%d",&res);
                         scanf("%f%f",&x-co,&y-co);
			}
		}


	return 0;
	}
	

		
	

