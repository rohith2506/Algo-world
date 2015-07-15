import math

def solve():
	fname = open("in.txt","rb")
	outfile = open("out.txt","wb")
	t = fname.readline()
	t = int(t)
	for tst in range(1, t+1):
		maxi, inp = fname.readline().split()
		maxi = int(maxi)
		data = []
		for i in range(0, len(inp)):
			data.append(int(inp[i]))
		res = 0
		num_of_persons = data[0]
		for i in range(1, len(data)):
			if data[i] == 0: continue
			if i > num_of_persons:
				res = res +  abs(i - num_of_persons)
				num_of_persons = num_of_persons + abs(i - num_of_persons)
			num_of_persons = num_of_persons + data[i]
		outfile.write("Case #" + str(tst) + ": " +  str(res))
		if(tst != t): outfile.write("\n")


if __name__ == "__main__":
	solve()
