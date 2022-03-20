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

#ifndef INCLUDED_IIO_HNCHBOARD2_SOURCE_IMPL_H
#define INCLUDED_IIO_HNCHBOARD2_SOURCE_IMPL_H

#include <string>
#include <vector>

#include <iio/hnchboard2_source.h>

#include "flexi_source_impl.h"

namespace gr {
  namespace iio {

    class hnchboard2_source_impl : public hnchboard2_source
			       , public flexi_source_impl
    {     
     public:
      hnchboard2_source_impl(struct iio_context *ctx, unsigned long samplerate, unsigned long lo_freq, double gain_value, unsigned long buffer_size);

      void set_params(unsigned long samplerate, unsigned long lo_freq, double gain_value);
    };

  } // namespace iio
} // namespace gr

#endif /* INCLUDED_IIO_HNCHBOARD2_SOURCE_IMPL_H */
