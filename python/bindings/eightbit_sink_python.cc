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
/* BINDTOOL_HEADER_FILE(eightbit_sink.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(8f2d6aeb677da089b4eb16d2500adffa)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <iio/eightbit_sink.h>
// pydoc.h is automatically generated in the build directory
#include <eightbit_sink_pydoc.h>

void bind_eightbit_sink(py::module& m)
{

    using eightbit_sink    = ::gr::iio::eightbit_sink;


    py::class_<eightbit_sink, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<eightbit_sink>>(m, "eightbit_sink", D(eightbit_sink))

        .def(py::init(&eightbit_sink::make),
           py::arg("uri"),
           py::arg("device"),
           py::arg("channels"),
           py::arg("device_phy"),
           py::arg("params"),
           py::arg("buffer_size") = 32768,
           py::arg("interpolation") = 0,
           py::arg("cyclic") = false,
           D(eightbit_sink,make)
        )
        ;




}








