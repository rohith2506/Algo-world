#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int tst=0;tst<t;tst++){
		string s;
		cin >> s;
		vector<bool> v(26,false);

		for(int i=0;i<s.length();i++){
			int index = (int)(s[i] -'a');
			v[index] = true;
		}

		int flag = 0;
		for(int i=0;i<v.size();i++){
			if(v[i] == false){
				flag = 1;
				break;
			}
		}

		if(flag == 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}