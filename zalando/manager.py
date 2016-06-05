'''
Variation of maximum sliding window
@Author: Rohith Uppala
'''

def get_max_price(duration_dict, duration):
	start_index, end_index, max_price = duration - 59, duration, -1
	for present_time in xrange(start_index, end_index+1):
		if present_time not in duration_dict: continue
		else: max_price = max(max_price, duration_dict[present_time])
	return max_price

if __name__ == "__main__":
	n = int(raw_input())
	duration_dict = {}
	while n:
		message = raw_input()
		values = message.split()
		if len(values) == 3:
			price, duration = int(values[1]), int(values[2])
			if duration not in duration_dict: duration_dict[duration] = price
			else: duration_dict[duration] = max(duration_dict[duration], price)
		else:
			duration = int(values[1])
			print get_max_price(duration_dict, duration)
		n = n - 1
