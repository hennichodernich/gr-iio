# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND iio_python_files
    attr_sink_python.cc
    attr_source_python.cc
    attr_updater_python.cc
    device_sink_python.cc
    device_source_python.cc
    eightbit_sink_python.cc
    eightbit_source_python.cc
    thirtytwobit_sink_python.cc
    thirtytwobit_source_python.cc
    flexi_source_python.cc
    fmcomms2_sink_python.cc
    fmcomms2_source_python.cc
    fmcomms5_sink_python.cc
    fmcomms5_source_python.cc
    hnchbbboard_source_python.cc
    hnchboard2_source_python.cc
    hnchboard2u_source_python.cc
    multi_source_python.cc
    pluto_sink_python.cc
    pluto_source_python.cc
    python_bindings.cc)

GR_PYBIND_MAKE_OOT(iio
   ../..
   gr::iio
   "${iio_python_files}")

install(TARGETS iio_python DESTINATION ${GR_PYTHON_DIR}/iio COMPONENT pythonapi)
