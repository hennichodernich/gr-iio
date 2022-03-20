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

#ifndef INCLUDED_IIO_HNCHBBBOARD_SOURCE_IMPL_H
#define INCLUDED_IIO_HNCHBBBOARD_SOURCE_IMPL_H

#include <string>
#include <vector>

#include <iio/hnchbbboard_source.h>

#include "device_source_impl.h"

namespace gr {
  namespace iio {

    class hnchbbboard_source_impl : public hnchbbboard_source
			       , public device_source_impl
    {
     private:
      std::vector<std::string> get_channels_vector(
		      int stream_id);

     public:
      hnchbbboard_source_impl(struct iio_context *ctx, bool destroy_ctx,
		    unsigned long long frequency, unsigned long samplerate,
		    int stream_id, unsigned long buffer_size, double gain_value);

      void set_params(unsigned long long frequency,
		      unsigned long samplerate, double gain_value);
    };

  } // namespace iio
} // namespace gr

#endif /* INCLUDED_IIO_HNCHBBBOARD_SOURCE_IMPL_H */
