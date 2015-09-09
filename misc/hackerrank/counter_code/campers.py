n,k = raw_input().split()
n,k = int(n), int(k)
lst = raw_input().split()

for i in range(0, len(lst)):
    lst[i] = int(lst[i])

arr = [0 for i in range(0, n)]

for l in lst:
    arr[l-1] = 1

res = 0
maxi = len(lst)
i = 0
while i < len(arr):
    if i == 0:
        if arr[i] == 0 and arr[i+1] == 0:
            maxi = maxi + 1
            arr[i] = 0
    elif i == len(arr) - 1:
        if arr[i] == 0 and arr[i-1] == 0:
            maxi = maxi + 1
            arr[i] = 0
    else:
        if arr[i] == 0 and arr[i-1] == 0 and arr[i+1] == 0:
            maxi = maxi + 1
            arr[i] = 0
    i = i + 1
res = max(maxi, res)

arr = [0 for i in range(0, n)]
for l in lst:
    arr[l-1] = 1
maxi = len(lst)
i = 1
while i < len(arr):
    if i == n-1:
        if arr[i] == 0 and arr[i-1] == 0:
            maxi = maxi + 1
            arr[i] = 0
    else:
        if arr[i] == 0 and arr[i-1] == 0 and arr[i+1] == 0:
            maxi = maxi + 1
            arr[i] = 0
    i = i + 1
res = max(maxi, res)

print res

