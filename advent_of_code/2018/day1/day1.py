values = [int(line.strip()) for line in open("/Users/ruppala/1.txt", "r").readlines()]

freq_found, has_found, result = {}, False, None

cum_sum = 0
while not has_found:
    for value in values:
        if cum_sum not in freq_found:
            freq_found[cum_sum] = True
        else:
            has_found = True
            result = cum_sum
            break
        cum_sum += value

print result
