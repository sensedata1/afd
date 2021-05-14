/********************************************************
 Bitstream Library, a module for reading bits of data

 Copyright (C) 2007-2015  Brian Langenberger

 The Bitstream Library is free software; you can redistribute it and/or modify
 it under the terms of either:

   * the GNU Lesser General Public License as published by the Free
     Software Foundation; either version 3 of the License, or (at your
     option) any later version.

 or

   * the GNU General Public License as published by the Free Software
     Foundation; either version 2 of the License, or (at your option) any
     later version.

 or both in parallel, as here.

 The Bitstream Library is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 for more details.

 You should have received copies of the GNU General Public License and the
 GNU Lesser General Public License along with the GNU MP Library.  If not,
 see https://www.gnu.org/licenses/.
 *******************************************************/

#ifndef __BITSTREAMLIB_FUNCIO_H__
#define __BITSTREAMLIB_FUNCIO_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/*casts for inserting functions with non-void pointers into ext_open_r*/

/*returns number of bytes actually read*/
typedef unsigned (*ext_read_f)(void* user_data,
                               uint8_t* buffer,
                               unsigned buffer_size);

/*casts for inserting functions with non-void pointers into ext_open_w*/

/*returns 0 on successful write, 1 if a write error occurs*/
typedef int (*ext_write_f)(void* user_data,
                           const uint8_t* buffer,
                           unsigned buffer_size);

/*returns 0 on a successful flush, EOF if a write error occurs*/
typedef int (*ext_flush_f)(void* user_data);

/*casts used by both ext_open_r and ext_open_w*/

/*returns 0 on a successful seek, EOF if a seek error occurs*/
typedef int (*ext_setpos_f)(void* user_data, void* pos);

/*returns non-NULL on a successful tell, NULL if a tell error occurs*/
typedef void* (*ext_getpos_f)(void* user_data);

/*frees position object pos as returned by ext_tell_f*/
typedef void (*ext_free_pos_f)(void *pos);

/*returns 0 on successful seek, nonzero if an error occurs*/
typedef int (*ext_seek_f)(void* user_data, long position, int whence);

/*returns 0 on a successful close, EOF if a close error occurs*/
typedef int (*ext_close_f)(void* user_data);

/*free user data as used by read_f or write_f*/
typedef void (*ext_free_f)(void* user_data);

struct br_external_input {
    void* user_data;
    ext_read_f read;
    ext_setpos_f setpos;
    ext_getpos_f getpos;
    ext_free_pos_f free_pos;
    ext_seek_f seek;
    ext_close_f close;
    ext_free_f free;

    struct {
        uint8_t *data;
        unsigned pos;
        unsigned size;
        unsigned maximum_size;
    } buffer;
};

struct bw_external_output {
    void* user_data;
    ext_write_f write;
    ext_setpos_f setpos;
    ext_getpos_f getpos;
    ext_free_pos_f free_pos;
    ext_seek_f seek;
    ext_flush_f flush;
    ext_close_f close;
    ext_free_f free;

    struct {
        uint8_t *data;
        unsigned pos;
        unsigned maximum_size;
    } buffer;
};

/*** stdio-like functions for br_external_input ***/

/*analagous to fopen for reading*/
struct br_external_input*
ext_open_r(void* user_data,
           unsigned buffer_size,
           ext_read_f read,
           ext_setpos_f setpos,
           ext_getpos_f getpos,
           ext_free_pos_f free_pos,
           ext_seek_f seek,
           ext_close_f close,
           ext_free_f free);

/*analagous to fgetc

  returns EOF and end of stream or if a read error occurs*/
int
ext_getc(struct br_external_input* stream);

/*analagous to fread

  reads "data_size" bytes from "stream" to "data"
  and returns the amount of bytes actually read
  (which may be less than the amount requested)*/
unsigned
ext_fread(struct br_external_input* stream,
          uint8_t* data,
          unsigned data_size);

/*analagous to fseek

  moves current stream position to position
  relative to stream position "whence"

  returns 0 on success, nonzero on failure*/
int
ext_fseek_r(struct br_external_input *stream, long position, int whence);


/*analagous to fclose

  this calls the passed-in close() function
  but doesn't deallocate "stream" itself*/
void
ext_close_r(struct br_external_input* stream);

/*this calls the passed-in free() function
  before deallocating "stream" itself*/
void
ext_free_r(struct br_external_input* stream);

/*** stdio-like functions for bw_external_input ***/

/*analagous to fopen for writing*/
struct bw_external_output*
ext_open_w(void* user_data,
           unsigned buffer_size,
           ext_write_f write,
           ext_setpos_f setpos,
           ext_getpos_f getpos,
           ext_free_pos_f free_pos,
           ext_seek_f seek,
           ext_flush_f flush,
           ext_close_f close,
           ext_free_f free);

/*analagous to fputc

  returns character written on success, EOF if a write error occurs*/
int
ext_putc(int i, struct bw_external_output* stream);

/*analagous to fwrite

  returns 0 on success, EOF if a write error occurs*/
int
ext_fwrite(struct bw_external_output* stream,
           const uint8_t *data,
           unsigned data_size);

/*analagous to fsetpos

  moves current stream position to pos
  which has been returned by ext_tell_w

  returns 0 on success, EOF on failure*/
int
ext_setpos_w(struct bw_external_output *stream, void *pos);

/*analagous to fgetpos

  returns current position as pos
  which may be fed to ext_seek_w

  returns NULL if an error occurs*/
void*
ext_getpos_w(struct bw_external_output *stream);


/*analagous to fseek

  moves current stream position to position
  relative to stream position "whence"

  returns 0 on success, nonzero on failure*/
int
ext_fseek_w(struct bw_external_output *stream, long position, int whence);


/*analagous to fflush,
  this sends all buffered bytes to write function
  and calls passed-in flush() function

  returns 0 on success, EOF on error*/
int
ext_flush_w(struct bw_external_output* stream);

/*analagous to fclose

  this flushes output and calls passed-in close() function
  but doesn't deallocate "stream" itself

  returns 0 on success, EOF on error*/
int
ext_close_w(struct bw_external_output* stream);

/*this calls the passed-in free() function
  before deallocating "stream"*/
void
ext_free_w(struct bw_external_output* stream);


#endif
