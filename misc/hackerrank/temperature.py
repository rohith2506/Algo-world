from sklearn.svm import LinearSVC
import time
from random import random,randint
import math
import time
import datetime as dt

months = ["January","February","March","April","May","June","July",
			"August","September","October","November","December"]

def func(data, temp1, temp2):
	avg_temp = 0.0
	for idx2, max_temp, min_temp in data:
		avg_temp = avg_temp + abs(max_temp - min_temp)
	avg_temp = avg_temp / len(data)
	if temp1 ==  100:
		return temp2 + avg_temp
	else:
		return temp1 - avg_temp

def main():
	n = raw_input()
	n = int(n)
	dump_line = raw_input()
	train_data = {}
	test_data = {}

	for month in months:
		train_data[month] = []
		test_data[month] = []

	for i in range(0,n):
		line = raw_input()
		lst = line.split("\t")
		lst = lst[1:len(lst)]
		max_temp = lst[2]
		min_temp = lst[3]
		idx = months.index(lst[1])
		if "Missing" in max_temp or "Missing" in min_temp:
				if "Missing" in max_temp:
					test_data[lst[1]].append((idx, 100, min_temp))
				else:
					test_data[lst[1]].append((idx, max_temp, 100))
		else:
			train_data[lst[1]].append((idx, max_temp,min_temp))
	print train_data[0]
	return train_data, test_data

def helper(train_data, test_data):
	for idx, temp1, temp2 in test_data:
		data = train_data[months[idx]]
		print idx, data
		missing_val = func(data, temp1, temp2)
		print missing_val

if __name__ == "__main__":
	train_data, test_data = main()
	helper(train_data, test_data)