# -*- coding: utf-8 -*-
import math,string,itertools,fractions,heapq,collections,re,array,bisect

class FourStrings:
	def get_substring(self, s1, s2):
		longest_str, max_len = "", 0
		for i in range(0, len(s1)):
			for j in range(i, len(s1)):
				temp_str = s1[i:j+1]
				if temp_str in s2 and len(temp_str) > max_len:
					max_len = len(temp_str)
					longest_str = temp_str
		return longest_str
				
	def get_all_possible_combinations(self, words_list):
		all_strings = []
		for num in range(1, 16):
			binary_num = bin(num)[2:]
			temp_str = ""
			for index in range(0, len(binary_num)):
				if binary_num[index] == '1':
					overlapped_string = self.get_substring(temp_str, words_list[index])
					temp_str = temp_str[0:len(temp_str) - len(overlapped_string)] + overlapped_string + words_list[index][len(overlapped_string):]
			all_strings.append(temp_str)
		return all_strings

	def shortestLength(self, a, b, c, d):
		min_length = 100000
		for permute in itertools.permutations([a,b,c,d]):
			all_possible_words = self.get_all_possible_combinations(permute)
			for word in all_possible_words:
				if a in word and b in word and c in word and d in word:
					min_length = min(min_length, len(word))
		return min_length

# CUT begin
# TEST CODE FOR PYTHON {{{
import sys, time, math

def tc_equal(expected, received):
    try:
        _t = type(expected)
        received = _t(received)
        if _t == list or _t == tuple:
            if len(expected) != len(received): return False
            return all(tc_equal(e, r) for (e, r) in zip(expected, received))
        elif _t == float:
            eps = 1e-9
            d = abs(received - expected)
            return not math.isnan(received) and not math.isnan(expected) and d <= eps * max(1.0, abs(expected))
        else:
            return expected == received
    except:
        return False

def pretty_str(x):
    if type(x) == str:
        return '"%s"' % x
    elif type(x) == tuple:
        return '(%s)' % (','.join( (pretty_str(y) for y in x) ) )
    else:
        return str(x)

def do_test(a, b, c, d, __expected):
    startTime = time.time()
    instance = FourStrings()
    exception = None
    try:
        __result = instance.shortestLength(a, b, c, d);
    except:
        import traceback
        exception = traceback.format_exc()
    elapsed = time.time() - startTime   # in sec

    if exception is not None:
        sys.stdout.write("RUNTIME ERROR: \n")
        sys.stdout.write(exception + "\n")
        return 0

    if tc_equal(__expected, __result):
        sys.stdout.write("PASSED! " + ("(%.3f seconds)" % elapsed) + "\n")
        return 1
    else:
        sys.stdout.write("FAILED! " + ("(%.3f seconds)" % elapsed) + "\n")
        sys.stdout.write("           Expected: " + pretty_str(__expected) + "\n")
        sys.stdout.write("           Received: " + pretty_str(__result) + "\n")
        return 0

def run_tests():
    sys.stdout.write("FourStrings (550 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("FourStrings.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            a = f.readline().rstrip()
            b = f.readline().rstrip()
            c = f.readline().rstrip()
            d = f.readline().rstrip()
            f.readline()
            __answer = int(f.readline().rstrip())

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(a, b, c, d, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1451322266
    PT, TT = (T / 60.0, 75.0)
    points = 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
