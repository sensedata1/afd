/********************************************************
 Audio Tools, a module and set of tools for manipulating audio data
 Copyright (C) 2007-2015  Brian Langenberger

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*******************************************************/

PyMethodDef module_methods[] = {
    {NULL}
};

typedef struct {
    PyObject_HEAD

    struct PCMReader *pcmreader;
    PyObject* audiotools_pcm;
} pcmconverter_Averager;

static PyObject*
Averager_sample_rate(pcmconverter_Averager *self, void *closure);

static PyObject*
Averager_bits_per_sample(pcmconverter_Averager *self, void *closure);

static PyObject*
Averager_channels(pcmconverter_Averager *self, void *closure);

static PyObject*
Averager_channel_mask(pcmconverter_Averager *self, void *closure);

static PyObject*
Averager_read(pcmconverter_Averager *self, PyObject *args);

static PyObject*
Averager_close(pcmconverter_Averager *self, PyObject *args);

static PyObject*
Averager_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

int
Averager_init(pcmconverter_Averager *self, PyObject *args, PyObject *kwds);

void
Averager_dealloc(pcmconverter_Averager *self);

PyGetSetDef Averager_getseters[] = {
    {"sample_rate", (getter)Averager_sample_rate, NULL, "sample rate", NULL},
    {"bits_per_sample", (getter)Averager_bits_per_sample, NULL, "bits per sample", NULL},
    {"channels", (getter)Averager_channels, NULL, "channels", NULL},
    {"channel_mask", (getter)Averager_channel_mask, NULL, "channel_mask", NULL},
    {NULL}
};

PyMethodDef Averager_methods[] = {
    {"read", (PyCFunction)Averager_read, METH_VARARGS, ""},
    {"close", (PyCFunction)Averager_close, METH_NOARGS, ""},
    {NULL}
};

PyTypeObject pcmconverter_AveragerType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "pcmconverter.Averager",   /*tp_name*/
    sizeof(pcmconverter_Averager),/*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)Averager_dealloc, /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    "Averager objects",        /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    Averager_methods,          /* tp_methods */
    0,                         /* tp_members */
    Averager_getseters,        /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)Averager_init,   /* tp_init */
    0,                         /* tp_alloc */
    Averager_new,              /* tp_new */
};


typedef struct {
    PyObject_HEAD

    struct PCMReader *pcmreader;
    PyObject* audiotools_pcm;
} pcmconverter_Downmixer;

static PyObject*
Downmixer_sample_rate(pcmconverter_Downmixer *self, void *closure);

static PyObject*
Downmixer_bits_per_sample(pcmconverter_Downmixer *self, void *closure);

static PyObject*
Downmixer_channels(pcmconverter_Downmixer *self, void *closure);

static PyObject*
Downmixer_channel_mask(pcmconverter_Downmixer *self, void *closure);

static PyObject*
Downmixer_read(pcmconverter_Downmixer *self, PyObject *args);

static PyObject*
Downmixer_close(pcmconverter_Downmixer *self, PyObject *args);

static PyObject*
Downmixer_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

int
Downmixer_init(pcmconverter_Downmixer *self, PyObject *args, PyObject *kwds);

void
Downmixer_dealloc(pcmconverter_Downmixer *self);

PyGetSetDef Downmixer_getseters[] = {
    {"sample_rate", (getter)Downmixer_sample_rate, NULL, "sample rate", NULL},
    {"bits_per_sample", (getter)Downmixer_bits_per_sample, NULL, "bits per sample", NULL},
    {"channels", (getter)Downmixer_channels, NULL, "channels", NULL},
    {"channel_mask", (getter)Downmixer_channel_mask, NULL, "channel_mask", NULL},
    {NULL}
};

PyMethodDef Downmixer_methods[] = {
    {"read", (PyCFunction)Downmixer_read, METH_VARARGS, ""},
    {"close", (PyCFunction)Downmixer_close, METH_NOARGS, ""},
    {NULL}
};

PyTypeObject pcmconverter_DownmixerType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "pcmconverter.Downmixer",  /*tp_name*/
    sizeof(pcmconverter_Downmixer),/*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)Downmixer_dealloc, /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    "Downmixer objects",       /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    Downmixer_methods,         /* tp_methods */
    0,                         /* tp_members */
    Downmixer_getseters,       /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)Downmixer_init,  /* tp_init */
    0,                         /* tp_alloc */
    Downmixer_new,             /* tp_new */
};

