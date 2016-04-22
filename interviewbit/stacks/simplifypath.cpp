#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void print_vector(vector<string> v) {
    for(int i=0; i<v.size(); i++) 
        cout << v[i] << " ";
    cout << endl;
}

string simplifyPath(string A) {
    A = A + "/";
    stack<string> stck;
    int idx = 0;
    vector<string> list_of_directories;
    string temp = "";
    for(int i=0; i<A.length(); i++) {
        if(A[i] == '/') {
            list_of_directories.push_back(temp);
            temp = "";
        }
        else
            temp = temp + A[i];
    }
    if(list_of_directories.size() == 0) return "/";
    else {
        for(int i=0; i<list_of_directories.size(); i++) {
            if(list_of_directories[i] == "") continue;
            if(list_of_directories[i] == "..") {
                if(!stck.empty()) stck.pop();
            }
            else {
                if(list_of_directories[i] != ".")
                    stck.push(list_of_directories[i]);
            }
        }
        vector<string> res;
        while(!stck.empty()) { res.push_back(stck.top());  stck.pop(); }
        string result = "/";
        for(int i=res.size() - 1; i >= 0; i--) {
            result = result + res[i];
            result = result + "/";
        }
        if(result == "/") return result;
        else return result.substr(0, result.length() - 1);
    }
}

int main() {
    string str;
    cin >> str;
    cout << simplifyPath(str) << endl;
    return 0;
}
