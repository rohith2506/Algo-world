T=input()
for t in range(T):
    A,B = map(int,raw_input().split())
    print pow(A,B,10**9+7)