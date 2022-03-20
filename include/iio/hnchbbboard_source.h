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


#ifndef INCLUDED_IIO_HNCHBBBOARD_SOURCE_H
#define INCLUDED_IIO_HNCHBBBOARD_SOURCE_H

#include <iio/api.h>
#include <gnuradio/hier_block2.h>
#include <gnuradio/sync_block.h>

#include "device_source.h"

namespace gr {
  namespace iio {

    /*!
     * \brief <+description of block+>
     * \ingroup iio
     *
     */
    class IIO_API hnchbbboard_source : virtual public gr::sync_block
    {
     public:
      typedef std::shared_ptr<hnchbbboard_source> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of iio::device.
       *
       * To avoid accidental use of raw pointers, iio::device's
       * constructor is in a private implementation
       * class. iio::device::make is the public interface for
       * creating new instances.
       */
      static sptr make(const std::string &uri, unsigned long long frequency,
		    unsigned long samplerate, int stream_id,
		    unsigned long buffer_size, double gain_value);

      static sptr make_from(struct iio_context *ctx,
		    unsigned long long frequency, unsigned long samplerate,		    
		    int stream_id, unsigned long buffer_size, double gain_value);

      virtual void set_params(unsigned long long frequency,
		      unsigned long samplerate, double gain_value) = 0;
    };

    class IIO_API hnchbbboard_source_f32c : virtual public gr::hier_block2
    {
    public:
      typedef std::shared_ptr<hnchbbboard_source_f32c> sptr;

      static sptr make(const std::string &uri,
		    unsigned long long frequency, unsigned long samplerate,
		    int stream_id, unsigned long buffer_size, double gain_value)
      {
	      hnchbbboard_source::sptr block = hnchbbboard_source::make(uri,
			      frequency, samplerate,
			      stream_id, buffer_size, gain_value);

	      return gnuradio::get_initial_sptr(
			      new hnchbbboard_source_f32c(stream_id, block));
      }

      void set_params(unsigned long long frequency,
		      unsigned long samplerate, double gain_value)
      {
              hnchbbboard_block->set_params(frequency, samplerate, gain_value);
      }
    private:
      hnchbbboard_source::sptr hnchbbboard_block;

    protected:
      explicit hnchbbboard_source_f32c(int stream_id,
		      hnchbbboard_source::sptr block);
    };

  } // namespace iio
} // namespace gr

#endif /* INCLUDED_IIO_HNCHBBBOARD_SOURCE_H */

