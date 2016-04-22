'''
Little Data structures manipulation.
@Author: Rohith
'''

import math
shoe_dict = {}

def form_dict(raw_string, shoe_type):
    if raw_string not in shoe_dict:
        shoe_dict[raw_string] = {}
        shoe_dict[raw_string][shoe_type] = 1
    else:
        if shoe_type not in shoe_dict[raw_string]:
            shoe_dict[raw_string][shoe_type] = 1
        else:
            shoe_dict[raw_string][shoe_type] += 1

if __name__ == "__main__":
    num_shoes = int(raw_input())
    while num_shoes:
        company, size, color, shoe_type = raw_input().split()
        combined_string = company + "_" + size + "_" + color
        form_dict(combined_string, shoe_type)
        num_shoes = num_shoes - 1
    result = 0
    for key, pair_dict in shoe_dict.items():
        result += min(pair_dict.get('L', 0), pair_dict.get('R', 0))
    print result
