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
#include "hnchbbboard_source_impl.h"

#include <gnuradio/blocks/short_to_float.h>
#include <gnuradio/blocks/float_to_complex.h>

using namespace gr::blocks;

namespace gr {
  namespace iio {

    hnchbbboard_source_f32c::hnchbbboard_source_f32c(int stream_id,
                    hnchbbboard_source::sptr src_block) :
            hier_block2("hnchbbboard_f32c",
                io_signature::make(0, 0, 0),
                io_signature::make(
			(stream_id==3) ? 2 : 1,
			(stream_id==3) ? 2 : 1,
			sizeof(gr_complex))),
            hnchbbboard_block(src_block)
    {
      basic_block_sptr hier = shared_from_this();
      unsigned int num_streams = (stream_id==3) ? 2 : 1;

      
      for (unsigned int i = 0; i < num_streams; i++) {
        short_to_float::sptr s2f1 = short_to_float::make(1, 2048.0);
        short_to_float::sptr s2f2 = short_to_float::make(1, 2048.0);
        float_to_complex::sptr f2c = float_to_complex::make(1);

        connect(src_block, i * 2, s2f1, 0);
        connect(src_block, i * 2 + 1, s2f2, 0);
        connect(s2f1, 0, f2c, 0);
        connect(s2f2, 0, f2c, 1);
        connect(f2c, 0, hier, i);
        }            
    }

    hnchbbboard_source::sptr
    hnchbbboard_source::make(const std::string &uri, unsigned long long frequency,
		    unsigned long samplerate,
		    int stream_id,
		    unsigned long buffer_size, double gain_value)
    {
      return gnuradio::get_initial_sptr
        (new hnchbbboard_source_impl(device_source_impl::get_context(uri), true,
				  frequency, samplerate,
				  stream_id, buffer_size, gain_value));
    }

    hnchbbboard_source::sptr
    hnchbbboard_source::make_from(struct iio_context *ctx,
		    unsigned long long frequency, unsigned long samplerate,		    
		    int stream_id, unsigned long buffer_size, double gain_value)
    {
      return gnuradio::get_initial_sptr
        (new hnchbbboard_source_impl(ctx, false, frequency, samplerate,
				  stream_id, buffer_size,
				  gain_value));
    }

    std::vector<std::string> hnchbbboard_source_impl::get_channels_vector(
		    int stream_id)
    {
	    std::vector<std::string> channels;
        if ((stream_id==0) || (stream_id==2) || (stream_id==3))
		    channels.push_back("voltage0");
        if ((stream_id==0) || (stream_id==3))	    
		    channels.push_back("voltage1");
	    if ((stream_id==1) || (stream_id==2) || (stream_id==3))	    
		    channels.push_back("voltage2");
	    if ((stream_id==1) || (stream_id==3))	    
		    channels.push_back("voltage3");
	    return channels;
    }

    hnchbbboard_source_impl::hnchbbboard_source_impl(struct iio_context *ctx,
		    bool destroy_ctx, unsigned long long frequency, 
            unsigned long samplerate, int stream_id,
		    unsigned long buffer_size, double gain_value)
      : gr::sync_block("hnchbbboard_source",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1, -1, sizeof(short)))
      , device_source_impl(ctx, destroy_ctx, "hnch_ctrl",
		      get_channels_vector(stream_id),
		      "hnch_ctrl", std::vector<std::string>(),
		      buffer_size, 0)
    {
	    set_params(frequency, samplerate, gain_value);
    }

    void hnchbbboard_source_impl::set_params(unsigned long long frequency,
		    unsigned long samplerate, double gain_value)
    {	    
	    std::vector<std::string> params;
        
	    params.push_back("in_voltage_frequency=" +
			    boost::to_string(frequency));
	    params.push_back("in_voltage_sampling_frequency=" +
                boost::to_string(samplerate));
	    params.push_back("in_voltage_hardwaregain=" +
			    boost::to_string(gain_value));
	    
	    device_source_impl::set_params(params);
    }

  } /* namespace iio */
} /* namespace gr */
