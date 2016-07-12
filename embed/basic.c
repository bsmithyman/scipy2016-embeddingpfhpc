
#include <stdio.h>
#include <Python.h>

int main(int argc, char *argv[]) {
    Py_SetProgramName(argv[0]);
    Py_Initialize();
    printf(" C: Hello World!\n");
    PyRun_SimpleString("print ' P: Hello World!'\n");
    Py_Finalize();
    return 0;
}
