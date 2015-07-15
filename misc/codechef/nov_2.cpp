#include <iostream>
#define MOD 1000000007
#define ll long long int
using namespace std;
ll power(ll a,ll b){
      if(b==0)
         return 1; 
      else if(b==1)
         return a; 
      else{
 	if(b%2==0)
            return power(((a%MOD)*(a%MOD))%MOD,b/2); 
        else
            return ((a%MOD)*power(((a%MOD)*(a%MOD))%MOD,(b-1)/2))%MOD;
      }
}


int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout<<power(2,n)-1<<endl;
	}
	return 0;
}
