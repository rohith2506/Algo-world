inp = raw_input()
vowels = ['A', 'E', 'I', 'O', 'U', 'Y']
jumps = [0]
for i in range(0, len(inp)):
    if inp[i] in vowels:
        jumps.append(i+1)
jumps.append(len(inp)+1)
max_jump = 0
for i in range(0, len(jumps) - 1):
    present, nxt = jumps[i], jumps[i+1]
    max_jump = max(max_jump, (nxt - present))
print max_jump
