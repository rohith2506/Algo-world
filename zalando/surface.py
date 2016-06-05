'''
Find minimum surface area of cuboid
@Author: Rohith Uppala
'''

def get_minimum_surface_area(breadth, length, height, n):
	result = int(10e18) + 1
	for i in range(1, n+1):
		if n % i == 0:
			l_b, h = i, n / i
			for j in range(1, l_b+1):
				if l_b % j == 0:
					l, b = j, l_b / j
					l1, b1, h1 = l * length, b * breadth, h * height
					surface_area = 2 * ((l1 * b1) + (b1 * h1) + (h1 * l1))
					result = min(surface_area, result)
	return result

if __name__ == "__main__":
	n = int(raw_input())
	b,l,h = map(int, raw_input().split())
	print get_minimum_surface_area(b,l,h,n)
