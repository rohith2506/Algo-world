// keep 1 in first position and and 3 in final position


#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	int low=2,high=2;

	int first = 0,last = n-1;
    
    for(int i=0; i <= last;){
        	if(a[i] > high){
    		int temp = a[i];
    		a[i] = a[last];
    		a[last] = temp;
    		last--;
    	}
    	else if(a[i] < low){
    		int temp = a[i];
    		a[i] = a[first];
    		a[first] = temp;
    		i++;
    		first++;
    	}
    	else{
    		i++;
    	}
    }

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;

		return 0;
}