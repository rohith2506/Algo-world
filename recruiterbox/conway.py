'''
Conway's Game of life
@Author: Rohith
'''

import math
import os


def start_func():
	'''
		It will start the conway's game of life
	'''
	lst = [[0,0,0,0,0],[1,0,0,1,0],[0,0,0,1,0],[1,1,0,0,1],[1,0,0,0,1]]
	xco, yco = 0,0
	stkx,stky = [],[]
	stkx.append(xco)
	stky.append(yco)
	while stkx:
		for i in range(0, len(lst)):
			for j in range(0, len(lst[i])):
				print lst[i][i],
			print
			
		tempx = stkx.pop()
		tempy = stky.pop()
		for i in range(-1,2):
			for j in range(-1,2):
				xco, yco = [], []
				if (tempx+i >= 0 and  tempx+i < 5) and (tempy+j >= 0 and tempy+j < 5):
					xco.append(tempx+i)
					yco.append(tempy+j)
					stkx.append(tempx+i)
					stky.append(tempy+j)
				living, dead = 0,0
				for x in xco:
					for y in yco:
						if lst[x][y] == 1:
							living = living + 1
						else:
							dead = dead + 1
				if lst[tempx][tempy] == 1:
					if living > 3:
						lst[tempx][tempy] = 0
					elif living == 2 or living == 3:
						lst[tempx][tempy] = 1
					else:
						lst[tempx][tempy] = 0
				else:
					if living == 3:
						lst[tempx][tempy] = 1


if __name__ == "__main__":
	start_func()
