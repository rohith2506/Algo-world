'''
Intersection between sets without using hash table
@Author: Rohit
'''

def FindIntersectionRange(intervals):
	start, end = intervals[0][0], intervals[0][1]
	for i in range(1, len(intervals)):
		nextX = intervals[i][0]
		nextY = intervals[i][1]
		if(end < nextY):
			continue
		else:
			start = max(start, nextX)
			end   = min(end, nextY)
	return (start, end)


if __name__ == "__main__":
        n = raw_input()
        n = int(n)
        intervals = []
        while n:
                start, end = raw_input().split()
                start, end = int(start), int(end)
                intervals.append((start,end))
                n = n - 1
	(start, end) = FindIntersectionRange(intervals)
	print start, end
