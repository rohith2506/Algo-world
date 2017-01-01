def find_next_right_value(arr, low, high, num):
	if low >= high:
		return None
	else:
		mid = (low + high) / 2
		if num >= arr[mid] and num < arr[mid+1]:
			return arr[mid+1]
		elif num >= arr[mid]:
			return find_next_right_value(arr, mid+1, high, num)
		else:
			return find_next_right_value(arr, low, mid-1, num)

n = int(raw_input())
max_dict, participants_dict = {}, {}
for i in range(n):
	index, bid = map(int, raw_input().split())
	if index not in participants_dict:
		participants_dict[index] = [bid]
	else:
		participants_dict[index].append(bid)
	if index not in max_dict:
		max_dict[index] = bid
	else:
		max_dict[index] = max(max_dict[index], bid)

q = int(raw_input())
for i in range(q):
	values = map(int, raw_input().split())
	bad_indices = {}
	max_index, max_value, second_max_value = -1, 0, 0
	for val in values[1:]: bad_indices[val] = 1
	
	for index in participants_dict.keys():
		if index in bad_indices: continue
		bid_value = max_dict.get(index, None)
		if not bid_value: continue
		if bid_value > max_value:
			second_max_value = max_value
			max_value = bid_value
			max_index = index
		elif bid_value == max_value:
			second_max_value = max_value
		elif bid_value < max_value and bid_value > second_max_value:
			second_max_value = bid_value

	if second_max_value == 0 and max_value == 0:
		print 0, 0
	elif second_max_value == 0:
		print max_index, min(participants_dict[max_index])
	else:
		arr, low, high = participants_dict[max_index], 0, len(participants_dict[max_index]) - 1
		result = find_next_right_value(arr, low, high, second_max_value)
		if not result:
			print 0, 0
		else:
			print max_index, result