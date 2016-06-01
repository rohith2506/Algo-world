def pretty_call_logger(func):
	def function_wrapper(a,b,c,d=0,e=1,f=2):
		result = "#Output:\n"
		function_name = func.__name__
		result = result + "#" + function_name + " called with:"
		cnt = 1
		first = "#%d:\t%d" %(cnt, a)
		cnt = cnt + 1
		second = "#%d:\t%d" %(cnt, b)
		cnt = cnt + 2
		third = "#%d:\t%d" %(cnt, c)
		result = result + "\n" + first + "\n" + second + "\n" + third + "\n"
		fourth, fifth, sixth = "", "", ""
		if d != 0:
			fourth = 'd:\t' + str(d)
		if e != 1:
			fifth = 'e:\t' + str(e)
		if f != 2:
			sixth = 'f:\t' + str(f)
		if fourth:
			result = result + str(fourth)
			result = result + "\n"
		if fifth:
			result = result + str(fifth)
			result = result + "\n" 
		if sixth:
			result = result + str(sixth)
			result = result + "\n"
		result = result + "#" + function_name + ": " + str(func(a,b,c,d=0,e=1,f=2))
		return result
	return function_wrapper

@pretty_call_logger
def some_function(a,b,c,d=0,e=1,f=2):
	return [42]

print some_function(67, 68, 69, d=5)

