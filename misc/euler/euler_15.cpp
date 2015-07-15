//easiest way:- To find central co-efficient of pascal triangle
//harder way:-  do dfs (takes time)...:-P
//this is dfs method

#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int go(vector<vector<int> > v,int res){
       stack<int> stkx;
       stack<int> stky;
       int n= v[0].size();
       stkx.push(0);
       stky.push(0);

       int cnt=0;
       while(!(stkx.empty())){
             int x=stkx.top();
             int y=stky.top();
             cout<<x<<" "<<y<<endl;
              stkx.pop();
             stky.pop();
             if((x < n) && (y < n)){
                if(v[x][y]==res)
                cnt++;
                stkx.push(x+1);
                stky.push(y);
                //cout<<"i a m h e r e"<<endl;
                stkx.push(x);
                stky.push(y+1);
             }

       }
       return cnt;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > v;;
    int cnt=1;
    for(int i=0;i<n+1;i++){
            vector<int> temp;
        for(int j=0;j<n+1;j++){
            temp.push_back(cnt);
            cnt++;
        }
        v.push_back(temp);
    }
    int res=(n+1)*(n+1);
    cout<<go(v,res)<<endl;
    return 0;
}
