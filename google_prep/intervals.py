'''
Give the start and end point of most overlapped intervals
@Author: Rohit
'''

def GetMaximum(intervals):
	maxi = 0
	for i in range(0, len(intervals)):
		if(intervals[i][1] > maxi):
			maxi = intervals[i][1]
	return maxi


def MostOverlappingIntervals(intervals):
	minimum, maximum = 0, GetMaximum(intervals)
	data_store = [0 for i in range(minimum, maximum+1)]
	for i in range(0, len(intervals)):
		start_point = intervals[i][0]
		end_point   = intervals[i][1]
		for j in range(start_point, end_point+1):
			data_store[j] = data_store[j] + 1
	
	max_count = 0
	for i in range(0, len(data_store)):
		if(data_store[i] > max_count):
			max_count = data_store[i]
	
	
	start, end = 0, 0
	for i in range(0, len(data_store)):
		if data_store[i] == max_count:
			start = i
			for j in range(i+1, len(data_store)):
				if data_store[j] != max_count: break
				end = j
			break
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
	(start, end) = MostOverlappingIntervals(intervals)
	print start, end
