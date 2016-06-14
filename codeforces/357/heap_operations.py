'''
heap operations
@Author: Rohith Uppala
'''

import math
import heapq

def solve(operations):
	heap, new_ops = [], []
	for i in range(len(operations)):
		operation = operations[i]
		try:
			op, element = operation.split()
		except:
			op = operation
		if op == "insert":
			element = int(element)
			heapq.heappush(heap, element)
			new_ops.append(operation)
		elif op == "removeMin":
			if heap:
				element = heapq.heappop(heap)
				new_ops.append(operation)
		else:
			if heap:
				mini_element = heapq.heappop(heap)
				if mini_element == int(element):
					heapq.heappush(heap, mini_element)
					new_ops.append(operation)
				else:
					result = "removeMin"
					new_ops.append(result)
					while heap:
						mini_element = heapq.heappop(heap)
						if mini_element == int(element): break
						elif mini_element < int(element):
							heapq.heappush(heap, element)
							result = "insert " + str(element)
							new_ops.append(result)
						elif mini_element > int(element):
							element = heapq.heappop(heap)
							result = "removeMin"
							new_ops.append(result)							
					if not heap:
						heapq.heappush(heap, element)
						result = "insert " + str(element)
						new_ops.append(result)
						new_ops.append(operation)
					else:
						heapq.heappush(heap, mini_element)
						new_ops.append(operation)
			else:
				heapq.heappush(heap, element)
				result = "insert " + str(element)
				new_ops.append(result)
				new_ops.append(operation)
	return new_ops

if __name__ == "__main__":
	n = int(raw_input())
	operations = []
	for i in range(n):
		operation = raw_input()
		operations.append(operation)
	result = solve(operations)
	print len(result)
	for res in result:
		print res
