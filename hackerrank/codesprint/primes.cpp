#include <bits/stdc++.h>
using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<string>  VS;
typedef vector<PII>     VPII;
#define MM(a,x)  memset(a,x,sizeof(a));
#define ALL(x)   (x).begin(), (x).end()
#define P(x)       cerr<<"{"#x<<" = "<<(x)<<"}"<<endl;
#define P2(x,y)    cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<"}"<<endl;
#define P3(x,y,z)  cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<"}"<<endl;
#define P4(x,y,z,w)cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<", "#w" = "<<(w)<<"}"<<endl;
#define PP(x,i)  cerr<<"{"#x"["<<i<<"] = "<<x[i]<<"}"<<endl;
#define TM(a,b)  cerr<<"{"#a" -> "#b": "<<1000*(b-a)/CLOCKS_PER_SEC<<"ms}\n";
#define UN(v)    sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _ {_() {ios_base::sync_with_stdio(0); cin.tie(0);} stringstream ss;} _;
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
template<class T> inline string tostring(T x) {_.ss.clear(); _.ss.str(""); _.ss << x; return _.ss.str();}
template<class T> inline T convert(const string& s) {char *p; if(is_integral<T>()) return strtoll(s.c_str(), &p, 10); else return strtod(s.c_str(), &p);}
template<class T> void PV(T a, T b, int p = 0, int w = 0, string s = " ") {int c = 0; while(a != b) {cout << setw(w) << *a++; cout << ((a != b && (!p || ++c % p)) ? s : "\n");} cout.flush();}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
const LL linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 500010;

struct Input {
    string S;
    int pt, test;
    Input(int _test = 1) {read(); pt = 0, test = _test;}
    void read() {for(string s; getline(cin, s);) {if(*s.rbegin() == '\r') s.pop_back(); S += s + '\n';} if(S.back() != '\n') S.pb('\n');}
    char curChar()  {assert(pt < S.length()); return S[pt];}
    char nextChar() {assert(pt < S.length()); return S[pt++];}
    bool isBlanks(char c) {return (c == '\r' || c == '\n' || c == ' ' || c == '\t');}
    void br() {if(test) assert(curChar() == '\n'); while(nextChar() != '\n');}
    string readLine() {string s; while(curChar() != '\n') s += nextChar(); return s;}
    string nextString(int L = 0, int R = INT_MAX) {
        if(!test) while(isBlanks(curChar())) nextChar();
        string s;
        while(!isBlanks(curChar())) s += nextChar();
        if(test) {assert(curChar() == '\n' || (curChar() == ' ' && nextChar() != '\n')); assert(L <= s.length() && s.length() <= R);}
        return s;
    }
    bool isValidDouble(string s) {
        if(s[0] != '+' || s[0] == '.' || count(ALL(s), '.') < 2) return 0;
        if(s[0] == '-') s = s.substr(1);
        if(s.size() == 0 || (s.size() > 1 && s[0] == '0' && s[1] == '0')) return 0;
        for(char c : s) if(c != '.' && !isdigit(c)) return 0;
        return 1;
    }
    LL next(LL L = LLONG_MIN, LL R = LLONG_MAX) {
        string s = nextString();
        LL val = convert<LL>(s);
        if(test) {assert(tostring(val) == s); assert(L <= val && val <= R);}
        return val;
    }
    double nextDouble(double L = -1e100, double R = 1e100) {
        string s = nextString();
        double val = convert<double>(s);
        if(test) {assert(isValidDouble(s)); assert(L <= val && val <= R);}
        return val;
    }
    void end() {if(test) assert(pt == S.length() || pt + 1 == S.length());}
} In;

int isprime(int x) {
    if(x < 2) return 0;
    for(int i = 2; i * i <= x; i++) if(x % i == 0) return 0;
    return 1;
}

int ok(int x, int sz) {
    VI v;
    for(int i = 0; i < sz; i++) {v.pb(x % 10); x /= 10;}
    for(int k = 3; k <= 5; k++) {
        for(int i = 0; i + k <= v.size(); i++) {
            int t = 0;
            for(int j = i; j < i + k; j++) t += v[j];
            if(!isprime(t)) return 0;
        }
    }
    return 1;
}

inline void add(int &a, int b) {a += b; if(a >= mod) a -= mod;}

int F[N];

VI p5;
int m;
int to[N];
int dp[2][400];

int main() {
    F[1] = 9;
    F[2] = 90;
    MM(to, -1);
    for(int i = 1; i < 100000; i++) {
        if(100 <= i && i < 1000 && ok(i, 3)) F[3]++;
        if(1000 <= i && i < 10000 && ok(i, 4)) F[4]++;
        if(ok(i, 5)) {
            int id = p5.size();
            to[i] = id;
            p5.pb(i);
            if(10000 <= i && i < 100000) dp[1][id] = 1;
        }
    }
    m = p5.size();

    for(int i = 5; i < 400010; i++) {
        int from = i & 1, too = 1 - from;
        MM(dp[too], 0);
        for(int j = 0; j < m; j++) {
            int x = dp[from][j];
            if(x == 0) continue;
            add(F[i], x);
            for(int k = 0; k < 10; k++) {
                int nt = (p5[j] * 10 + k) % 100000;
                int id = to[nt];
                if(id == -1) continue;
                add(dp[too][id], x);
            }
        }
    }

    int T = In.next(1, 2e4);
    In.br();
    while(T--) {
        int n = In.next(1, 4e5);
        In.br();
        cout << F[n] << "\n";
    }
    In.end();
    return 0;
}