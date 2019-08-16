/*
Average reading time for a node = reading time of the node + (average of incoming and outgoing links)
@Author: Rohith Uppala
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int get_best_reading_node(vector<vector<int> > graph, vector<int> questions) {

}

int main() {
    int n;
    cin >> n;
    vector<int> questions(n);
    for(int i=0; i<n; i++) cin >> questions[i];
    vector<vector<int> > graph(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = graph[y][x] = 1;
    }
    int best_node = get_best_reading_node(graph, questions);
    cout << best_node << endl;
    return 0;
}
