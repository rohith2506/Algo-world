#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

pair<int, vector<string> > solve(int size, int x1, int y1, int x2, int y2) {
    pair<pair<int, int>, vector<string> > pr;
    queue<pair<pair<int, int>, vector<string>> > q;
    pr.first.first = x1;
    pr.first.second = y1;
    pr.second.clear();
    q.push(pr);
    vector<string> positions = {"UL", "UR", "R", "LR", "LL", "L"};
    vector<vector<string> > result;
    while(!q.empty()) {
        pair<pair<int, int>, vector<string> > inter_pair = q.pop();
        int tempx = inter_pair.first.first, tempy = inter_pair.first.second;
        if(tempx < 0 || tempx >= n || tempy < 0 || tempy >= n) continue;
        if(tempx == x2 && tempy == y2) {
            result.push_back(inter_pair.second);
            continue;
        }
        if(visited[tempx][tempy] == true) continue;
        visited[tempx][tempy] = true;
        for(int i=0; i<positions.size(); i++) {
            pair<pair<int, int> >, vector<string>> > new_pair;
            switch(positions[i]) {
                case "UL": { 
                    new_pair.first.first = x1-2;
                    new_pair.first.second = y1-1;
                },
                case "UR": {
                    new_pair.first.first = x1-2;
                    new_pair.first.second = y1+1;
                },
                case "R": {
                    new_pair.first.second = y1+2;
                },
                case "L": {
                    new_pair.first.second = y1-2;
                },
                case "LR": {
                    new_pair.first.first = x1+2;
                    new_pair.first.second = y1+1;
                },
                case "LL": {
                    new_pair.first.first = x1+2;
                    new_pair.first.second = y1-1;
                }
            }
            copy(inter_pair.second.begin(), inter_pair.second.end(), new_pair.second.begin());
            new_pair.second.push_back(positions[i]);
            q.push_back(new_pair);
        }
    }

    // Now, we got the result
    vector<vector<string> > main_result;
    for(int i=0; i<result.size(); i++) {
        min_size = min(result[i].size(), min_size);
    }

    for(int i=0; i<result.size(); i++) {
        if(result[i].size() == min_size) {
            main_result.push_back(result[i]);
        }
    }
    
    if(main_result.size() > 0) {
        return pair<int, vector<string> > (main_result[0].size(), main_result[0]);
    }
    else {
        return pair<int, vector<string> > (0, vector<string>());
    }
}

int main() {
    int size;
    cin >> size;
    int i_s, j_s, i_e, j_e;
    cin >> i_s >> j_s >> i_e >> j_e;
    pair<int, vector<string> > result = solve(size, i_s, j_s, i_e, j_e);
    if(result.first == 0) {
        cout << "Impossible" << endl;
    }
    else {
        cout << result.first << endl;
        for(int i=0; i<result.second.size(); i++)
            cout << result.second[i] << " ";
        cout << endl;
    }
    return 0;
}
