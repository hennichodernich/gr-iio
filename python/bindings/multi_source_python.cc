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
/* BINDTOOL_HEADER_FILE(multi_source.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(a42c08720b441140089275d05c1414bd)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <iio/multi_source.h>
// pydoc.h is automatically generated in the build directory
#include <multi_source_pydoc.h>

void bind_multi_source(py::module& m)
{

    using multi_source    = ::gr::iio::multi_source;


    py::class_<multi_source, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<multi_source>>(m, "multi_source", D(multi_source))

        .def(py::init(&multi_source::make),
           py::arg("uri"),
           py::arg("device"),
           py::arg("channels"),
           py::arg("device_phy1"),
           py::arg("params1"),
           py::arg("device_phy2"),
           py::arg("params2"),
           py::arg("buffer_size") = 32768,
           py::arg("decimation") = 0,
           D(multi_source,make)
        )
        .def("set_buffer_size",&multi_source::set_buffer_size,       
            py::arg("buffer_size"),
            D(multi_source,set_buffer_size)
        )


        
        .def("set_timeout_ms",&multi_source::set_timeout_ms,       
            py::arg("timeout"),
            D(multi_source,set_timeout_ms)
        )

        ;




}








