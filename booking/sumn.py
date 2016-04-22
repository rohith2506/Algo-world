MAX = 100000

def isSum(arr, value):
    hash_map = {}
    for i in range(0,len(arr)):
        temp = value-arr[i]
        if temp>=0 and if temp in hash_map: return True
        hash_map[arr[i]]=1
    return False
 
val = int(raw_input())
m = int(raw_input())
arr = []

for i in range(0, m): 
    temp = int(raw_input())
    arr.append(temp)

if isSum(arr, val): print 1
else: print 0