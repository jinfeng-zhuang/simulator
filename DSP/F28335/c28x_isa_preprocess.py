f = open("c28x_isa.txt", "rb")
lines = f.readlines()
for line in lines:
	line_list = list(line)
	for idx in range(0, len(line_list)):
		if int(line_list[idx].encode('hex'), 16) > 128:
			line_list[idx] = '-'
	newline = "".join(line_list)

	split_pos = newline.find('-')

	part_inst = newline[:split_pos]
	part_desc = newline[split_pos+1:]
	
	part_desc = part_desc.replace('-', '').strip()
	
	split_pos = part_desc.find('.')
	part_desc = part_desc[:split_pos]
	
	# generate excel with '#' '<<' ...
	#print part_inst + '\t' + part_desc
	
	# now remove '#', ...
	part_inst = part_inst.strip()
	
	part_inst = part_inst.replace(' ', '_');
	part_inst = part_inst.replace(',', '_');
	part_inst = part_inst.replace(".", '_');
	
	part_inst = part_inst.replace("(", '_index_');
	part_inst = part_inst.replace(")", '_');
	part_inst = part_inst.replace('{', '_optional_');
	part_inst = part_inst.replace('}', '_');
	
	part_inst = part_inst.replace('~', '_not_');
	part_inst = part_inst.replace('*', '_pointer_');
	part_inst = part_inst.replace(':', '_colon_');
	part_inst = part_inst.replace('/', '_slash_');
	part_inst = part_inst.replace('+', '_plus_');
	part_inst = part_inst.replace('#', '_imm_');
	part_inst = part_inst.replace("<<", '_leftshift_');
	
	part_inst = part_inst.replace('__', '_');
	part_inst = part_inst.replace('__', '_');
	part_inst = part_inst.replace('__', '_');
	
	if part_inst[-1] == '_':
		part_inst = part_inst[:-1]
	
	print part_inst + '\t' + part_desc