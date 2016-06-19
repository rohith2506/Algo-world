'''
minimum positive integer 

Given an array, apply bi where 1 <= bi <= ai for all 1 <= i <= n, find the maximum minimum positive integer which won't appear in array

for example: 1,3,3,3,6 => 1,2,2,3,4 => answer: 5
for example: 2,1 => 1,2 => answer: 3
for example: 2,1,1 => 1,1,2 => answer: 3

Solution: sort the numbers and start mex with one. try to compare with each element in that position and if it's lesser than that, increment it's count. The final count is your answer.

Proof: It's just a simple observation. we are trying to find minimum positive integer at every index by comparing with number at that index.

@Author: Rohith Uppala
'''

def solve(numbers):
	numbers.sort()
	cnt = 1
	for a in numbers: if a >= cnt: cnt = cnt + 1
	return cnt

if __name__ == "__main__":
	n = int(raw_input())
	numbers = map(int, raw_input().split())
	print solve(numbers)		