typedef struct {
    PyObject_HEAD

    struct PCMReader *pcmreader;
    SRC_STATE *src_state;            /*libsamplerate's internal state*/
    SRC_DATA src_data;               /*libsamplerate's processing state*/
    int sample_rate;                 /*the output sample rate*/
    PyObject* audiotools_pcm;
} pcmconverter_Resampler;

static PyObject*
Resampler_sample_rate(pcmconverter_Resampler *self, void *closure);

static PyObject*
Resampler_bits_per_sample(pcmconverter_Resampler *self, void *closure);

static PyObject*
Resampler_channels(pcmconverter_Resampler *self, void *closure);

static PyObject*
Resampler_channel_mask(pcmconverter_Resampler *self, void *closure);

static PyObject*
Resampler_read(pcmconverter_Resampler *self, PyObject *args);

static PyObject*
Resampler_close(pcmconverter_Resampler *self, PyObject *args);

static PyObject*
Resampler_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

int
Resampler_init(pcmconverter_Resampler *self, PyObject *args, PyObject *kwds);

void
Resampler_dealloc(pcmconverter_Resampler *self);

PyGetSetDef Resampler_getseters[] = {
    {"sample_rate", (getter)Resampler_sample_rate, NULL, "sample rate", NULL},
    {"bits_per_sample", (getter)Resampler_bits_per_sample, NULL, "bits per sample", NULL},
    {"channels", (getter)Resampler_channels, NULL, "channels", NULL},
    {"channel_mask", (getter)Resampler_channel_mask, NULL, "channel_mask", NULL},
    {NULL}
};

PyMethodDef Resampler_methods[] = {
    {"read", (PyCFunction)Resampler_read, METH_VARARGS, ""},
    {"close", (PyCFunction)Resampler_close, METH_NOARGS, ""},
    {NULL}
};

PyTypeObject pcmconverter_ResamplerType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "pcmconverter.Resampler",  /*tp_name*/
    sizeof(pcmconverter_Resampler),/*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)Resampler_dealloc, /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    "Resampler objects",       /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    Resampler_methods,         /* tp_methods */
    0,                         /* tp_members */
    Resampler_getseters,       /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)Resampler_init,  /* tp_init */
    0,                         /* tp_alloc */
    Resampler_new,             /* tp_new */
};

typedef struct {
    PyObject_HEAD

    struct PCMReader *pcmreader;
    int bits_per_sample;
    BitstreamReader *white_noise;
    PyObject *audiotools_pcm;
} pcmconverter_BPSConverter;

static PyObject*
BPSConverter_sample_rate(pcmconverter_BPSConverter *self, void *closure);

static PyObject*
BPSConverter_bits_per_sample(pcmconverter_BPSConverter *self, void *closure);

static PyObject*
BPSConverter_channels(pcmconverter_BPSConverter *self, void *closure);

static PyObject*
BPSConverter_channel_mask(pcmconverter_BPSConverter *self, void *closure);

static PyObject*
BPSConverter_read(pcmconverter_BPSConverter *self, PyObject *args);

static PyObject*
BPSConverter_close(pcmconverter_BPSConverter *self, PyObject *args);

static PyObject*
BPSConverter_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

int
BPSConverter_init(pcmconverter_BPSConverter *self,
                  PyObject *args, PyObject *kwds);

void
BPSConverter_dealloc(pcmconverter_BPSConverter *self);

PyGetSetDef BPSConverter_getseters[] = {
    {"sample_rate", (getter)BPSConverter_sample_rate,
     NULL, "sample rate", NULL},
    {"bits_per_sample", (getter)BPSConverter_bits_per_sample,
     NULL, "bits per sample", NULL},
    {"channels", (getter)BPSConverter_channels,
     NULL, "channels", NULL},
    {"channel_mask", (getter)BPSConverter_channel_mask,
     NULL, "channel_mask", NULL},
    {NULL}
};

PyMethodDef BPSConverter_methods[] = {
    {"read", (PyCFunction)BPSConverter_read, METH_VARARGS, ""},
    {"close", (PyCFunction)BPSConverter_close, METH_NOARGS, ""},
    {NULL}
};

