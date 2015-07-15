import math

def check(x,y):
        if len(str(x)) > len(str(y)):
                return True
        else:
                return False

def calc():
        numer, denom = 2,1
        main_num, main_den = 0,0
        res = 0
        for i in range(2,1001):
                temp = numer
                numer = (numer * 2) + denom
                denom = temp
#               print numer, denom
                main_num = numer + denom
                main_den = numer
                print str(main_num) + "/" + str(main_den)
                if check(main_num,main_den):
                        print str(main_num) + "/" + str(main_den)
                        res = res + 1
#               numer,denom = denom,numer
#               print numer, denom
        print res

if __name__ == "__main__":
        calc()

