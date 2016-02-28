'''
Window overlapping problem.
Right & left array precomputations
'''

__author__ = "ROHITH UPPALA"

import math

def get_upvotes(arr, k):
	inc_seq = [[0 for i in range(len(arr))] for j in range(2)]
	dec_seq = [[0 for i in range(len(arr))] for j in range(2)]
	
	for i in range(0, n):
		inc_seq[0][i] = 1 + (inc_seq[0][i-1] if i and arr[i] >= arr[i-1] else 0)
		dec_seq[0][i] = 1 + (dec_seq[0][i-1] if i and arr[i] <= arr[i-1] else 0)
	
	for i in range(n-1, -1, -1):
		inc_seq[1][i] = 1 + (inc_seq[1][i+1] if i < n-1 and arr[i] >= arr[i+1] else 0)
		dec_seq[1][i] = 1 + (dec_seq[1][i+1] if i < n-1 and arr[i] <= arr[i+1] else 0)
	
	inc_count, dec_count = 0, 0
	for i in range(0, k-1):
		inc_count += inc_seq[0][i]
		dec_count += dec_seq[0][i]
	
	for i in range(k-1, n):
		inc_count = inc_count + min(k, inc_seq[0][i])
		dec_count = dec_count + min(k, dec_seq[0][i])
		print inc_count - dec_count
		inc_count = inc_count - min(k, dec_seq[1][i - (k-1)])
		dec_count = dec_count - min(k, inc_seq[1][i - (k-1)])

if __name__ == "__main__":
	n,k = raw_input().split()
	n,k = int(n), int(k)
	arr = map(int, raw_input().split())
	get_upvotes(arr, k)
