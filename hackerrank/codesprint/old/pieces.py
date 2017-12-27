'''
Deriving math equation
'''
MOD = int(10e9+7)

def compute(n):
    if n == 1: return [1]
    elif n == 2: return [[1], [3,3]]
    compute_arr = []
    compute_arr.append([1])
    compute_arr.append([3,3])
    for i in range(2, n):
        values = []
        values.append(pow(2, n, MOD) - 1) # First value
        prev, prev2 = compute_arr[i-1], compute_arr[i-2]
        for j in range(0, len(prev) - 1):
            temp = prev[j] + prev[j+1] + prev2[j]
            values.append(temp)
        values.append(pow(2, n, MOD) - 1) # Last value
        compute_arr.append(values)
    return compute_arr

n = int(raw_input())
print compute(n)

#arr = map(int, raw_input().split())

#result, total = compute(n), 0
#for i in range(len(result)):
#    total = ((total % MOD) + ((result[i] % MOD) * (arr[i] % MOD)) % MOD ) % MOD
#print total
