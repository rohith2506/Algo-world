n = int(raw_input())
scores = map(int, raw_input().split())
m = int(raw_input())
alice = map(int, raw_input().split())
ranks = [1]
for i in range(1, len(scores)):
    if scores[i] < scores[i-1]:
        ranks.append(ranks[i-1] + 1)
    else:
        ranks.append(ranks[i-1])
ranks_dict = {}
for i in range(len(scores)):
    ranks_dict[scores[i]] = ranks[i]
j, i, = 0, 0
scores = scores[::-1]
while i < len(alice) and j < len(scores):
    score = alice[i]
    if score > scores[j]:
        j = j + 1
    elif score == scores[j]:
        print ranks_dict.get(score)
        i = i + 1
    else:
        print ranks_dict.get(scores[j]) + 1
        i = i + 1
while i < len(alice):
    print 1
    i = i + 1
