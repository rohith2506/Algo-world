#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int friendCircles(vector<vector<int> > friends) {
    int total = friends.size(), result = 0;
    vector<bool> visited(total, false);
    for(int edge = 0; edge < total; edge++) {
        if(visited[edge] == true) continue;
        stack<int> stck;
        stck.push(edge);
        while(!stck.empty()) {
            int temp = stck.top();
            stck.pop();
            if(visited[temp] == true) continue;
            visited[temp] = true;
            vector<int> connected_edges = friends[edge];
            for(int edge = 0; edge < connected_edges.size(); edge++) {
                if(friends[temp][connected_edges[edge]] == 1) 
                    stck.push(connected_edges[edge]);
            }
        }
        result = result + 1;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > friends(n, vector<int>(n));
    vector<string> inp;
    for(int i=0; i<n; i++) {
        string temp; cin >> temp;
        inp.push_back(temp);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(inp[i][j] == 'Y') friends[i][j] = 1;
            else friends[i][j] = 0;
        }
    }
    int result = friendCircles(friends);
    cout << result << endl;
    return 0;
}
