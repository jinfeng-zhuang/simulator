f = open("ISA.txt")
lines = f.readlines();

history = '';

print("#include <stdint.h>\n")

for line in lines:
	if (':' not in line):
		continue;

	new_line = '';
	mask = 0;
	value = 0;
	instruction = '';

	for c in line:
		if '\t' == c:
			continue;
		if '\n' == c:
			continue;
		if ' ' == c:
			continue;
		new_line = new_line + c;
	
	instruction = new_line[new_line.index(':') + 1 : ];
	
	for c in new_line:
		if 'x' == c:
			mask = mask << 1 | 0;
		elif (('0' == c) or ('1' == c)):
			mask = mask << 1 | 1;

		if ('1' == c):
			value = value << 1 | 1;
		elif(('0' == c) or ('x' == c)):
			value = value << 1 | 0;
		
		# REV16
		if (':' == c):
			break;

	if ('.' + instruction + '.') in history:
		continue;

	history = history + instruction + '.';
	print("void INSTRUCTION_%s(uint16_t instruction)\n{\n\n}\n" %(instruction));