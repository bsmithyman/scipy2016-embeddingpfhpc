
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#define MODULE_NAME "mymod"
#define EXTENSION_FILE "extend.py"
#define NEWLINE 0xA
#define NULLCHAR 0x0

#include <Python.h>
#include <numpy/arrayobject.h>
#include <stdio.h>
#include <string.h>

PyMODINIT_FUNC initmymod(void);

void init_py_() {
    FILE *fp;
    PyObject *module, *debug;

    Py_Initialize();
    import_array();

    initmymod();
    module = PyImport_AddModule(MODULE_NAME);

    debug = PyBool_FromLong(DEBUG);
    PyObject_SetAttrString(module, "DEBUG", debug);
    Py_DECREF(debug);

    fp = fopen(EXTENSION_FILE, "r");
    if (fp != NULL)
        PyRun_SimpleFile(fp, EXTENSION_FILE);
    fclose(fp);
}

void dest_py_() {
    Py_Finalize();
}

char * process_label (char *name, unsigned int slen) {
    char *label;
    size_t i;

    label = malloc(slen+1);

    for (i = 0; i < slen; i++)
        label[i] = name[i];

    label[slen] = NULLCHAR;
    return label;
}

void run_py_ (char *func, unsigned int slen) {
  char *runstr;

  runstr = process_label(func, slen+1);
  runstr[slen] = NEWLINE;

  PyRun_SimpleString(runstr);
  free(runstr);
}

void register_general_array (char *label, void *reference, unsigned int ndims, npy_intp dims[], int typenum) {

    PyObject *arr, *module;

    // Map a numpy array of the given size and type to the pointer
    // 'reference', which points to the beginning of the Fortran array
    arr = PyArray_New(&PyArray_Type, ndims, dims, typenum, (npy_intp *) NULL, reference, -1, NPY_ARRAY_FARRAY, (PyObject *) NULL);

    // Get a handle to the fullwv Python module (parent of global objects)
    module = PyImport_AddModule(MODULE_NAME);

    // Attach the array to the global variable list in Python
    PyObject_SetAttrString(module, label, arr);

    Py_DECREF(arr);
}

// 1D array registration routine for REAL arrays
void register_1d_real_array_ (char *name, void *reference, signed int *dim0, unsigned int slen) {
  char *label;
  npy_intp dims[1];

  dims[0] = *dim0;

  label = process_label(name, slen);
  register_general_array(label, reference, 1, dims, NPY_FLOAT);
  free(label);
}
