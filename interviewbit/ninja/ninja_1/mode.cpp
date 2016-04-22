int getModeHash(unordered_map<int, int> &map) {
    int maxCount = 0;
    int maxCountNum = INT_MIN;
    for ( auto it = map.begin(); it != map.end(); ++it) {
        if(maxCount <= it->second) {
            if(maxCount == it->second) {
                maxCountNum = min(maxCountNum, it->first);
            }
            else {
                maxCountNum = it->first;
                maxCount = it->second;
            }
        }
    }
    return maxCountNum;
}

vector<int> Solution::getMode(vector<int> &A, vector<vector<int> > &B) {
   unordered_map<int, int> map;
   vector<int> result;

   for(int i=0; i< A.size(); i++) {
       if(map.find(A[i]) == map.end()) {
           map[A[i]] = 0;
       }
       map[A[i]]++;
   }

   for(int i=0; i < B.size(); i++) {
        map[A[B[i][0]-1]]--;
        if(map[A[B[i][0]-1]] == 0) {
            map.erase(A[B[i][0]-1]);
        }
        A[B[i][0]-1] = B[i][1];
        if(map.find(A[B[i][0]-1]) == map.end()) {
           map[A[B[i][0]-1]] = 0;
       }
       map[A[B[i][0]-1]]++;     
       result.push_back(getModeHash(map));
   }
   return result;
}