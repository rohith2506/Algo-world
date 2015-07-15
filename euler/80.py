import math
import decimal

def total_sum():
	total_sum = 0
	for i in range(1,101):
		print i,
		d2 = decimal.Decimal(i)
		dot100 = decimal.Context(prec=101)
		var = str(d2.sqrt(dot100))
		print var
		Sum = 0
		for v in var[2:]:
			Sum = Sum + int(v)
		total_sum = total_sum + Sum
		print Sum
	print total_sum

if __name__ == "__main__":
	total_sum()
