import math

n,p,x = raw_input().split()
n,p,x = int(n), int(p), int(x)
ratings = raw_input().split()

for i in range(0, len(ratings)):
    ratings[i] = int(ratings[i])

person_id = -1
maxi = 0

for i in range(0, len(ratings)):
    person_score = p * ratings[i]
    if person_score > maxi:
        maxi = person_score
        person_id = i+1
    p = p - x

print person_id
