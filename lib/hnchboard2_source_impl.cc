/* -*- c++ -*- */
/* 
 * Copyright 2014 Analog Devices Inc.
 * Author: Paul Cercueil <paul.cercueil@analog.com>
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <cstdio>

#include <gnuradio/io_signature.h>
#include "hnchboard2_source_impl.h"

#include <gnuradio/blocks/short_to_float.h>
#include <gnuradio/blocks/float_to_complex.h>

using namespace gr::blocks;

namespace gr {
  namespace iio {

    hnchboard2_source_f32c::hnchboard2_source_f32c(hnchboard2_source::sptr src_block) :
            hier_block2("hnchboard2_f32c",
                io_signature::make(0, 0, 0),
                io_signature::make(1, 1, sizeof(gr_complex))),
            hnchboard2_block(src_block)
    {
      basic_block_sptr hier = shared_from_this();      

      short_to_float::sptr s2f1 = short_to_float::make(1, 2048.0);
      short_to_float::sptr s2f2 = short_to_float::make(1, 2048.0);
      float_to_complex::sptr f2c = float_to_complex::make(1);
      
      connect(src_block, 0, s2f1, 0);
      connect(src_block, 1, s2f2, 0);
      connect(s2f1, 0, f2c, 0);
      connect(s2f2, 0, f2c, 1);
      connect(f2c, 0, hier, 0);

    }

    hnchboard2_source::sptr
    hnchboard2_source::make(const std::string &uri, unsigned long samplerate, unsigned long lo_freq, double gain_value, unsigned long buffer_size)
    {
      return gnuradio::get_initial_sptr
        (new hnchboard2_source_impl(flexi_source_impl::get_context(uri), samplerate, lo_freq, gain_value, buffer_size));
    }

    hnchboard2_source::sptr
    hnchboard2_source::make_from(struct iio_context *ctx,unsigned long samplerate, unsigned long lo_freq, double gain_value, unsigned long buffer_size)
    {
      return gnuradio::get_initial_sptr
        (new hnchboard2_source_impl(ctx, samplerate, lo_freq, gain_value, buffer_size));
    }


    hnchboard2_source_impl::hnchboard2_source_impl(struct iio_context *ctx, unsigned long samplerate, unsigned long lo_freq, double gain_value, unsigned long buffer_size)
      : gr::sync_block("hnchboard2_source",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1, -1, sizeof(short))), 
              flexi_source_impl(ctx, true, "hnch_ctrl",
                                      {"voltage0", "voltage1"},
                                      "adrf6806", {"in_voltage_sampling_frequency=5000000","in_voltage_hardwaregain=4.5"}, {"out_altvoltage0_RX_LO_frequency=100000000"}, buffer_size, 0)
    {
	    set_params(samplerate, lo_freq, gain_value);
    }

    void hnchboard2_source_impl::set_params(unsigned long samplerate, unsigned long lo_freq, double gain_value)
    {	    
	std::vector<std::string> devparams;
    std::vector<std::string> phyparams;

	devparams.push_back("in_voltage_sampling_frequency=" + boost::to_string(samplerate));
    devparams.push_back("in_voltage_hardwaregain=" + boost::to_string(gain_value));	    
	flexi_source_impl::set_devparams(devparams);
    phyparams.push_back("out_altvoltage0_RX_LO_frequency=" + boost::to_string(lo_freq));	    
	flexi_source_impl::set_phyparams(phyparams);
    }

  } /* namespace iio */
} /* namespace gr */
