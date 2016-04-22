INF = 10000
class Interval:
	def __init__(self, s=0, e=0):
		self.start = s
		self.end = e

class Solution:
	def insert(self, intervals, new_interval):
		new_intervals = []
		ns, ne = new_interval.start, new_interval.end
		ns, ne = min(ns, ne), max(ns, ne)
		intervals.append(Interval(ns, ne))
		intervals.sort(key = lambda x: x.start)
		prev = intervals[0]
		for i in range(1, len(intervals)):
			curr = intervals[i]
			if prev.end >= curr.start:
				merged = Interval(prev.start, max(prev.end, curr.end))
				prev = merged
			else:
				new_intervals.append(prev)
				prev = curr
		new_intervals.append(prev)
		new_intervals.sort(key = lambda x: x.start)
		return new_intervals

if __name__ == "__main__":
	n = int(raw_input())
	intervals = []
	for i in range(n):
		s,e = raw_input().split()
		s,e = int(s), int(e)
		obj = Interval(s,e)
		intervals.append(obj)
	s,e = raw_input().split()
	s,e = int(s), int(e)
	obj = Interval(s, e)
	new_intervals = Solution().insert(intervals, obj)
	for interval in new_intervals:
		print interval.start, interval.end
