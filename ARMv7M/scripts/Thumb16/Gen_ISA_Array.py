f = open("ISA.txt")
lines = f.readlines();

print("#include \"isa.h\"\n")
print("struct ISA ISA_Array[] = {")

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

	print("\t{0x%04x, 0x%04x, INSTRUCTION_%s, \"%s\"}," %(mask, value, instruction, instruction));

print("\t{0, 0, 0}");
print("};")