'''
To find outliers, i am gonna use little bit of statistics here,
For a given set of numbers, to find outliers, we are gonna use IQR (inter quartile range) method.

1) IQR = (Q3 - Q1)
where Q3 = 75th percentile
      Q1 = 25th percentile
2) low value = Q1 - 150% of IQR 
   high value = Q3 + 150% of IQR 

As we here are interested in only high values, we will consider only high value.
'''

import math

def calc_median(numbers):
    if len(numbers) % 2 == 0:
        mid = len(numbers) / 2
        return ((numbers[mid-1] + numbers[mid]) * 1.0/2)
    else:
        mid = len(numbers) / 2
        return numbers[mid]

def calc_q1_and_q3(numbers):
    mid = len(numbers) / 2
    q1 = calc_median(numbers[0:mid])
    q3 = calc_median(numbers[mid:len(numbers)])
    return (q1, q3)

def calc_iqr(numbers):
    (q1, q3) = calc_q1_and_q3(numbers)
    iqr = (q3 - q1)
    return (q1, q3, iqr)

def calc_outlier_threshold_limit(numbers):
    (q1, q3, iqr) = calc_iqr(numbers)
    threshold_limit = q3 + (1.5 * iqr)
    return threshold_limit

if __name__ == "__main__":
    n = int(raw_input())
    timeseries, numbers = [], []
    for i in range(n):
        time, requests = raw_input().split()
        requests = int(requests)
        timeseries.append((time, requests))
        numbers.append(requests)
    tl = calc_outlier_threshold_limit(numbers)
    results = []
    for i in range(0, len(timeseries)):
        time, requests = timeseries[i][0], timeseries[i][1]
        if requests > tl and flag == 0:
            startx = time
            flag = 1
        if requests < tl and flag == 1:
            endx = time
            flag = 0
        results.append((startx, endx))
    print results
