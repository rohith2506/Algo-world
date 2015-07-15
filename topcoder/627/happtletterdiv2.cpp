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

class HappyLetterDiv2 {
public:
	int getHappyLetter(string letters) {
		vector<int> hash(256,0);
		for(int i=0;i<letters.size();i++)
			hash[(int)(letters[i])]++;
		int maxi = 0;
		int index = 0;
		for(int i=0;i<hash.size();i++){
			if(hash[i] > maxi){
				maxi = hash[i];
				index = i;
			}
		}
		int sum = 0;
		for(int i=0;i<hash.size();i++){
			if (index != i)
				sum = sum + hash[i];
		}
		if(sum < maxi)
			return (char)(index);
		else
			return '.';
	}
};