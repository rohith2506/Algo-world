// disjoint set data structure
int parent[N]; // initialized as: parent[i] = i
// Returns the root element of the set
int find(x) { return parent[x] = (x == parent[x] ? x : find(parent[x]); }
// Union of two sets
void join(int x, int y) { parent[find(x)] = find(y); }
// Returns true, if sets containing elements `x` and `y` are disjoint
bool disjoint(int x, int y) { return find(x) != find(y); }




// gcd of two numbers
function gcd(a, b) { return b ? gcd(b, a % b) : a; }



// string copying
while (*s++ = *t++);


//counting set bits in 'v'
for(c = 0; v; c++) v &= v - 1;



// fast inverse sqaure root of a number
float FastInvSqrt(float x) {
  float xhalf = 0.5f * x;
  int i = *(int*)&x;          // evil floating point bit level hacking
  i = 0x5f3759df - (i >> 1);  // what the fuck?
  x = *(float*)&i;
  x = x*(1.5f-(xhalf*x*x));
  return x;
}

