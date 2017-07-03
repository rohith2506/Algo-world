'''
Algorithm: Tree Traversal
Solution: https://community.topcoder.com/stat?c=problem_solution&cr=23057666&rd=16884&pm=14610
Author: Rohith Uppala
'''

# -*- coding: utf-8 -*-
import math,string,itertools,fractions,heapq,collections,re,array,bisect

class InPrePost:
    def solve(self, s, preorder, inorder, postorder):
        if not preorder: return True
        label = preorder[0]
        if label not in inorder: return False
        if label != postorder[-1]: return False
        idx = inorder.index(label)
        s2_left, s3_right = inorder[0:idx], inorder[idx+1:]
        l, r = len(s2_left), len(s3_right)
        s0_left, s1_right = preorder[1:1+l], preorder[1+l:]
        s4_left, s5_right = postorder[0:l], postorder[l:-1]
        cl_pre, cl_in, cl_post = [], [], []
        cr_pre, cr_in, cr_post = [], [], []
        for left, ix in ((s0_left, 0), (s2_left, 2), (s4_left, 4)):
            if s[ix] == 'pre': cl_pre.append(left)
            elif s[ix] == 'in': cl_in.append(left)
            else: cl_post.append(left)
        if not self.solve(s, cl_pre[0], cl_in[0], cl_post[0]): return False
        for right, ix in ((s1_right, 1), (s3_right, 3), (s5_right, 5)):
            if s[ix] == 'pre': cr_pre.append(right)
            elif s[ix] == 'in': cr_in.append(right)
            else: cr_post.append(right)
        if not self.solve(s, cr_pre[0], cr_in[0], cr_post[0]): return False
        return True

    def isPossible(self, s, a1, a2, a3):
        YES, NO = "Possible", "Impossible"
        if self.solve(s, a1, a2, a3): return YES
        else: return NO


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

def do_test(s, a1, a2, a3, __expected):
    startTime = time.time()
    instance = InPrePost()
    exception = None
    try:
        __result = instance.isPossible(s, a1, a2, a3);
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
    sys.stdout.write("InPrePost (1000 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("InPrePost.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            s = []
            for i in range(0, int(f.readline())):
                s.append(f.readline().rstrip())
            s = tuple(s)
            a1 = []
            for i in range(0, int(f.readline())):
                a1.append(int(f.readline().rstrip()))
            a1 = tuple(a1)
            a2 = []
            for i in range(0, int(f.readline())):
                a2.append(int(f.readline().rstrip()))
            a2 = tuple(a2)
            a3 = []
            for i in range(0, int(f.readline())):
                a3.append(int(f.readline().rstrip()))
            a3 = tuple(a3)
            f.readline()
            __answer = f.readline().rstrip()

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(s, a1, a2, a3, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1499061043
    PT, TT = (T / 60.0, 75.0)
    points = 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
