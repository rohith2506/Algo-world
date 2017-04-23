import math
import pdb

color_dicts = {
        'R': ['Y', 'B', 'G'],
        'O': ['B'],
        'Y': ['B', 'R', 'V'],
        'G': ['R'],
        'B': ['Y', 'R', 'O'],
        'V': ['Y']
}

valid_combiantion = None

def is_valid_combination(inp, n):
    if len(inp) != n: return False
    if inp[0] == inp[len(inp) - 1]: return False
    for i in range(0, len(inp) - 1):
        if inp[i] == inp[i+1]: return False
    return True

def get_possible_combination(present_combination, colors, n):
    if is_valid_combination(present_combination, n):
        global valid_combiantion
        valid_combiantion = present_combination
        return
    else:
        present_color = present_combination[len(present_combination) - 1]
        for matched_colors in color_dicts[present_color]:
            for matched_color in matched_colors:
                matched_color_count = colors.get(matched_color, 0)
                if matched_color_count > 0:
                    new_combination = present_combination + matched_color
                    colors[matched_color] -= 1
                    get_possible_combination(new_combination, colors, n)
                    colors[matched_color] += 1

def solve(colors, n):
    for k, v in colors.items():
        if not v: continue
        get_possible_combination(k, colors, n)

if __name__ == "__main__":
    tst = int(raw_input())
    for t in range(1, tst+1):
        valid_combiantion = None
        n,r,o,y,g,b,v = map(int, raw_input().split())
        colors = {}
        colors['R'], colors['Y'], colors['B'] = r, y, b
        colors['O'], colors['G'], colors['V'] = o, g, v
        solve(colors, n)
        if valid_combiantion:
            print "Case #%d: %s" %(tst, valid_combiantion)
        else:
            print "Case #%d: %s" %(tst, "IMPOSSIBLE")
