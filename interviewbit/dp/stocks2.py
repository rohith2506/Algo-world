class Solution:
    def findFirst(self, A):
        if len(A) <= 1: return 0
        max_profit = 0
        mini = 10e9
        mini_arr = [mini for i in range(len(A))]
        mini_arr[0] = A[0]
        for i in range(1, len(A)):
            mini_arr[i] = min(mini_arr[i-1], A[i]) 
        for i in range(1, len(A)):
            profit = A[i] - mini_arr[i-1]
            if profit > max_profit:
                max_profit = profit
                sell_index = i
        return max_profit,
