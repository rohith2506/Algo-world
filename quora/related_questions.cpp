/*
 * Expectation = Time Reading Q(i) + 1 / N ( visiting child nodes time) 
 * Where N = Number of child  nodes attached to that root we take
 * Iterate over all nodes and get minimum time.
 * 
 * @Author: ROHITH UPPALA
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#define INF 10e9

using namespace std;

void print_vector(vector<vector<int> > adj) {
	for(int i=0; i<adj.size(); i++) {
		for(int j=0; j<adj[i].size(); j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}

double calculate_expected_time(vector<vector<int> > adj, vector<int> time, int src) {
	vector<bool> visited(time.size()+1, false);
	map<int, double>::iterator it;
	stack< map<int, double> > stck;
	map<int, double> mp;
	mp[src] = time[src];
	stck.push(mp);
	double expectation = 0.0;
	while(!stck.empty()) {
		map<int, double> pull_temp = stck.top();
		stck.pop();
		it = pull_temp.begin();
		int temp = it->first;
		double time_temp = it->second;
		if(visited[temp] == true) continue;
		visited[temp] = true;
		expectation += time_temp;
		vector<int> childs = adj[temp];
		int num_of_childs = 0;
		for(int i=0; i<childs.size(); i++) 
			if(visited[childs[i]] == false) num_of_childs++;
		if(num_of_childs == 0) continue;
		for(int i=0; i<childs.size(); i++) {
			if(visited[childs[i]] == false) {
				map<int, double> push_temp;
				push_temp[childs[i]] = (1.0 / num_of_childs) * time[childs[i]];
				stck.push(push_temp);
			}
		}
	}
	return expectation;
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<int> time(n+1);
	for(int i=1; i<=n; i++) cin >> time[i];
	vector<vector<int> > adj(n+1);
	for(int i=0; i<n-1; i++) {
		int src, dest;
		cin >> src >> dest;
		adj[src].push_back(dest);
		adj[dest].push_back(src);
	}
	double result = INF;
	int question;
	for(int src=1; src<=n; src++) {
		double temp_result = calculate_expected_time(adj, time, src);
		if(temp_result < result) {
			result = temp_result;
			question = src;
		}
	}
	cout << question << endl;
	return 0;
}
