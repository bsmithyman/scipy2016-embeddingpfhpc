from mymod import debug, printf, myarr

def myfunction():
    if debug:
        printf('Starting \'myfunction\'...\n')
        printf('First five elements: ', myarr[:5])
    myarr[:] = myarr**2
    if debug:
        printf('First five elements squared: ', myarr[:5])
        printf('Squared elements in Python.')
