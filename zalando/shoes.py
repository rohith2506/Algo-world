'''
Find top k shoes 
@Author: Rohith Uppala
'''
import pdb
from collections import OrderedDict

def get_top_shoes(shoes_dict, k):
	shoes_dict = OrderedDict(sorted(shoes_dict.items(), key=lambda t: -t[1]))
	return shoes_dict.items()[:k]

if __name__ == "__main__":
	k, m, n = map(int, raw_input().split())
	shoes_dict = {}
	for i in xrange(n):
		shoe = int(raw_input())
		if shoe not in shoes_dict: shoes_dict[shoe] = 1
		else: shoes_dict[shoe] += 1
	shoes_list = get_top_shoes(shoes_dict, k)
	for shoe_num, shoe_cnt in shoes_list:
		print shoe_num
