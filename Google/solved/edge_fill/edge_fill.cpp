#include "headers.h"

vector<int> get_positions(vector<string> v){
	vector<int> pos;
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 'x'){
				pos.push_back(i);
				pos.push_back(j);
				return pos;
			}
		}
	}
	return pos;
}


vector<string> edge_fill(vector<string> inp, vector<int> pos){
	stack<int> stkx;
	stack<int> stky;

	stkx.push(pos[0]);
	stky.push(pos[1]);
	
	vector<vector<bool> > visited(inp.size(), vector<bool>(inp.size(), false));
	while(!stkx.empty()){
		int x = stkx.top();
	       	int y = stky.top();
		stkx.pop();
		stky.pop();
		if(visited[x][y] == true) continue;
		if(((x < 0) || (x >= inp.size()))) continue;
		if(((y < 0) || (y >= inp.size()))) continue;
		visited[x][y] = true;
		if(inp[x][y] == '1') {
			inp[x][y] = '2';
			continue;
		}
		for(int i=-1; i<=1; i++){
			for(int j=-1; j<=1; j++){
				if(visited[x+i][y+j] == false){
					stkx.push(x+i);
					stky.push(y+j);
				}
			}
		}
	}
	return inp;
}


int main(){
	ifstream fin;
	vector<string> inp;
	fin.open("input.txt",ios::in);
	string str;
	while(getline(fin,str)){
		inp.pb(str);
	}
	vector<int> pos = get_positions(inp);
	inp[pos[0]][pos[1]] = '0';
	print_vector(edge_fill(inp, pos));
	return 0;
}
