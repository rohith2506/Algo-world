# permutations of string using standard backtrack algorithm
maxcandidates = 10000


def backtrack (a,k,input):
		
		c[maxcandidates]=True
		if(is_a_solution(a,k,input)):
			process_solution(a,k,input)

		else:
			k=k+1
			construct_candidates(a,k,input,)









