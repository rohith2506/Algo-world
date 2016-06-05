'''
Another dictionary problem
@Author: Rohith Uppala
'''
import itertools

if __name__ == "__main__":
	na, nb, nc = map(int, raw_input().split())
	values_dict = {}
	values_dict['A'], values_dict['B'] , values_dict['C'] = na, nb, nc
	orders = int(raw_input())
	orders_dict = {}
	for i in range(1, orders+1):
		orders = raw_input().split(',')
		for order in orders:
			if order not in orders_dict:
				orders_dict[order] = {}
				orders_dict[order] = [i]
			else:
				orders_dict[order].append(i)
	order_perms = itertools.permutations(orders_dict.items())
	result = []
	for order_list in order_perms:
		result = []
		first, second, third = order_list
		if len(first[1]) < len(second[1]):
			first, second = second, first
		interestion = [val for val in first[1] if val in second[1]]
		f_count = values_dict.get(first[0]) - len(intersection)
		s_count = values_dict.get(second[0]) - len(intersection)
		for value in first[1]:
			if value not in interestion and f_count > 0:
				interestion.append(value)
				f_count = f_count - 1 
		for value in second[1]:
			if value not in intersection and s_count > 0:
				interestion.append(value)
				s_count = s_count - 1
		if len(interestion) < len(third[1]):
			intersection, third = third, interestion
		interestion = [val for val in interestion if val in third[1]]
		
