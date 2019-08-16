

values = [line.strip() for line in open("input.txt", "r").readlines()]

for value in values:
    date_and_time, remaining = value.split(']')
    print date_and_time
