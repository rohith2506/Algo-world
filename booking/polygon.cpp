#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> num_polygons(vector<int> numbers) {
    int x = 0, y = 0, z = 0;
	int a = numbers[0], b = numbers[1], c = numbers[2], d = numbers[3];
    if(a == b && b == c && c == d && a > 0 && b > 0 && c > 0 && d > 0) x = x + 1;
    else if(a == c && b == d && a > 0 && b > 0 && c > 0 && d > 0) y = y + 1;
    else z = z + 1;
    vector<int> res;
	res.push_back(x);
	res.push_back(y);
	res.push_back(z);
	return res;
}

int main() {
	int totalx = 0, totaly = 0, totalz = 0;
	while(true) {
		string st;
		getline(cin, st);
		if(st.empty()) break;
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
		vector<int> res = num_polygons(n2);
		totalx = totalx + res[0];
		totaly = totaly + res[1];
		totalz = totalz + res[2];
	}
	cout << totalx << " " << totaly << " " << totalz << endl;
	return 0;
}
