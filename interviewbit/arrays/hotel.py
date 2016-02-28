class Solution:
	def hotel(self, arrive, depart, K):
		arrive.sort()
		depart.sort()
		guests_in, max_guests = 1, 1
		i, j = 1, 0
		while i < len(arrive) and j < len(depart):
			if arrive[i] < depart[j]:
				guests_in += 1
				max_guests = max(max_guests, guests_in)
				i = i + 1
			else:
				guests_in -= 1
				j = j + 1
		if max_guests > K: return 0
		else: return 1
	
arrive = raw_input().split()
for i in range(len(arrive)): arrive[i] = int(arrive[i])
depart = raw_input().split()
for i in range(len(depart)): depart[i] = int(depart[i])
K = int(raw_input())
print Solution().hotel(arrive, depart, K)
