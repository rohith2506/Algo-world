import math
str1 = raw_input()
str2 = raw_input()

flag = 0
for i in range(0, len(str2)):
	if str2[i] not in str1:
		flag = 1
		break

if flag == 1:
	print "need tree"
else:
	str11 = ''.join(ch for ch in str1)
	str22 = ''.join(ch for ch in str2)
	str1 = ''.join(sorted(str1))
	str2 = ''.join(sorted(str2))                                                                                         
	if str1 == str2:
		print "array"
	else:
		