import math
import operator

if __name__ == "__main__":
    n = int(raw_input())
    space_dict, sids, scores = {}, [], {}
    for i in range(n):
        sid, stime, etime = map(int, raw_input().split())
        space_dict[sid] = [stime, etime]
        sids.append(sid)
    for i in range(0, len(sids)):
        s1, e1 = space_dict[sids[i]]
        score = 0
        for j in range(0, len(sids)):
            if j == i: continue
            s2, e2 = space_dict[sids[j]]
            if s2 >= s1 and e2 <= e1: score = score + 1
        scores[sids[i]] = score
    sorted_result = sorted(scores.items(), key=lambda x: (x[1], x[0]))
    for res in sorted_result:
        print res[0], res[1]
