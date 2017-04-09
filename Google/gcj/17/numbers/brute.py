
def is_sequence_right(num):
    digits = [d for d in str(num)]
    for i in range(0, len(digits)-1):
        if digits[i] > digits[i+1]: return False
    return True

def get_largest_number(n):
    for i in range(n, -1, -1):
        if is_sequence_right(i): return i

test = int(raw_input())
for t in range(1, test+1):
    number = int(raw_input())
    print "Case #%d: %d" %(t, get_largest_number(number))
