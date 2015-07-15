int binsearh(vector<int> v,int element, int low, int high){
    if(high >= low){
             int mid = low + (high - low) / 2;
             if( v[mid] == 0  && v[mid+1] == 1 && v[mid-1] == 0)
                 return mid;
             else if(v[mid] == 1)
                 return binsearch(v,element,low,mid-1);
             else
                 return binsearch(v,element,mid+1,high);
    }
    return -1;
}

int maximum_rows(vector<vector<int> > v){   
    int idx = binsearch(v[0],1,0,n);
    int maxi;
    if (idx == -1)
        maxi = 0;
    else
        maxi = n - idx;
    
    for(int j=1;j<m;j++){
           if(v[j][idx] == 0)
               continue;
           else{
               vector<int> v2(v[j].begin(),idx);
               int idx2 = binsearch(v2,element,0,idx);
               int maxi2;
               if (idx2 == -1)
                   maxi2 = 0;
               else{
                   maxi2 = n - idx2;
                   maxi  = maxi2;
                   idx = idx2;
                   }
           }
    }
    return maxi;
}