#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#define gc getchar_unlocked

using namespace std;

inline int fast_io() 
{
	register int N = 0, C;
	while ((C = gc()) < '0');
 
	do {
		N = (N<<3) + (N<<1) + C - '0';
	}while ((C = gc()) >= '0');
	return N;
}


int main(){
	int test;
	test = fast_io();
	
	long int a[10000];
	long int b[10000];
	long int max1[10000];
	long int max2[10000];
	long int min1[10000];
	long int min2[10000];

	while(test--){
		long int n;
		n = fast_io();

		for(int i=0;i<n;i++){
			scanf("%ld",&a[i]);
			b[i]=-a[i];
		}

		long int maxendhere=a[0];
		long int maxsofar=a[0];
		max1[0]=a[0];

		for(int i=1;i<n;i++){
			maxendhere=maxendhere+a[i];
			maxendhere = maxendhere > a[i] ? maxendhere:a[i];
			maxsofar = maxsofar > maxendhere ? maxsofar : maxendhere;
			max1[i]=maxsofar;
		}

/*		for(int i=0;i<n;i++)
			cout<<max1[i]<<" ";
			cout<<endl;
*/
		maxendhere = max2[n-1] = maxsofar = a[n-1];
//		cout<<max2[n-1]<<endl;
		for(int i=n-2;i>=0;i--){
				maxendhere=maxendhere+a[i];
				maxendhere = maxendhere > a[i] ? maxendhere:a[i];
				maxsofar = maxsofar > maxendhere ? maxsofar : maxendhere;
				max2[i]=maxsofar;	
		}

		maxendhere = maxsofar = b[0];

		min1[0]=-b[0];

		for(int i=1;i<n;i++){
			maxendhere=maxendhere+b[i];
			maxendhere = maxendhere > b[i] ? maxendhere:b[i];
			maxsofar = maxsofar > maxendhere ? maxsofar : maxendhere;
			min1[i]= -maxsofar;
		}


		maxendhere = maxsofar = b[n-1];

		min2[n-1] = -b[n-1];

		for(int i=n-2;i>=0;i--){
			maxendhere=maxendhere+b[i];
			maxendhere = maxendhere > b[i] ? maxendhere:b[i];
			maxsofar = maxsofar > maxendhere ? maxsofar : maxendhere;
			min2[i]= -maxsofar;	
		}

/*		for(int i=0;i<n;i++){
			cout<<a[i]<<" "<<b[i]<<" "<<max1[i]<<" "<<max2[i]<<" "<<min1[i]<<" "<<min2[i]<<endl;
		}
*/

		long int main_max = 0;

		for(int i=1;i<n;i++){
			long m1 = abs(max1[i-1]-min2[i]);
			long m2 = abs(max2[i]-min1[i-1]);

			m1 = m1 > m2 ? m1:m2;
			main_max = main_max > m1 ? main_max : m1;
		}
		printf("%ld\n",main_max);
	}	
	return 0;
}