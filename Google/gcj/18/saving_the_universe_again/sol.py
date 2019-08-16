import pdb

def damage(robot_program):
    total, temp_power = 0, 1
    for i in range(0, len(robot_program)):
        if robot_program[i] == 'S':
            total = total + temp_power
        else:
            temp_power = temp_power * 2
    return total

def hack(robot_program):
    hacked_robot_program = []
    for r in robot_program: hacked_robot_program.append(r)
    for i in range(len(hacked_robot_program)-1, 0, -1):
        prev_index, next_index = i-1, i
        if hacked_robot_program[prev_index] == 'C' and hacked_robot_program[next_index] == 'S':
            temp = hacked_robot_program[prev_index]
            hacked_robot_program[prev_index] = hacked_robot_program[next_index]
            hacked_robot_program[next_index] = temp
            break
    return ''.join(hacked_robot_program)

if __name__ == "__main__":
    T = int(raw_input())
    for i in range(1, T+1):
        D, robot_program = raw_input().split()
        D, hacks = int(D), 0
        while damage(robot_program) > D:
            hacked_robot_program = hack(robot_program)
            if hacked_robot_program == robot_program:
                hacks = -1
                break
            else:
                hacks = hacks + 1
                robot_program = hacked_robot_program
        if hacks == -1:
            print "Case #%d: %s" %(i, "IMPOSSIBLE")
        else:
            print "Case #%d: %d" %(i, hacks)
