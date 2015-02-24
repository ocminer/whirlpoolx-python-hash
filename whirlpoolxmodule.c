#include <Python.h>

#include "whirlpoolx.h"

static PyObject *whirlpoolx_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    whirlpoolx_hash((char *)PyBytes_AsString((PyObject*) input), output, 80);
#else
    whirlpoolx_hash((char *)PyString_AsString((PyObject*) input), output, 80);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef WhirlpoolxMethods[] = {
    { "getPoWHash", whirlpoolx_getpowhash, METH_VARARGS, "Returns the proof of work hash using whirlpoolx hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef WhirlpoolxModule = {
    PyModuleDef_HEAD_INIT,
    "whirlpoolx_hash",
    "...",
    -1,
    WhirlpoolxMethods
};

PyMODINIT_FUNC PyInit_whirlpoolx_hash(void) {
    return PyModule_Create(&WhirlpoolxModule);
}

#else

PyMODINIT_FUNC initwhirlpoolx_hash(void) {
    (void) Py_InitModule("whirlpoolx_hash", WhirlpoolxMethods);
}
#endif
