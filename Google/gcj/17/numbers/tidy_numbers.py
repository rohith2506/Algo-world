import pdb

def get_largest_digits(a, b):
    if a <= b:
        return a, b
    else:
        a, b = a-1, 9
        return max(0, a), b

def solve(digits):
    if len(digits) == 1:
        return int(digits[0])
    else:
        last = len(digits) - 1
        while last >= 1:
            first, second = digits[last-1], digits[last]
            f1, s1 = get_largest_digits(first, second)
            if first != f1 or second != s1:
                digits[last-1], digits[last] = f1, s1
                for i in range(last+1, len(digits)): digits[i] = 9
            last = last - 1
        return int(''.join(map(str, digits)))

if __name__ == "__main__":
    test = int(raw_input())
    for t in range(1, test+1):
        number = int(raw_input())
        digits = [int(d) for d in str(number)]
        result = solve(digits)
        print "Case #%d: %d" %(t, result)
