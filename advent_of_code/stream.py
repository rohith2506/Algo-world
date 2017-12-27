
def contains_garbage(inp, x, y):
    stck, idx, total_length = [], x, 0
    while idx <= y:
        if inp[idx] == '<':
            stck.append(idx)
        elif inp[idx] == '>':
            prev_idx = stck.pop()
            total_length = total_length + (idx - prev_idx - 1)
            print total_length
        idx = idx + 1
    if len(stck): return False
    else: return True

def get_group_count(x, y, group_dict):
    cnt = 1
    for k, v in group_dict.items():
        x1, y1 = k.split("_")
        x1, y1 = int(x1), int(y1)
        if x1 >= x and x1 <= y and y1 >= x and y1 <= y:
            cnt = cnt + 1
    return cnt

lines = open("in.txt").readlines()
in_str = lines[0].strip()

# Removes the ingored characters
new_str, i = "", 0
while i < len(in_str):
    if in_str[i] == '!':
        i = i + 2
    else:
        new_str = new_str + in_str[i]
        i = i + 1

#Empty all the data between garbage
final_str, i, is_garbage, stck, total_length  = "", 0, False, [], 0
print new_str
while i < len(new_str):
    if new_str[i] == '<' and not is_garbage:
        stck.append(i)
        is_garbage = True
    elif new_str[i] == '>':
        prev_i = stck.pop()
        total_length = total_length + (i - prev_i - 1)
        is_garbage = False
        i = i + 1
        continue
    if not is_garbage:
        final_str = final_str + new_str[i]
    i = i + 1

print final_str
print "total length: ", total_length
new_str = final_str
idx, stck, group_dict = 0, [], {}
while idx < len(new_str):
    if new_str[idx] == '{':
        stck.append(idx)
    elif new_str[idx] == '}':
        prev_idx = stck.pop()
        if contains_garbage(new_str, prev_idx, idx):
            group_cnt = get_group_count(prev_idx, idx, group_dict)
            group_dict[str(prev_idx) + "_" + str(idx)] = group_cnt
    idx = idx + 1

print group_dict
print sum(group_dict.values())
