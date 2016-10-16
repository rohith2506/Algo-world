n = int(raw_input())
arr = map(int, raw_input().split())
arr.append(0)
is_possible = True
for i in range(0, len(arr) - 1):
    if arr[i] < 0: 
        is_possible = False
        break
    discounts = arr[i] / 2
    arr[i] = arr[i] - (discounts * 2)
    coupons = arr[i]
    arr[i], arr[i+1] = arr[i] - coupons, arr[i+1] - coupons
for i in range(len(arr)):
    if arr[i] != 0: is_possible = False
if is_possible: print "YES"
else: print "NO"
