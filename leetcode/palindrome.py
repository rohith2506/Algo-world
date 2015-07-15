import math

tst = raw_input()
tst = int(tst)
while tst:
	string = raw_input()
	yes = False
	for i in range(0, len(string)):
		temp = string[:i]+string[i+1:]
		if temp == temp[::-1]:
			yes = True
			break
	if yes == True:
		print "YES"
	else:
		print "NO"
	tst = tst - 1
