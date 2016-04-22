class Solution:
    def canCompleteCircuit(self, gas, cost):
        start, end = 0, 1
        cur_petrol = gas[start] - cost[start]
        while end != start or cur_petrol < 0:
            while cur_petrol < 0 and end != start:
                cur_petrol -= gas[start] - cost[start]
                start = (start + 1)%len(gas)
                if start == 0: return -1
            cur_petrol = cur_petrol + (gas[end] - cost[end])
            end = (end + 1)%len(gas)
        return start

A = map(int, raw_input())
B = map(int, raw_input())

print Solution().canCompleteCircuit(A, B)