PyTypeObject pcmconverter_BPSConverterType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "pcmconverter.BPSConverter", /*tp_name*/
    sizeof(pcmconverter_BPSConverter),/*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)BPSConverter_dealloc, /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    "BPSConverter objects",    /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    BPSConverter_methods,      /* tp_methods */
    0,                         /* tp_members */
    BPSConverter_getseters,    /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)BPSConverter_init, /* tp_init */
    0,                         /* tp_alloc */
    BPSConverter_new,          /* tp_new */
};


typedef struct {
    PyObject_HEAD

    int closed;
    struct PCMReader *pcmreader;
    PyObject *audiotools_pcm;
} pcmconverter_BufferedPCMReader;

static PyObject*
BufferedPCMReader_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

int
BufferedPCMReader_init(pcmconverter_BufferedPCMReader *self,
                       PyObject *args, PyObject *kwds);

void
BufferedPCMReader_dealloc(pcmconverter_BufferedPCMReader *self);

static PyObject*
BufferedPCMReader_sample_rate(pcmconverter_BufferedPCMReader *self,
                              void *closure);

static PyObject*
BufferedPCMReader_bits_per_sample(pcmconverter_BufferedPCMReader *self,
                                  void *closure);

static PyObject*
BufferedPCMReader_channels(pcmconverter_BufferedPCMReader *self,
                           void *closure);

static PyObject*
BufferedPCMReader_channel_mask(pcmconverter_BufferedPCMReader *self,
                               void *closure);

static PyObject*
BufferedPCMReader_read(pcmconverter_BufferedPCMReader *self, PyObject *args);

static PyObject*
BufferedPCMReader_close(pcmconverter_BufferedPCMReader *self, PyObject *args);

static PyObject*
BufferedPCMReader_enter(pcmconverter_BufferedPCMReader *self, PyObject *args);

static PyObject*
BufferedPCMReader_exit(pcmconverter_BufferedPCMReader *self, PyObject *args);

PyGetSetDef BufferedPCMReader_getseters[] = {
    {"sample_rate", (getter)BufferedPCMReader_sample_rate,
     NULL, "sample rate", NULL},
    {"bits_per_sample", (getter)BufferedPCMReader_bits_per_sample,
     NULL, "bits per sample", NULL},
    {"channels", (getter)BufferedPCMReader_channels,
     NULL, "channels", NULL},
    {"channel_mask", (getter)BufferedPCMReader_channel_mask,
     NULL, "channel_mask", NULL},
    {NULL}
};

PyMethodDef BufferedPCMReader_methods[] = {
    {"read", (PyCFunction)BufferedPCMReader_read, METH_VARARGS, ""},
    {"close", (PyCFunction)BufferedPCMReader_close, METH_NOARGS, ""},
    {"__enter__", (PyCFunction)BufferedPCMReader_enter,
     METH_NOARGS, "enter() -> self"},
    {"__exit__", (PyCFunction)BufferedPCMReader_exit,
     METH_VARARGS, "exit(exc_type, exc_value, traceback) -> None"},
    {NULL}
};

PyTypeObject pcmconverter_BufferedPCMReaderType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "pcmconverter.BufferedPCMReader", /*tp_name*/
    sizeof(pcmconverter_BufferedPCMReader), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)BufferedPCMReader_dealloc, /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    "BufferedPCMReader objects", /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    BufferedPCMReader_methods, /* tp_methods */
    0,                         /* tp_members */
    BufferedPCMReader_getseters, /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)BufferedPCMReader_init, /* tp_init */
    0,                         /* tp_alloc */
    BufferedPCMReader_new,     /* tp_new */
};


typedef struct {
    PyObject_HEAD

    int closed;
    struct PCMReader *pcmreader;

    unsigned frame_index;
    unsigned frame_total;

    PyObject *audiotools_pcm;
} pcmconverter_FadeInReader;

static PyObject*
FadeInReader_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

int
FadeInReader_init(pcmconverter_FadeInReader *self,
                  PyObject *args, PyObject *kwds);

void
FadeInReader_dealloc(pcmconverter_FadeInReader *self);

static PyObject*
FadeInReader_sample_rate(pcmconverter_FadeInReader *self,
                         void *closure);

static PyObject*
FadeInReader_bits_per_sample(pcmconverter_FadeInReader *self,
                             void *closure);

