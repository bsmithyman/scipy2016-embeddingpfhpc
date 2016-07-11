
cdef extern void stackc()
cdef extern void stackf_()
cdef extern void stackf_callc_()

def stackcy():
    print(' Y: in \'stackcy\'')
    stackc()

def stackcy_noc():
    print(' Y: in \'stackcy_noc\'')
    stackf_()

def stackcy_fc():
    print(' Y: in \'stackcy_fc\'')
    stackf_callc_()
