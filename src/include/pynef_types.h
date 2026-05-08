#ifndef PyObject
#include <Python.h>
#endif

struct PythonData{
  PyObject *pArgs;
  PyObject *pName;
  PyObject *pModule;
  PyObject *pFunc;
  PyObject *pValue;
};
