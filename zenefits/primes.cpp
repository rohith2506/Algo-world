#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

vector<long long int> primes_upto(long long int limit) {
	vector<bool> isPrime(limit - 1, true);
	isPrime[0] = false;
	isPrime[1] = false;
	for(int n=0; n <= int(sqrt(limit) + 1.5); n++) {
		if(isPrime[n] == true) {
			for(int i=n*n; i <= limit; i+=n)
				isPrime[i] = false;
		}
	}
	vector<long long int> primes;
	for(int i=0; i < isPrime.size(); i++) {
		if(isPrime[i])
			primes.push_back(i);
	}
	return primes;
}

int main(int argc, char *argv[]) {
	long long int n;
	scanf("%lld", &n);
	vector<long long int> v;
	for(int i=0; i<n; i++) {
		long long int num;
		scanf("%lld", &num);
		v.push_back(num);
	}
	vector<long long int> primes = primes_upto(n+5);
	long long int result = 0;
	for(int i = 0; i < primes.size(); i++) {
		long long int prime = primes[i];
		for(int j=0; j < v.size(); j++) {
			if(j - prime >= 0) 
				result += (v[j] - v[j-prime]);
		}
	}
	printf("%lld\n", result);
	return 0;
}