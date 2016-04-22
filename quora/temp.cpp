#include <map>
#include <iostream>

using namespace std;

int main() {
	map<int, int> mp;
	mp[1] = 2;
	mp[2] = 3;
	map<int, int>::iterator it;
	map<int, int> temp = mp;
	it = mp.begin();
	cout << it -> first << " " << it -> second << endl;
	for(it=mp.begin(); it != mp.end(); it++) 
		cout << it->first << " " << it->second << endl;
	return 0;
}
