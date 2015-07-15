#include <iostream>
#include <set>
#include <vector>
#include <string>


using namespace std;

int main(){
	set<string> myset = {"ba","ac","cb"};
	set<string>::iterator it;	
	for(it=myset.begin(); it!=myset.end(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
