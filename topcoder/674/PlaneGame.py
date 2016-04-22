# -*- coding: utf-8 -*-
import math,string,itertools,fractions,heapq,collections,re,array,bisect
class PlaneGame:
	def move_by_angle(self, points, angle):
		new_points = []
		for i in range(0, len(points)):
			x, y = points[i]
			angle = math.radians(angle)
			x1 = (x * math.cos(angle)) - (y * math.sin(angle))
			y1 = (x * math.sin(angle)) + (y * math.cos(angle))
			new_points.append((x1, y1))
		return new_points
	
	def rotate(self, points):
		res = 0
		for i in range(0, len(points)):
			x,y = points[i]
			angle = math.degrees(math.atan(y/x)) if x != 0 else 90
			if angle >= 0 and angle < 90:
				xy1 = self.move_by_angle(points, angle)
				xy2 = self.move_by_angle(points, 90 - angle)
				res = max(res, self.get_count(xy1), self.get_count(xy2))
			elif angle >= 90 and angle < 180:
				xy3 = self.move_by_angle(points, angle - 90)
				xy4 = self.move_by_angle(points, 180 - angle)
				res = max(res, self.get_count(xy3), self.get_count(xy4))
			elif angle >= 180 and angle < 270:
				xy5 = self.move_by_angle(points, angle - 180)
				xy6 = self.move_by_angle(points, 270 - angle)
				res = max(res, self.get_count(xy5), self.get_count(xy6))
			else:
				xy7 = self.move_by_angle(points, angle - 270)
				xy8 = self.move_by_angle(points, 360 - angle)
				res = max(res, self.get_count(xy7), self.get_count(xy8))
		return res

	def get_count(self, values):
		cnt = 0
		for x_co, y_co in values:
			if int(x_co) == 0 or int(y_co) == 0: cnt+=1
		return cnt
	
	def move_by_translate(self, points, val, index):
		new_points = []
		for i in range(0, len(points)):
			x, y = points[i]
			if index == 0:
				new_points.append((x+val, y))
			else:
				new_points.append((x, y+val))
		return new_points

	def translate(self, points):
		res = 0
		for i in range(0, len(points)):
			h, k = points[i]
			positive_x_set = self.move_by_translate(points, h, 0)
			negative_x_set = self.move_by_translate(points, -h, 0)
			positive_y_set = self.move_by_translate(points, k, 1)
			negative_y_set = self.move_by_translate(points, -k, 1)
			res = max(res, self.get_count(positive_x_set), self.get_count(negative_x_set), \
						   self.get_count(positive_y_set), self.get_count(negative_y_set))
		return res

	def bestShot(self, x, y):
		points = [(a,b) for a,b in zip(x,y)]
		res1 = self.translate(points)
		res2 = self.rotate(points)
		return max(res1, res2)

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

def do_test(x, y, __expected):
    startTime = time.time()
    instance = PlaneGame()
    exception = None
    try:
        __result = instance.bestShot(x, y);
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
    sys.stdout.write("PlaneGame (500 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("PlaneGame.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            x = []
            for i in range(0, int(f.readline())):
                x.append(int(f.readline().rstrip()))
            x = tuple(x)
            y = []
            for i in range(0, int(f.readline())):
                y.append(int(f.readline().rstrip()))
            y = tuple(y)
            f.readline()
            __answer = int(f.readline().rstrip())

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(x, y, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1448986162
    PT, TT = (T / 60.0, 75.0)
    points = 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
