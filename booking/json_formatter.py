def pretty_json(inp):
	n = len(inp)
	if n == 0: print "Invalid json string"
	start_index, indent_count, temp_str = 0, 0, ""
	while start_index < len(inp):
		temp_str = temp_str + inp[start_index]
		if inp[start_index] == ',':
			indent_str = ""
			for i in range(indent_count): indent_str = indent_str + "\t"
			print indent_str,
			print temp_str
			temp_str = ""			
		elif inp[start_index] == '{' or inp[start_index] == '[':
			indent_count = indent_count + 1
			print temp_str
			indent_str = ""
			for i in range(indent_count): indent_str = indent_str + "\t"
			print indent_str,
			temp_str = ""
		elif inp[start_index] == '}' or inp[start_index] == ']':
			indent_count = indent_count - 1
			print temp_str
			indent_str = ""
			for i in range(indent_count): indent_str = indent_str + "\t"
			print indent_str,
			temp_str = ""
		start_index = start_index + 1

if __name__ == "__main__":
	inp = raw_input()
	print pretty_json(inp) 
