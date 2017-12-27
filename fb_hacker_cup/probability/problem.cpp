#include <utility>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

void print_vector(vector<pair<int, int> > v) {
    cout << "###############\n";
    cout << "size: " << v.size() << endl;
    for(int i=0; i<v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << "###############\n";
}

bool is_enough_white_balls(vector<pair<int, int> > containers, int p) {
    double probability = 0.0;
    for(int i=0; i<containers.size(); i++) {
        pair<int, int> p = containers[i];
        if(p.first != 0) {
            probability = probability + ((1.0 / containers.size()) *  ((p.second * 1.0) / (p.first + p.second)));
        }
        else {
            probability = probability + (1.0 / containers.size());
        }
    }
    probability = (probability * 100.0);
    cout << "probability: " << probability << endl;
    if((int) probability >= p) return true;
    else return false;
}

int solve(int c, int b, int p) {
    vector<pair<int, int> > containers(c, make_pair(0, 0));
    int black_balls = 0;
    while(black_balls < b) {
        for(int i=0; i<containers.size(); i++) {
            if(black_balls < b) {
                containers[i].first = containers[i].first + 1;
                black_balls = black_balls + 1;
            }
        }
    }
    int result = 0;
    for(int i=0; i<containers.size(); i++) {
        if(containers[i].first == 0) {
            containers[i].second = 1;
            result = result + 1;
        }
    }
    while(!is_enough_white_balls(containers, p)) {
        // get the index of container which contains less white balls
        int mini = INT_MAX, mini_index = -1;
        for(int i=0; i<containers.size(); i++) {
            if(containers[i].first != 0) {
                if(containers[i].second < mini) {
                    mini = containers[i].second;
                    mini_index = i;
                }
            }
        }
        if(mini_index == -1) {
            // this should not happen
            break;
        }
        else {
            containers[mini_index].second += 1;
            result = result + 1;
        }
    }
    print_vector(containers);
    return result;
}
         
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int c,b,p;
        cin >> c >> b >> p;
        int res = solve(c, b, p);
        cout << res << endl;
    }
    return 0;
}
