/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <pybind11/pybind11.h>

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/arrayobject.h>

namespace py = pybind11;

// Headers for binding functions
/**************************************/
// The following comment block is used for
// gr_modtool to insert function prototypes
// Please do not delete
/**************************************/
// BINDING_FUNCTION_PROTOTYPES(
void bind_attr_sink(py::module& m);
void bind_attr_source(py::module& m);
void bind_attr_updater(py::module& m);
void bind_device_sink(py::module& m);
void bind_device_source(py::module& m);
void bind_eightbit_sink(py::module& m);
void bind_eightbit_source(py::module& m);
void bind_thirtytwobit_sink(py::module& m);
void bind_thirtytwobit_source(py::module& m);
void bind_flexi_source(py::module& m);
void bind_fmcomms2_sink(py::module& m);
void bind_fmcomms2_source(py::module& m);
void bind_fmcomms5_sink(py::module& m);
void bind_fmcomms5_source(py::module& m);
void bind_hnchbbboard_source(py::module& m);
void bind_hnchboard2_source(py::module& m);
void bind_hnchboard2u_source(py::module& m);
void bind_multi_source(py::module& m);
void bind_pluto_sink(py::module& m);
void bind_pluto_source(py::module& m);
// ) END BINDING_FUNCTION_PROTOTYPES


// We need this hack because import_array() returns NULL
// for newer Python versions.
// This function is also necessary because it ensures access to the C API
// and removes a warning.
void* init_numpy()
{
    import_array();
    return NULL;
}

PYBIND11_MODULE(iio_python, m)
{
    // Initialize the numpy C API
    // (otherwise we will see segmentation faults)
    init_numpy();

    // Allow access to base block methods
    py::module::import("gnuradio.gr");

    /**************************************/
    // The following comment block is used for
    // gr_modtool to insert binding function calls
    // Please do not delete
    /**************************************/
    // BINDING_FUNCTION_CALLS(
bind_attr_sink(m);
bind_attr_source(m);
bind_attr_updater(m);
bind_device_sink(m);
bind_device_source(m);
bind_eightbit_sink(m);
bind_eightbit_source(m);
bind_thirtytwobit_sink(m);
bind_thirtytwobit_source(m);
bind_flexi_source(m);
bind_fmcomms2_sink(m);
bind_fmcomms2_source(m);
bind_fmcomms5_sink(m);
bind_fmcomms5_source(m);
bind_hnchbbboard_source(m);
bind_hnchboard2_source(m);
bind_hnchboard2u_source(m);
bind_multi_source(m);
bind_pluto_sink(m);
bind_pluto_source(m);
    // ) END BINDING_FUNCTION_CALLS
}
