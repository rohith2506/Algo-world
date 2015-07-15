#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int cnt(){

		int count = 0;
        int onetonine = strlen("onetwothreefourfivesixseveneightnine");
        int tentonineteen = strlen("teneleventwelvethirteenfourteenfifteensixteenseventeeneighteennineteen");
        int nd = strlen("and");
        int twentytoninety = strlen("twentythirtyfortyfiftysixtyseventyeightyninety");
        int hundred = strlen("hundred");
        int thousand = strlen("thousand");
        count = strlen("one") + thousand + 
          900*hundred + 100*onetonine + 
          100*twentytoninety + 891*nd + 
          80*onetonine + 10*(onetonine + tentonineteen);

         return count;
}


int main(){
	cout<<cnt()<<endl;
	return 0;
}