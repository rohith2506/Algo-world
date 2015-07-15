#include <iostream>
#include <stdio.h>
#include <cmath>
#include <queue>

using namespace std;

long long int go(int n){
	queue<long long int> q;
	q.push(9);
	while(!q.empty()){
		long long int num = q.front();
		q.pop();
//		cout<<num<<" "<<n<<endl;
		if(num%n == 0) return num;
		long long int num2 = (num*10)+0;
		long long int num3 = (num*10)+9;
		q.push(num2);
		q.push(num3);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout<<go(n)<<endl;
	}
	return 0;
}