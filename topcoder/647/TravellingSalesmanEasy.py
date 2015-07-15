'''
Still unsolved
'''

# -*- coding: utf-8 -*-
import math,string,itertools,fractions,heapq,collections,re,array,bisect

class TravellingSalesmanEasy:
    def getMaxProfit(self, M, profit, city, visit):
		max_profit = 0
		d = dict()
		for i in range(1, M+1):
			if i not in d.keys():
				d[i] = []
		profits = [p for p in profit]
		cities = [c for c in city]
		visits = [v for v in visit]
		for i in range(0, len(cities)):
			d[cities[i]].append(profits[i])
		for k,v in d.items():
			lst = d[k]
			lst.sort()
			lst = lst[::-1]
			d[k] = lst
		for i in range(0, len(visits)):
			ct = visits[i]
			lst = d[ct]
			if lst:
				max_profit = max_profit + lst[0]
				d[ct] = lst[1:]
		return max_profit


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

def do_test(M, profit, city, visit, __expected):
    startTime = time.time()
    instance = TravellingSalesmanEasy()
    exception = None
    try:
        __result = instance.getMaxProfit(M, profit, city, visit);
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
    sys.stdout.write("TravellingSalesmanEasy (500 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("TravellingSalesmanEasy.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            M = int(f.readline().rstrip())
            profit = []
            for i in range(0, int(f.readline())):
                profit.append(int(f.readline().rstrip()))
            profit = tuple(profit)
            city = []
            for i in range(0, int(f.readline())):
                city.append(int(f.readline().rstrip()))
            city = tuple(city)
            visit = []
            for i in range(0, int(f.readline())):
                visit.append(int(f.readline().rstrip()))
            visit = tuple(visit)
            f.readline()
            __answer = int(f.readline().rstrip())

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(M, profit, city, visit, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1422119475
    PT, TT = (T / 60.0, 75.0)
    points = 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
