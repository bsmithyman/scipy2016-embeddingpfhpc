import mymod

def dbprint(msg):
    if mymod.DEBUG:
        mymod.cprintf(msg)

def myfunction():
    dbprint('Starting \'myfunction\'...\n')
    pymyarr = mymod.myarr
    dbprint('First five elements:\n{}\n'.format(pymyarr[:5]))
    pymyarr[:] = pymyarr**2
    dbprint('First five elements squared:\n{}\n'.format(pymyarr[:5]))
    dbprint('Squared elements in Python.\n')
