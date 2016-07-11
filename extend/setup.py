from distutils.core import setup
from Cython.Build import cythonize
from distutils.extension import Extension

sources = ['hellocy.pyx', 'helloc.c']
extensions = [Extension('hellocy',
                        sources,
                        extra_link_args=['-L/Users/brendan/anaconda/lib', '-lgfortran'],
                        extra_objects=['hellof.o'],
                        extra_compile_args=['-fPIC'],
             )]

setup(
    ext_modules = cythonize(extensions)
)
