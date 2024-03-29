'''
Problem still unsolved
@Author: Rohith
'''

# -*- coding: utf-8 -*-
import math,string,itertools,fractions,heapq,collections,re,array,bisect

class BuildingTowers:
    def maxHeight(self, N, K, x, t):
	towers, heights = [],[]
	heights = [0 for i in range(0, N)]
	for i in range(0,len(x)):
		idx = x[i]-1
		heights[idx] = t[i]
	towers.append(1)
	for temp in x: towers.append(temp)
	for i in range(0, len(towers) - 1):
		first = towers[i] - 1
		second = towers[i+1] - 1
		if heights[first] < heights[second]:
			print "i am here", first, second
			diff = second - first
			heights[second] = min(heights[second], (heights[first]+diff*K))
		else:
			diff = second - first
			heights[first] = min(heights[first], (heights[second]+diff*K))

'''
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

def do_test(N, K, x, t, __expected):
    startTime = time.time()
    instance = BuildingTowers()
    exception = None
    try:
        __result = instance.maxHeight(N, K, x, t);
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
    sys.stdout.write("BuildingTowers (950 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("BuildingTowers.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            N = int(f.readline().rstrip())
            K = int(f.readline().rstrip())
            x = []
            for i in range(0, int(f.readline())):
                x.append(int(f.readline().rstrip()))
            x = tuple(x)
            t = []
            for i in range(0, int(f.readline())):
                t.append(int(f.readline().rstrip()))
            t = tuple(t)
            f.readline()
            __answer = int(f.readline().rstrip())

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(N, K, x, t, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1422121042
    PT, TT = (T / 60.0, 75.0)
    points = 950 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)
'''

if __name__ == '__main__':
	b = BuildingTowers()
	n = int(raw_input())
	k = int(raw_input())
	x = raw_input().split()
	t = raw_input().split()
	for i in range(0, len(x)): x[i] = int(x[i])
	for i in range(0, len(t)): t[i] = int(t[i])
	b.maxHeight(n,k,x,t)
# }}}
# CUT end
