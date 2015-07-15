#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		double ps,pr,pi,pu,pw,pd,pl;
		cin >> ps >> pr >> pi >> pu >> pw >> pd >> pl;

		double res = 0.0;
		for(int i=0;i<k;i++){
			double sunny = pi;
			double rainy = 1-pi;
			double res1 = (ps*(sunny + i*(pu*pw)))/(ps*(sunny + i*(pu*pw))) + ((1-ps)(sunny + i*(pl*pd))));
			double res2 = (pr*(1-))
		}


	}
}