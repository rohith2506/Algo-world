'''
Not too much clarity on how bit masking works
Especially the lines from 23 to 26. Need more practice
@Author: Rohith Uppala
'''

# -*- coding: utf-8 -*-
import math,string,itertools,fractions,heapq,collections,re,array,bisect
import pdb

class SubsetSumExtreme:
    def getExpectation(self, block, face):
        su = [0 for i in range(10101)]
        f = [0.0 for i in range(10101)]
        n, m = len(block), len(face)
        for i in range(0, (1 << n)):
            for j in range(0, n):
                if((i >> j) & 1): su[i] += block[j]
        for i in range(0, (1 << n)):
            f[i] = 0
            for j in range(0, m):
                tmp, k = su[i], i
                while k > 0:
                    if su[k] == face[j] and f[i^k] < tmp:
                        tmp = f[i^k]
                    k = (k - 1) & i
                f[i] = f[i] + tmp
            f[i] = f[i] * 1.0 / m
        return f[(1 << n) - 1]

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

def do_test(block, face, __expected):
    startTime = time.time()
    instance = SubsetSumExtreme()
    exception = None
    try:
        __result = instance.getExpectation(block, face);
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
    sys.stdout.write("SubsetSumExtreme (1000 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("SubsetSumExtreme.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            block = []
            for i in range(0, int(f.readline())):
                block.append(int(f.readline().rstrip()))
            block = tuple(block)
            face = []
            for i in range(0, int(f.readline())):
                face.append(int(f.readline().rstrip()))
            face = tuple(face)
            f.readline()
            __answer = float(f.readline().rstrip())

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(block, face, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1499150083
    PT, TT = (T / 60.0, 75.0)
    points = 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
