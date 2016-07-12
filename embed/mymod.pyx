
cdef extern from "stdio.h":
    int printf(const char* format, ...)

def cprintf(msg):
    printf(msg)
