vector<string> help(string s, vector<string> &dict, map<string, vector<string>>& cache){
    if(cache.find(s)!=cache.end())   return cache[s];
    vector<string> result;
    for(int i=0; i<s.size(); i++){
        string w=s.substr(0, i+1);
        if(find(dict.begin(), dict.end(), w)!=dict.end()){
            if(i==s.size()-1){
                result.push_back(w);
                break;
            }

            vector<string> ret=help(s.substr(i+1), dict, cache);

            for(int j=0; j<ret.size(); j++){
                result.push_back(w+" "+ret[j]);
            }
        }
    }
    cache[s]=result;
    return result;
}

vector<string> Solution::wordBreak(string s, vector<string>& wordDict) {
    map<string, vector<string>> cache;
    return help(s, wordDict, cache);
}

