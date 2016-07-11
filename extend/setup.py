from distutils.core import setup
from Cython.Build import cythonize
from distutils.extension import Extension

sources = ['stackcy.pyx', 'stackc.c']
extensions = [Extension('stackcy',
                        sources,
                        extra_link_args=['-L/Users/brendan/anaconda/lib', '-lgfortran'],
                        extra_objects=['stackf.o'],
                        extra_compile_args=['-fPIC'],
             )]

setup(
    ext_modules = cythonize(extensions)
)
