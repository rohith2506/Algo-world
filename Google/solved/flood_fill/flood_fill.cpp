#include "headers.h"

vector<int> get_positions(vector<string> inp){
	vector<int> pos;
	for(int i=0; i<inp.size(); i++){
		for(int j=0; j<inp[i].size(); j++){
			if(inp[i][j] == 'x'){
				pos.push_back(i);
				pos.push_back(j);
				return pos;
			}
		}
	}
	return pos;
}


vector<string> flood_fill(vector<string> inp, int xc, int yc){
	stack<int> stkx, stky;
	stkx.push(xc);
	stky.push(yc);
	vector<vector<bool> > visited(inp.size(), vector<bool>(inp.size(), false));

	while(!stkx.empty()) {
		int x = stkx.top();
		int y = stky.top();
		stkx.pop();
		stky.pop();
		if(visited[x][y] == true) continue;
		if(((x<0) || (x >= inp.size()))) continue;
	        if(((y<0) || (y	>= inp.size()))) continue;
		if(inp[x][y] == '1') continue;
		inp[x][y] = '2';
		visited[x][y] = true;
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
	fin.open("input.txt", ios::in);
	string str;
	vector<string> inp;
	while(getline(fin,str)){
		inp.pb(str);
	}
	vector<int> pos = get_positions(inp);
	int xco = pos[0];
	int yco = pos[1];
	print_vector(flood_fill(inp, xco, yco));
	return 0;
}
