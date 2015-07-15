#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <cstring>
#include <string>
#include <fstream>
int n = 80;
using namespace std;

int go(vector<vector<int> > v,int xco,int yco){
    stack<int> stkx;
    stack<int> stky;

    stkx.push(xco);
    stky.push(yco);
    
    cout<<"starting element: "<<v[xco][yco]<<endl;

    vector<vector<bool> > visited(n,vector<bool>(n,false));

    cout<<"path was: "<<endl;

    int sum = 0;
    while(!stkx.empty()){
        int xc = stkx.top();
        int yc = stky.top();

            
      //  if(yc == 4) break;

        stkx.pop();
        stky.pop();


        if(xc>=0 && xc < n && yc>=0 && yc < n && !visited[xc][yc]){
           visited[xc][yc] = true;
        
           sum+= v[xc][yc];
           cout<<v[xc][yc]<<" ";

           int temp_min = 10000001;
           int val1=10000001,val2=10000001,val3=10000001;
           if(xc-1>=0 && !visited[xc-1][yc])
                val1 = v[xc-1][yc];
           if(xc+1<n && !visited[xc+1][yc])
                val2 = v[xc+1][yc];
           if(yc+1 < n && !visited[xc][yc+1])
                val3 = v[xc][yc+1];

           int min1 = min(val1,val2);
           int min2 = min(min1,val3);

           if(min2!=10000001){
                if(min2 == val1){
                    stkx.push(xc-1);
                    stky.push(yc);
                }
                if(min2 == val2){
                    stkx.push(xc+1);
                    stky.push(yc);
                }
                if(min2 == val3){
                    stkx.push(xc);
                    stky.push(yc+1);
                }
           }
        }

        if(yc == n-1) break;
    }

        cout<<endl;
        if(sum == 260324){
             cout<<"sum was: "<<sum<<endl;
             while(1){}
        }
        return sum;
}

int main(){
        ifstream fin;
        fin.open("in.txt",ios::in);
        string str;
        vector<vector<int> > v(n,vector<int>(n));
        int r=0,c;
        while(getline(fin,str)){
           int num = 0;
           c = 0;
           for(int i=0;i<str.length();i++){
                if(str[i]!=',')
                    num = num*10 + (int)(str[i]-'0');
                else{
                    v[r][c] = num;
                    num = 0;
                    c++;
                }
           }
           v[r][c]=num;
           r++;
        }
        
        int res = 10000001;
        for(int i=0;i<n;i++)
            res = min(go(v,i,0),res);
        cout<<res<<endl;
        return 0;
}

