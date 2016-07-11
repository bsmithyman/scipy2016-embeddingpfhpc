#!/usr/bin/env python

import multiprocessing

def msg(i):
    return 'P: Hello World from {}!'.format(i)

p = multiprocessing.Pool(4)
for line in p.map(msg, xrange(4)):
    print(line)
p.close()
