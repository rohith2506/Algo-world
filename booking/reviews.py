'''
Data Manipulation
@Author: Rohith Uppala
'''
import pdb
import string
import math
import datetime

if __name__ == "__main__":
    n, m = map(int, raw_input().split())
    passions = []
    for i in range(n):
        passion = raw_input()
        passion = passion.lower()
        passions.append(passion)
    reviewers = {}
    for i in range(m):
        pid, ts = map(int, raw_input().split())
        review = raw_input()
        reviewers[pid] = [ts, review]
    for passion in passions:
        result, maxi, scores = -1, 0, {}
        for pid, values in reviewers.items():
            ts, review = values
            score = 0
            words = review.split()
            for i in range(len(words)):
                string = words[i]
                words[i] = ''.join(e for e in string if e.isalnum())
                words[i] = words[i].lower()
            if passion not in words: continue
            if ts >= 1465941600 and ts <= 1468533600:
                score = score + 20
            else:
                score = score + 10
            if len(review) > 100:
                score = score + 20
            else:
                score = score + 10
            if pid not in scores:
                scores[pid] = score
            else:
                scores[pid] = scores[pid] + score
        for k, v in scores.items():
            if v > maxi:
                maxi = v
                result = k
            elif v == maxi:
                result = min(k, result)
        print result
