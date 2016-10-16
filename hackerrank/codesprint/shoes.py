n = int(raw_input())
socks = map(int, raw_input().split())
sock_dict, result = {}, 0
for sock in socks:
    if sock not in sock_dict or sock_dict[sock] == 0:
        sock_dict[sock] = 1
    else:
        result = result + 1
        sock_dict[sock] = 0
print result
