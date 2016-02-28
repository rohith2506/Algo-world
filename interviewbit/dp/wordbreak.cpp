#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

bool is_found(vector<string> &dict, string str) {
    for(int i=0; i<dict.size(); i++) {
        if(dict[i] == str) return true;
    }
    return false;
}

int wordBreak(string A, vector<string> &B) {
    int length = A.length();
    vector<bool> words(length+1, false);
    for(int i=1; i<=length; i++) {
        if(words[i] == false && is_found(B, A.substr(0, i))) 
            words[i] = true;
        if(words[i] == true) {
            for(int j=i; j<=length; j++) {
                if(words[j] == false && is_found(B, A.substr(i, j-i))) 
                    words[j] = true;
                if(j == length && words[j] == true) return 1;
            }
        }
    }
   return false;
}

int main() {
    string str;
    cin >> str;
    int len;
    cin >> len;
    vector<string> dict(len);
    for(int i=0; i<len; i++) cin >> dict[i];
    cout << wordBreak(str, dict) << endl;
    return 0;
}
