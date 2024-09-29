/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(device_sink.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(dc3c3b315db5326d73e95d64cc7f448e)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <iio/device_sink.h>
// pydoc.h is automatically generated in the build directory
#include <device_sink_pydoc.h>

void bind_device_sink(py::module& m)
{

    using device_sink    = ::gr::iio::device_sink;


    py::class_<device_sink, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<device_sink>>(m, "device_sink", D(device_sink))

        .def(py::init(&device_sink::make),
           py::arg("uri"),
           py::arg("device"),
           py::arg("channels"),
           py::arg("device_phy"),
           py::arg("params"),
           py::arg("buffer_size") = 32768,
           py::arg("interpolation") = 0,
           py::arg("cyclic") = false,
           D(device_sink,make)
        )
        ;
}







