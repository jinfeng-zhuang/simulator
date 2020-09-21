while 1:
    inst = raw_input("Enter inst: ");
    f = open('%s.cpp' %inst, 'w')
    f.write('#include <common.h>\n\n')
    f.write('void INSTRUCTION_%s(U16 inst)\n{\n\t\n}' %(inst.upper()))
    f.close()