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
/* BINDTOOL_HEADER_FILE(flexi_source.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(58edbdbaa9b9343daeb878c6bc56332e)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <iio/flexi_source.h>
// pydoc.h is automatically generated in the build directory
#include <flexi_source_pydoc.h>

void bind_flexi_source(py::module& m)
{

    using flexi_source    = ::gr::iio::flexi_source;


    py::class_<flexi_source, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<flexi_source>>(m, "flexi_source", D(flexi_source))

        .def(py::init(&flexi_source::make),
           py::arg("uri"),
           py::arg("device"),
           py::arg("channels"),
           py::arg("device_phy"),
           py::arg("devparams"),
           py::arg("phyparams"),
           py::arg("buffer_size") = 32768,
           py::arg("decimation") = 0,
           D(flexi_source,make)
        )
        .def("set_buffer_size",&flexi_source::set_buffer_size,       
            py::arg("buffer_size"),
            D(flexi_source,set_buffer_size)
        )
        .def("set_timeout_ms",&flexi_source::set_timeout_ms,       
            py::arg("timeout"),
            D(flexi_source,set_timeout_ms)
        )
        ;




}








