#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long int>v(n);
		
		for(int i=0;i<n;i++) cin>>v[i];
		int k;
		cin >> k;
		
		int num = v[k-1];
		int cnt = 0;
		for(int i=0;i<v.size();i++){
			if(num > v[i])
				cnt++;
		}

		cout<<cnt+1<<endl;
	}
	return 0;
}
