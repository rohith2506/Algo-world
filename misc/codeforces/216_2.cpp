#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int n,k,l,r,sall,sk;
	cin >> n >> k >> l >> r >> sall >> sk;

	//cout<<k<<" "<<l<<" "<<r<<endl;

	int kl = k*l;
	int kr = k*r;

	//cout<<kl<<" "<<kr<<endl;

	vector<int> v(n);

	int diff1 = sk - kl;
	int diff2 = kr - sk;

	//cout<<diff1<<" "<<diff2<<endl;


	if(diff2 > diff1){
		for(int i=0;i<k;i++)
			v[i] = l;
		v[0] = v[0] + diff1;
	}
	else{
		for(int i=0;i<k;i++)
			v[i] = r;
		v[k-1] = v[k-1] - diff2;
	}

	//for(int i=0;i<k;i++)cout<<v[i]<<" ";
	//cout<<endl;


	int kl2 = (n-k)*l;
	int kr2 = (n-k)*r;

	int sk2 = sall - sk;

	int diff3 = sk2 - kl2;
	int diff4 = kr2 - sk2;

	if(diff4 > diff3){
		for(int i=k;i<n;i++)
			v[i] = l;
		v[k] = v[k] + diff3;
	}

	else{
		for(int i=k;i<n;i++)
			v[i] = r;
		v[n-1] = v[n-1] - diff4;
	}

	for(int i=0;i<n;i++)cout<<v[i]<<" ";
	cout<<endl;

	return 0;
}