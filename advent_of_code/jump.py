lines = open("in.txt").readlines()

numbers = []
for line in lines:
    numbers.append(int(line.strip()))

step, i = 0, 0
while True:
    if i < 0 or i >= len(numbers): break
    to_jump = numbers[i]
    if to_jump < 3:
        numbers[i] = numbers[i] + 1
    else:
        numbers[i] = numbers[i] - 1
    i = i + to_jump
    step = step + 1

print step
