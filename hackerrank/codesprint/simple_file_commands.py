def get_missing_number(s, t):
    return ((t * (t + 1)) / 2) - s

def delete_file(file_name,file_dict):
    file_number = 0
    if '(' in file_name:
        file_name, file_number = file_name.split('(')
        file_number = int(file_number[0])
    if file_name in file_dict:
        file_dict[file_name]['sum'] -= file_number
        file_dict[file_name]['total'] -= 1

def create_file(file_name, file_dict):
    result = ""
    if file_name not in file_dict:
        file_dict[file_name] = {}
        file_dict[file_name]['sum'] = 0
        file_dict[file_name]['total'] = 1
        result = "+ " + file_name
    else:
        missing_number = get_missing_number(file_dict[file_name]['sum'], file_dict[file_name]['total'])
        file_dict[file_name]['sum'] += missing_number
        file_dict[file_name]['total'] += 1
        if not missing_number:
            result = "+ " + file_name
        else:
            result = "+ " + file_name + "(" + str(missing_number) + ")"
    return result

if __name__ == "__main__":
    n = int(raw_input())
    file_dict = {}
    for i in range(n):
        command = raw_input()
        command = command.strip().split()
        if command[0] == 'crt':
            result = create_file(command[1], file_dict)
            print result
        elif command[0] == 'del':
            delete_file(command[1], file_dict)
            print "- " + command[1]
        else:
            delete_file(command[1], file_dict)
            result = create_file(command[2], file_dict)
            print result
        print file_dict
