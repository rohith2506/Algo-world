def get_next_letter(alpha_dict):
    for k,v in alpha_dict.items():
        if v == 0:
            alpha_dict[k] = 1
            return k

def is_possible_to_replace(s1):
    alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    alpha_dict = {}
    for alpha in alphabets: alpha_dict[alpha] = 0
    for letter in s1:
        if letter != '?':
            alpha_dict[letter] += 1
            if alpha_dict[letter] > 1: return ""
    result = ""
    for letter in s1:
        if letter == '?': 
            letter = get_next_letter(alpha_dict)
        result = result + letter
    return result

inp, is_found = raw_input(), False
result, start, end = "", 0, 0
for i in range(0, len(inp) - 25):
    s1 = inp[i:i+26]
    result = is_possible_to_replace(s1)
    if result:
        is_found = True
        start, end = i, i+26
        break

if is_found:
    main_result = inp[:start] + result + inp[end:]
    main_result = main_result.replace('?', 'C')
    print main_result
else:
    print -1
