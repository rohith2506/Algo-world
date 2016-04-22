class Solution:
    def minJumps(self, A, B):
        INF = 1000001
        dp = [INF for i in range(len(A))]
        if len(A) == 1:
            if A[0] == -1: return []
            else:   return [1]
        dp[0] = A[0]
        if dp[0] == -1: return []
        res, lst_index = {}, 0
        for i in range(1, len(A)):
            if A[i] == -1: continue
            for j in range(0, i):
                if i - j <= B and dp[j] + A[i] < dp[i]:
                    dp[i] = dp[j] + A[i]
                    res[i] = j
                    last_index = i
        if dp[len(A) - 1] == INF: return []
        ans = []
        ans.append(last_index)
        while True:
            temp = res.get(last_index, None)
            if temp == None: break
            ans.append(temp)
            last_index = temp 
        ans = [x+1 for x in ans]
        return ans[::-1]
            
A = map(int, raw_input().split())
B = int(raw_input())
print Solution().minJumps(A, B)                   
