#include <iostream>
using namespace std;

int main(){
	long long int a;
	cin >> a;
	if(a%6 ==0 || a%6 == 1 || a%6 == 3)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}