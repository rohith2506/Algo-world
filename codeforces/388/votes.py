from collections import deque
n = int(raw_input())
voters = raw_input()
d, r = deque([]), deque([])
for i in range(len(voters)):
	if voters[i] == 'D':
		d.append(i)
	else:
		r.append(i)
while d and r:
	d_index, r_index = d.popleft(), r.popleft()
	if d_index < r_index:
		d.append(d_index + len(voters))
	else:
		r.append(r_index + len(voters))
if not d:
	print "R"
else:
	print "D"