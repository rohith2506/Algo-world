#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class PairGameEasy {
public:
	string able(int a, int b, int c, int d) {

		queue<int> stkx;
		queue<int> stky;

		stkx.push(a);
		stky.push(b);

		int flag = 0;

		while(!stkx.empty()){
			int temp1 = stkx.front();
			int temp2 = stky.front();

			stkx.pop();
			stky.pop();

			if(temp1 == c && temp2 == d){
				flag = 1;
				break;
			}

			int val1,val2;
			val1 = temp1;
			val2 = temp1 + temp2;

			if(val1 <= c && val2 <= d){
				stkx.push(val1);
				stky.push(val2);
			}

			val1 = temp1+temp2;
			val2 = temp2;

			if(val1 <= c && val2 <= d){
				stkx.push(val1);
				stky.push(val2);
			}	
		}


		if(flag == 1)
			return "Able to generate";
		else
			return "Not able to generate";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, string p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	PairGameEasy *obj;
	string answer;
	obj = new PairGameEasy();
	clock_t startTime = clock();
	answer = obj->able(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p4 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p4;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	int p3;
	string p4;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 2;
	p2 = 3;
	p3 = 5;
	p4 = "Able to generate";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 2;
	p2 = 2;
	p3 = 1;
	p4 = "Not able to generate";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 2;
	p1 = 2;
	p2 = 2;
	p3 = 999;
	p4 = "Not able to generate";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 2;
	p1 = 2;
	p2 = 2;
	p3 = 1000;
	p4 = "Able to generate";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 47;
	p1 = 58;
	p2 = 384;
	p3 = 221;
	p4 = "Able to generate";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 1000;
	p1 = 1000;
	p2 = 1000;
	p3 = 1000;
	p4 = "Able to generate";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
