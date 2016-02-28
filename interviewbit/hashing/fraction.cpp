#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

string fractionToDecimal(int n, int d) {
    long int numerator = (long)(n), denominator = (long)(d);
    string res = "";
    map<long, long> mp;
    if(numerator == 0) return "0";
    if(numerator < 0 || denominator < 0) {
        if(numerator < 0 && denominator < 0) {}
        else res = res + "-";
    }
    numerator = abs(numerator);
    denominator = abs(denominator);
    res = res + to_string(numerator / denominator);
    if(numerator % denominator == 0) return res;
    res = res + ".";
    for(long r = numerator%denominator; r ; r = r % denominator) {
        if(mp.find(r) != mp.end()) {
            res.insert(mp[r], 1, '(');
            res = res + ')';
            break;
        }
        mp[r] = res.size();
        r = r * 10;
        res += to_string(r/denominator);
    }
    return res;
}

int main() {
    int n, d;
    cin >> n >> d;
    cout << fractionToDecimal(n, d) << endl;
    return 0;
}
