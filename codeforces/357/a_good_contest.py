'''
Yes/No
@Author: Rohith Uppala
'''

def is_good_or_not(contestors_dict):
	flag = 0
	for contestor, ratings in contestors_dict.items():
		prev_rating, next_rating = ratings
		if prev_rating >= 2400 and next_rating >= 2400 and next_rating > prev_rating: flag = 1
	if flag == 1: return "YES"
	else: return "NO"

if __name__ == "__main__":
	n = int(raw_input())
	contestors_dict = {}
	for i in range(n):
		raw_data = raw_input().split()
		contestors_dict[raw_data[0]] = [int(raw_data[1]), int(raw_data[2])]
	print is_good_or_not(contestors_dict)
