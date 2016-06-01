#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> find_delta(vector<int> numbers) {
	vector<int> res;
    res.push_back(numbers[0]);
    for(int i=1; i<numbers.size(); i++) {
    	int previous = numbers[i-1], present = numbers[i];
        int diff = present - previous;
        if(diff > 127 || diff < -127) res.push_back(-128);
        res.push_back(diff);
    }
    return res;
}

int main() {
	string st;
	getline(cin, st);
	vector<string> numbers;
	string num = "";
	for(int i=0; i<st.length(); i++) {
		if(st[i] == ' ') {
			numbers.push_back(num);
			num = "";
		}
		else {
			num = num + st[i];
		}
	}
	numbers.push_back(num);
	vector<int> n2;
	for(int i=0; i<numbers.size(); i++) {
		n2.push_back(atoi(numbers[i].c_str()));
	}
	vector<int> res = find_delta(n2);
	for(int i=0; i<res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}