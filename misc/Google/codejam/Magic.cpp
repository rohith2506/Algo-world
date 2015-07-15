#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int tst=1;tst<=t;tst++){
		int x;
		cin >> x;
		vector<vector<int> > v(4,vector<int>(4));
		
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cin >> v[i][j];
			}
		}

		int y;
		cin >> y;
		vector<vector<int> > v2(4,vector<int>(4));

		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cin >> v2[i][j];
			}
		}

//		cout<<"iam here";
		vector<int> rows  = v[x-1];
		vector<int> rows2 = v2[y-1];
		vector<int> common;

		for(int i=0;i<rows.size();i++){
			for(int j=0;j<rows2.size();j++){
				if(rows[i] == rows2[j])
					common.push_back(rows[i]);
			}
		}
		if(common.size() == 1)
			cout << "Case #" << tst << ": " << common[0] << endl;
		else if(common.size() == 0)
			cout << "Case #" << tst << ": " << "Volunteer cheated!" << endl;
		else
			cout << "Case #" << tst << ": " << "Bad magician!" << endl;
	}
}