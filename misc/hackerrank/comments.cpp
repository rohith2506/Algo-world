/*
 * Print the single line and multi line comments from source code
 * @Author: Rohith Uppala
 */

#include <iostream>
#include <vector>
using namespace std;
int main() {
    string line;
    vector<string> comments;
    string comment = "";
    bool is_single_comment = false, is_multi_comment_begin = false, is_multi_comment_end = false;
    while(cin) {
        getline(cin, line);
        if(line.empty()) line = "\n";
        int i = 0;
        for(i=0; i<line.length()-1; i++) {
            string temp = line.substr(i, 2);
            if(!is_multi_comment_begin && temp == "//") {
                is_single_comment = true;
            }
            if(temp == "/*") {
                is_multi_comment_begin = true;
            }
            if(temp == "*/") {
                is_multi_comment_end = true;
            }
            if(is_single_comment || is_multi_comment_begin || is_multi_comment_end) 
                comment = comment + line[i];
        }
        if(is_single_comment) {
            comment = comment + line.substr(i, 2);   
            comments.push_back(comment);
            comment = "";
            is_single_comment = false;
        }
        if(is_multi_comment_begin) {
            comment = comment + line.substr(i, 2);
            if(!is_multi_comment_end) {
                comment = comment + "\n";
            }
            else {
                comments.push_back(comment);
                comment = "";
                is_multi_comment_begin = false;
                is_multi_comment_end = false;
            }
        }
    }
    for(int i=0; i<comments.size(); i++) cout << comments[i] << endl;
    return 0;
}
