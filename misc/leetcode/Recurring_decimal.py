'''
Only trciky part is dictioanry mod.
How did he do it??

let's say 0.147851...
 First when 1 encouters mod[1] = 0(index) will be stored
 now when again 1 encounters, it's already present
   so first for loop is from (0 to 0)
   and second for loop is from (1 to 5)(5 is the index where it again occured)
   and return the solution
   This piece i missed.
'''
class Solution:
    # @return a string
    def fractionToDecimal(self, numerator, denominator):
        a, b = numerator, denominator
        d = float(a) / b
        ret = str(abs(int(d)))
        if d < 0:
            a = abs(a)
            b = abs(b)
            ret = '-' + ret

        a = a % b
        if not a:
            return ret

        ret += '.'
        result = []
        index = 0
        mod = {}
        while True:
            p = a % b
            a = p * 10
            if not a:
                for c in result:
                    ret += str(c)
                return ret
            result.append(a / b)

            if p not in mod:
                mod[p] = index
            else:
                for i in range(mod[p]):
                    ret += str(result[i])
                ret += '('
                for i in range(mod[p], index):
                    ret += str(result[i])
                ret += ')'
                return ret

            index += 1