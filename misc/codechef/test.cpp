#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream fout;
	fout.open("in.txt",ios::out);
	int t=100000;
	fout<<t<<endl;
	for(int i=1;i<=t;i++)
		fout<<i<<endl;
	return 0;
}
