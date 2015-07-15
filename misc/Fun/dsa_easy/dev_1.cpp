#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string go(vector<int> v,string str){
	int hr=0,min=0,sec=0;
	hr = hr * 10 + (int)(str[0] - '0');
	hr = hr * 10 + (int)(str[1] - '0');

	min = min * 10 + (int)(str[3] - '0');
	min = min * 10 + (int)(str[4] - '0');

	sec = sec * 10 + (int)(str[6] - '0');
	sec = sec * 10 + (int)(str[7] - '0');

	int enter_delay = v[v.size()-1];
	enter_delay = enter_delay / 1000;

	int delay_hrs = 0, delay_mins = 0, delay_secs = 0;
	delay_secs =  enter_delay % 60;
	enter_delay = enter_delay / 60;
	delay_mins =  enter_delay % 60;
	delay_hrs  =  enter_delay / 60;



	hr = hr + delay_hrs;
	min = min + delay_mins;
	sec = sec + delay_secs;

//	cout << hr << " " << min << " " << sec << endl;

	int t1 = sec/60;
	sec = sec%60;
	
	int t2 = (min + t1)/60;
	min = (min + t1)%60;

	hr = (hr + t2)%24;

//	cout << hr << " " << min << " " << sec << endl;

	vector<int> num(10,0);
	int temp = hr/10;
	int temp2 = hr%10;
	num[temp]++;
	num[temp2]++;

	temp = min/10;
	temp2 = min%10;
	num[temp]++;
	num[temp2]++;

	temp = sec/10;
	temp2 = sec%10;
	num[temp]++;
	num[temp2]++;

	int main_delay = 0;
	for(int i=0;i<num.size();i++){
		if(num[i]!=0){
//			cout << i << " " << num[i] << endl;
			main_delay = main_delay + (v[i] * num[i]);
		}
	}

	main_delay = main_delay / 1000;
	delay_secs = main_delay % 60;
	main_delay = main_delay / 60;
	delay_mins = main_delay % 60;
	delay_hrs  =  main_delay / 60;

//	cout << delay_hrs << " " << delay_mins << " " << delay_secs << endl;

	hr = hr + delay_hrs;
	min = min + delay_mins;
	sec = sec + delay_secs;

	sec = sec%60;
	t1 = sec/60;
	min = (min + t1)%60;
	t2 = (min + t1)/60;
	hr = (hr + t2)%24;

//	cout << hr << " " << min << " " << sec << endl;

	string res = "";
	stringstream ss1,ss2,ss3;
	string hr1,min1,sec1;
	if(hr < 10)
		res = res + "0";
	ss1 << hr;
	ss1 >> hr1;
	res = res + hr1;
	res = res + ":";
	if(min < 10)
		res = res + "0";
	ss2 << min;
	ss2 >> min1;
	res = res + min1;
	res = res + ":";
	if(sec < 10)
		res = res + "0";
	ss3 << sec;
	ss3 >> sec1;
	res = res + sec1;
	return res;
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	string str;
	cin >> str;
	go(v,str);
	return 0;
}