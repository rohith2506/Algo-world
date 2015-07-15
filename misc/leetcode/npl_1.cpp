#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int p,q,r;
		cin>>p>>q>>r;

		vector<string> temp;

		for(int i=0;i<p;i++){
			string s;
			cin>>s;
			temp.push_back(s);
		}

		vector<string> temp2;

		for(int i=0;i<q;i++){
			string s;
			cin>>s;
			temp2.push_back(s);
		}


		vector<string> temp3;

		for(int i=0;i<r;i++){
			string s;
			cin>>s;
			temp3.push_back(s);
		}


		// for raju


		int rajusum = 0;
		for(int i=0;i<temp.size();i++){
			int flag = 0;
			for(int j=0;j<temp2.size();j++){
				if(temp[i] == temp2[j])
					flag++;
			}

			for(int k=0;k<temp2.size();k++){
				if(temp[i] == temp3[k])
					flag++;
			}

			if(flag == 0)
				rajusum=rajusum+3;
			else if(flag == 1)
				rajusum=rajusum+2;
			else if(flag == 2)
				rajusum=rajusum+1;
			else{}
		}


		//for ramu

		int ramusum = 0;
		
		for(int i=0;i<temp2.size();i++){
			int flag=0;
			for(int j=0;j<temp.size();j++){
				if(temp2[i] == temp[j])
					flag++;
			}

			for(int k=0;k<temp3.size();k++){
				if(temp2[i] == temp3[k])
					flag++;
			}

			if(flag == 0)
				ramusum=ramusum+3;
			else if(flag == 1)
				ramusum=ramusum+2;
			else if(flag == 2)
				ramusum=ramusum+1;
			else{}
		}

		//for ramesh

		//for ramu

		int rameshsum = 0;
		
		for(int i=0;i<temp3.size();i++){
			int flag=0;
			for(int j=0;j<temp.size();j++){
				if(temp3[i] == temp[j])
					flag++;
			}

			for(int k=0;k<temp2.size();k++){
				if(temp3[i] == temp2[k])
					flag++;
			}

			if(flag == 0)
				rameshsum=rameshsum+3;
			else if(flag == 1)
				rameshsum=rameshsum+2;
			else if(flag == 2)
				rameshsum=rameshsum+1;
			else{}
		}

		vector<int> t;

		t.push_back(rajusum);
		t.push_back(ramusum);
		t.push_back(rameshsum);

		sort(t.begin(),t.end());

		if(t[2] == t[1])
			cout<<"Tie"<<endl;
		else{

			if(t[2] == ramusum)
				cout<<"Ramu"<<endl;
			else if(t[2] == rajusum)
				cout<<"Raju"<<endl;
			else
				cout<<"Rakesh"<<endl;
		}

		
	}
	return 0;
}