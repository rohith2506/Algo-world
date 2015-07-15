#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#define INF 10e9+7

using namespace std;

class Solution{
	public:
		void dfs(vector<vector<int> > paths, vector<string> words, vector<string> v, string start, string end){
			if(start == end){
				result.push_back(v);
				return ;
			}
			else {
				int index = find(words.begin(), words.end(), start) - words.begin();
				visited[index] = true;
				for(int j=0; j<paths[index].size(); j++){
					if(paths[index][j] == 1 && visited[j] == false){
						v.push_back(words[j]);
						dfs(paths, words, v, words[j], end);
						v.pop_back();
					}
				}
			}
		}
						
		int change(string w1, string w2) {
			vector<int> v1(26,0);
			vector<int> v2(26,0);
			int diff = 0;
			for(int i=0;i<w1.length();i++)
				v1[(int)(w1[i] - 'a')]++;
			for(int i=0;i<w2.length();i++)
				v1[(int)(w2[i] - 'a')]++;
			for(int i=0;i<v1.size();i++)
				diff = diff + abs(v1[i] - v2[i]);
			return diff;
		}			

		vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict){
			int sz = dict.size();
			vector<string> words;
			vector<vector<int> > paths(sz, vector<int>(sz, INF));			
			for(auto it=dict.begin(); it!=dict.end(); it++)
				words.push_back(*it);	
			for(int i=0; i<paths.size(); i++){
				for(int j=0; j<paths[i].size(); j++){
					int diff = change(words[i], words[j]);
					if(diff == 1)
						paths[i][j] = paths[j][i] = 1;
					if(diff == 0)
						paths[i][j] = paths[j][i] = 0;
				}
			}
			vector<string> v;
			v.push_back(start);
			dfs(paths, words, v, start, end);
			return result;
		}

	private:
		vector<vector<string> > result;
}
	
