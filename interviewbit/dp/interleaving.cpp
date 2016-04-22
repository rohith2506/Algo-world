class Solution {
    private:
        string s1, s2, s3;
        short memo[101][101][101];
    public:
        bool isInterleave(int index1, int index2, int index3) {
            if (index1 == s1.length() && index2 == s2.length()) {
                return index3 == s3.length();
            }
            if (index3 >= s3.length()) return false;

            if (memo[index1][index2][index3] != -1) return memo[index1][index2][index3];
            
            bool answer = false; 
            if (index1 < s1.length() && s1[index1] == s3[index3]) answer |= isInterleave(index1 + 1, index2, index3 + 1);
            if (index2 < s2.length() && s2[index2] == s3[index3]) answer |= isInterleave(index1, index2 + 1, index3 + 1);
            
            return memo[index1][index2][index3] = answer;
        }

        bool isInterleave(string S1, string S2, string S3) {
            s1 = S1; 
            s2 = S2;
            s3 = S3;
            memset(memo, -1, sizeof(memo));
            if (S3.length() != S1.length() + S2.length()) return false;
            return isInterleave(0, 0, 0);
        }
};
