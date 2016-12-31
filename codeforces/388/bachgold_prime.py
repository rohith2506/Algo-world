n = int(raw_input())
result = []
if n % 2 == 1:
    result.append(3)
    n = n - 3
for i in range(0, n/2): result.append(2)
print len(result)
for res in result:
    print res,
