n, m = map(int, raw_input().split())
d = map(int, raw_input().split())
a = map(int, raw_input().split())
a = [0] + a
have = [1 for i in range(0, n)]
a[0], have[0] = -1, 0
extra, All, result = 0, 0, -1
for i in range(1, n+1):
    extra = extra - (a[d[i]])
    All = All + have[d[i]]
    have[d[i]] = 0
    a[d[i]] = a[d[i]] - 1
    if extra >= 0 and All == m and d[i] != 0:
        flag, result = 1, i
        break
print result
