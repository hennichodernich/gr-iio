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


#ifndef INCLUDED_IIO_HNCHBOARD2U_SOURCE_H
#define INCLUDED_IIO_HNCHBOARD2U_SOURCE_H

#include <iio/api.h>
#include <gnuradio/hier_block2.h>
#include <gnuradio/sync_block.h>

#include "flexi_source.h"

namespace gr {
  namespace iio {

    /*!
     * \brief <+description of block+>
     * \ingroup iio
     *
     */
    class IIO_API hnchboard2u_source : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<hnchboard2u_source> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of iio::device.
       *
       * To avoid accidental use of raw pointers, iio::device's
       * constructor is in a private implementation
       * class. iio::device::make is the public interface for
       * creating new instances.
       */
      static sptr make(const std::string &uri, unsigned long samplerate, unsigned long lo_freq, double gain_value, unsigned long buffer_size);

      static sptr make_from(struct iio_context *ctx, unsigned long samplerate, unsigned long lo_freq, double gain_value, unsigned long buffer_size);

      virtual void set_params(unsigned long samplerate, unsigned long lo_freq, double gain_value) = 0;
    };

    class IIO_API hnchboard2u_source_f32c : virtual public gr::hier_block2
    {
    public:
      typedef boost::shared_ptr<hnchboard2u_source_f32c> sptr;

      static sptr make(const std::string &uri, unsigned long samplerate, unsigned long lo_freq, double gain_value, unsigned long buffer_size)
      {
	      hnchboard2u_source::sptr block = hnchboard2u_source::make(uri, samplerate, lo_freq, gain_value, buffer_size);

	      return gnuradio::get_initial_sptr(
			      new hnchboard2u_source_f32c(block));
      }

      void set_params(unsigned long samplerate, unsigned long lo_freq, double gain_value)
      {
              hnchboard2u_block->set_params(samplerate, lo_freq, gain_value);              
      }
    private:
      hnchboard2u_source::sptr hnchboard2u_block;

    protected:
      explicit hnchboard2u_source_f32c(hnchboard2u_source::sptr block);
    };

  } // namespace iio
} // namespace gr

#endif /* INCLUDED_IIO_HNCHBOARD2U_SOURCE_H */
