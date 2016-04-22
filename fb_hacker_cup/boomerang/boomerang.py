'''
Count the number of distinct and equal length segments
'''

import math
from collections import defaultdict

def dist(p1, p2):
	return ((p1[0] - p2[0]) * (p1[0] - p2[0])) + ((p1[1] - p2[1]) * (p1[1] - p2[1]))

def calc_line_segments(points):
	point_pairs = {}
	for i in range(0, len(points)):
		for j in range(0, len(points)):
			px, py = points[i], points[j]
			if px == py: continue
			distance = dist(px, py)
			if px not in point_pairs:
				point_pairs[px] = {}
				point_pairs[px][distance] = 1
			elif distance not in point_pairs[px]:
				point_pairs[px][distance] = 1
			else:
				point_pairs[px][distance] += 1
	result = 0
	for points, distance_dict in point_pairs.items():
		for distance, count in distance_dict.items():
			result += (count * (count - 1) / 2)
	return result

if __name__ == "__main__":
	t = int(raw_input())
	for i in range(1, t+1):
		num_stars = int(raw_input())
		points = []
		for j in range(num_stars):
			px, py =  raw_input().split()
			px, py = int(px), int(py)
			points.append((px, py))
		result = calc_line_segments(points)
		print "Case #%d: %d" %(i, result)
