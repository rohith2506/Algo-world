#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string A) {
    vector<int> visited(256, -1);
    visited[A[0]] = 0;
    int max_len = 1, cur_len = 1, prev_index;
    for(int i=1; i<A.length(); i++) {
        prev_index = visited[A[i]];
        if(prev_index == -1 || (i - cur_len) > prev_index) {
           cur_len++;
        }
        else {
            if(cur_len > max_len) {
                max_len = cur_len;
            }
            cur_len = i - prev_index;
        }
        visited[A[i]] = i;
    }
    if(cur_len > max_len) max_len = cur_len;
    return max_len;
}

int main() {
    string str;
    cin >> str;
    cout << lengthOfLongestSubstring(str) << endl;
    return 0;
}
