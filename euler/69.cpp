# include <iostream>
# include <stdio.h>
# include <cmath>
# include <vector> 
using namespace std;

vector<int> primeFactors(int n)
{
    vector<int> factors;
    int flag = 0;
    while (n%2 == 0)
    {
	flag = 1;
        n = n/2;
    }
    if(flag == 1) factors.push_back(2);
    flag = 0;
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
	    flag = 1;
            n = n/i;
        }
	if(flag == 1){
		factors.push_back(i);
		flag = 0;
	}
    }
    if (n > 2)
	factors.push_back(n);
    return factors;
}
 
/* Driver program to test above function */
int main(){
    	int n;
    	cin >> n;
	double maxi = 0;
	int main_res;
	for(int num=2; num<=n; num++){
   		vector<int> factors = primeFactors(num);
		double prod = 1.0;
		for(int i=0;i<factors.size();i++)
			prod = (prod * (factors[i] -1))/(factors[i]);
		double result = num * prod;
		cout << num << "  " << result << "  " << (num/result) << endl;
		result = num / result;
		if(result > maxi){
			maxi = result;
			main_res = num;
		}
	}
	cout << main_res << endl;
	return 0;
}	
