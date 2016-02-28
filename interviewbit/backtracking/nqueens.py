class Solution:
	def under_attack(self, col, queens):
			return col in queens or \
						any(abs(col - x) == len(queens)-i for i,x in enumerate(queens))
	 
	def solve(self, n):
			solutions = [[]]
			for row in range(n):
					solutions = (solution+[i+1]
												for solution in solutions
												for i in range(n)
												if not self.under_attack(i+1, solution))
			return solutions

	def solveNQueens(self, board_size):
			results = []
			for first_answer in self.solve(board_size):
				results.append(list(enumerate(first_answer, start=1)))
			all_queens = []
			for result in results:
					queens = [['.' for i in range(board_size)] for j in range(board_size)]
					for x, y in result:
							queens[x-1][y-1] = 'Q'
					temp = []
					for row in queens:
						raw_string = ""
						for x in row: raw_string = raw_string + x
						temp.append(raw_string)
					all_queens.append(temp)
			return all_queens
								
n = int(raw_input())
print Solution().solveNQueens(n)
