#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n,0);
	while( v.size() > 0){
		cout << v.back() << " ";
		v.pop_back();
	}
	return 0;
}
