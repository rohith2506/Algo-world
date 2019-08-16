from collections import deque
import pdb

def find_next_directions(position, path_dict):
    next_positions = []
    if (position[0], position[1], position[0] + 1, position[1]) not in path_dict:
        next_positions.append((position[0] + 1, position[1]))
    if (position[0], position[1], position[0], position[1] + 1) not in path_dict:
        next_positions.append((position[0], position[1] + 1))
    return next_positions

def find_path_using_raw_input(path, n):
    initial_pos = (0, 0)
    path_arr = [initial_pos]
    for i in range(len(path)):
        prev_pos = path_arr[len(path_arr)-1]
        if path[i] == 'E': path_arr.append((prev_pos[0], prev_pos[1] + 1))
        else: path_arr.append((prev_pos[0] + 1, prev_pos[1]))
    path_dict = {}
    for i in range(len(path_arr) - 1):
        path_dict[(path_arr[i][0], path_arr[i][1], path_arr[i+1][0], path_arr[i+1][1])] = 1
    return path_dict

def is_valid_final_path(path):
    e_cnt, s_cnt = 0, 0
    for i in range(len(path)):
        if path[i] == 'E': e_cnt = e_cnt + 1
        else: s_cnt = s_cnt + 1
    return e_cnt == s_cnt

def convert_path_to_string(path):
     result = ""
     for i in range(len(path) - 1):
         cur_pos, next_pos = path[i], path[i+1]
         if cur_pos[0] != next_pos[0]: result = result + 'S'
         else: result = result + 'E'
     return result

def solve(path_dict, n):
    stck = []
    stck.append([0, 0, []])
    result = ""
    while stck:
        px, py, pr_path = stck.pop()
        present_path = pr_path[:]
        if px >= n or py >= n: continue
        present_path.append([px, py])
        if px == n - 1 and py == n - 1:
            path_string = convert_path_to_string(present_path)
            if is_valid_final_path(path_string):
                result = path_string
                break
        next_positions = find_next_directions((px, py), path_dict)
        for next_position in next_positions:
            stck.append([next_position[0], next_position[1], present_path])
    return result

if __name__ == "__main__":
    t = int(raw_input())
    for i in range(1, t+1):
        n = int(raw_input())
        path = raw_input()
        path_dict = find_path_using_raw_input(path, n)
        result = solve(path_dict, n)
        print "Case #%d: %s" %(i, result)