static PyObject*
FadeInReader_channels(pcmconverter_FadeInReader *self,
                      void *closure);

static PyObject*
FadeInReader_channel_mask(pcmconverter_FadeInReader *self,
                          void *closure);

static PyObject*
FadeInReader_read(pcmconverter_FadeInReader *self, PyObject *args);

static PyObject*
FadeInReader_close(pcmconverter_FadeInReader *self, PyObject *args);

PyGetSetDef FadeInReader_getseters[] = {
    {"sample_rate", (getter)FadeInReader_sample_rate,
     NULL, "sample rate", NULL},
    {"bits_per_sample", (getter)FadeInReader_bits_per_sample,
     NULL, "bits per sample", NULL},
    {"channels", (getter)FadeInReader_channels,
     NULL, "channels", NULL},
    {"channel_mask", (getter)FadeInReader_channel_mask,
     NULL, "channel_mask", NULL},
    {NULL}
};

PyMethodDef FadeInReader_methods[] = {
    {"read", (PyCFunction)FadeInReader_read, METH_VARARGS, ""},
    {"close", (PyCFunction)FadeInReader_close, METH_NOARGS, ""},
    {NULL}
};

PyTypeObject pcmconverter_FadeInReaderType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "pcmconverter.FadeInReader", /*tp_name*/
    sizeof(pcmconverter_FadeInReader), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)FadeInReader_dealloc, /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    "FadeInReader objects", /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    FadeInReader_methods,      /* tp_methods */
    0,                         /* tp_members */
    FadeInReader_getseters,    /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)FadeInReader_init, /* tp_init */
    0,                         /* tp_alloc */
    FadeInReader_new,          /* tp_new */
};


typedef struct {
    PyObject_HEAD

    int closed;
    struct PCMReader *pcmreader;

    unsigned frame_index;
    unsigned frame_total;

    PyObject *audiotools_pcm;
} pcmconverter_FadeOutReader;

static PyObject*
FadeOutReader_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

int
FadeOutReader_init(pcmconverter_FadeOutReader *self,
                   PyObject *args, PyObject *kwds);

void
FadeOutReader_dealloc(pcmconverter_FadeOutReader *self);

static PyObject*
FadeOutReader_sample_rate(pcmconverter_FadeOutReader *self,
                          void *closure);

static PyObject*
FadeOutReader_bits_per_sample(pcmconverter_FadeOutReader *self,
                              void *closure);

static PyObject*
FadeOutReader_channels(pcmconverter_FadeOutReader *self,
                       void *closure);

static PyObject*
FadeOutReader_channel_mask(pcmconverter_FadeOutReader *self,
                           void *closure);

static PyObject*
FadeOutReader_read(pcmconverter_FadeOutReader *self, PyObject *args);

static PyObject*
FadeOutReader_close(pcmconverter_FadeOutReader *self, PyObject *args);

PyGetSetDef FadeOutReader_getseters[] = {
    {"sample_rate", (getter)FadeOutReader_sample_rate,
     NULL, "sample rate", NULL},
    {"bits_per_sample", (getter)FadeOutReader_bits_per_sample,
     NULL, "bits per sample", NULL},
    {"channels", (getter)FadeOutReader_channels,
     NULL, "channels", NULL},
    {"channel_mask", (getter)FadeOutReader_channel_mask,
     NULL, "channel_mask", NULL},
    {NULL}
};

PyMethodDef FadeOutReader_methods[] = {
    {"read", (PyCFunction)FadeOutReader_read, METH_VARARGS, ""},
    {"close", (PyCFunction)FadeOutReader_close, METH_NOARGS, ""},
    {NULL}
};

PyTypeObject pcmconverter_FadeOutReaderType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "pcmconverter.FadeOutReader", /*tp_name*/
    sizeof(pcmconverter_FadeOutReader), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)FadeOutReader_dealloc, /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    "FadeOutReader objects",   /* tp_doc */
    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    0,                         /* tp_iter */
    0,                         /* tp_iternext */
    FadeOutReader_methods,     /* tp_methods */
    0,                         /* tp_members */
    FadeOutReader_getseters,   /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)FadeOutReader_init, /* tp_init */
    0,                         /* tp_alloc */
    FadeOutReader_new,         /* tp_new */
};
