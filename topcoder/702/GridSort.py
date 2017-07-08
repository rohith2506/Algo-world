'''
Ran without any error in just one time :D
Author: Rohith Uppala
'''

# -*- coding: utf-8 -*-
import math,string,itertools,fractions,heapq,collections,re,array,bisect

class GridSort:
    def number_check(self, dp):
        n, m = len(dp), len(dp[0])
        total_numbers, all_numbers = {}, [val for val in range(1, n*m)]
        for i in range(n):
            for j in range(m):
                if dp[i][j] not in total_numbers:
                    total_numbers[dp[i][j]] = 1
                else:
                    total_numbers[dp[i][j]] += 1
        for num in all_numbers:
            num_val = total_numbers.get(num, 0)
            if num_val == 0 or num_val > 1: return False
        return True

    def row_check(self, dp):
        n, m = len(dp), len(dp[0])
        for i in range(0, len(dp)):
            dp_row = dp[i]
            low, high, temp_dict = min(dp_row), max(dp_row), {}
            row_dict = [val for val in range(low, high+1)]
            for j in range(0, len(dp[i])):
                if dp[i][j] not in temp_dict:
                    temp_dict[dp[i][j]] = 1
                else:
                    temp_dict[dp[i][j]] += 1
            for num in row_dict:
                num_val = temp_dict.get(num, 0)
                if num_val == 0 or num_val > 1: return False
        return True

    def column_check(self, dp):
        n, m = len(dp), len(dp[0])
        for j in range(m):
            columns = []
            for i in range(n):
                columns.append(dp[i][j])
            columns.sort()
            for k in range(0, len(columns) - 1):
                if columns[k+1] - columns[k] != m: return False
        return True

    def sort(self, n, m, grid):
        dp = [[0 for j in range(m)] for i in range(n)]
        for i in range(n):
            for j in range(m):
                dp[i][j] = grid[i*m + j]
        if not self.row_check(dp): return "Impossible"
        if not self.column_check(dp): return "Impossible"
        if not self.number_check(dp): return "Impossible"
        return "Possible"

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

def do_test(n, m, grid, __expected):
    startTime = time.time()
    instance = GridSort()
    exception = None
    try:
        __result = instance.sort(n, m, grid);
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
    sys.stdout.write("GridSort (500 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("GridSort.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            n = int(f.readline().rstrip())
            m = int(f.readline().rstrip())
            grid = []
            for i in range(0, int(f.readline())):
                grid.append(int(f.readline().rstrip()))
            grid = tuple(grid)
            f.readline()
            __answer = f.readline().rstrip()

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(n, m, grid, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1499147075
    PT, TT = (T / 60.0, 75.0)
    points = 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
