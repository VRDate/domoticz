#pragma once

#include "RFXNames.h"
#include "EventSystem.h"
#include "../hardware/plugins/DelayedLink.h"

#include "structmember.h"

namespace Plugins {
  typedef struct {
      PyObject_HEAD
      PyObject *name; /* first name */
      PyObject *n_value_string;  /* last name */
      int id;
  } PDevice;

  static PyObject * PDevice_Describe(PDevice* self);
  static void PDevice_dealloc(PDevice* self);
  static int PDevice_init(PDevice *self, PyObject *args, PyObject *kwds);
  static PyObject * PDevice_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

  static PyMemberDef PDevice_members[] = {
      {"name", T_OBJECT_EX, offsetof(PDevice, name), 0,
       "Device name"},
      {"n_value_string", T_OBJECT_EX, offsetof(PDevice, n_value_string), 0,
       "Device n_value_string"},
      {"id", T_INT, offsetof(PDevice, id), 0,
       "Device id"},
      {NULL}  /* Sentinel */
  };

  static PyMethodDef PDevice_methods[] = {
      {"Describe", (PyCFunction)PDevice_Describe, METH_NOARGS,
       "Return the name, combining the first and last name"
      },
      {NULL}  /* Sentinel */
  };

  static PyTypeObject PDeviceType = {
      PyVarObject_HEAD_INIT(NULL, 0)
      "DomoticzEvents.PDevice",             /* tp_name */
      sizeof(PDevice),             /* tp_basicsize */
      0,                         /* tp_itemsize */
      (destructor)PDevice_dealloc, /* tp_dealloc */
      0,                         /* tp_print */
      0,                         /* tp_getattr */
      0,                         /* tp_setattr */
      0,                         /* tp_reserved */
      0,                         /* tp_repr */
      0,                         /* tp_as_number */
      0,                         /* tp_as_sequence */
      0,                         /* tp_as_mapping */
      0,                         /* tp_hash  */
      0,                         /* tp_call */
      0,                         /* tp_str */
      0,                         /* tp_getattro */
      0,                         /* tp_setattro */
      0,                         /* tp_as_buffer */
      Py_TPFLAGS_DEFAULT |
          Py_TPFLAGS_BASETYPE,   /* tp_flags */
      "PDevice objects",           /* tp_doc */
      0,                         /* tp_traverse */
      0,                         /* tp_clear */
      0,                         /* tp_richcompare */
      0,                         /* tp_weaklistoffset */
      0,                         /* tp_iter */
      0,                         /* tp_iternext */
      PDevice_methods,             /* tp_methods */
      PDevice_members,             /* tp_members */
      0,                         /* tp_getset */
      0,                         /* tp_base */
      0,                         /* tp_dict */
      0,                         /* tp_descr_get */
      0,                         /* tp_descr_set */
      0,                         /* tp_dictoffset */
      (initproc)PDevice_init,      /* tp_init */
      0,                         /* tp_alloc */
      PDevice_new,                 /* tp_new */
  };

  static PyModuleDef PDevicemodule = {
      PyModuleDef_HEAD_INIT,
      "DomoticzEvents",
      "Example module that creates an extension type.",
      -1,
      NULL, NULL, NULL, NULL, NULL
  };
}
