/* ioapi_mem.h -- IO base function header for compress/uncompress .zip
   files using zlib + zip or unzip API

   This version of ioapi is designed to access memory rather than files.
   We do use a region of memory to put data in to and take it out of.

   Copyright (C) 2012-2017 Nathan Moinvaziri
      https://github.com/nmoinvaz/minizip

   This program is distributed under the terms of the same license as zlib.
   See the accompanying LICENSE file for the full text of the license.
*/

#ifndef _MZ_STREAM_ZLIB_H
#define _MZ_STREAM_ZLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "zlib.h"
#include "ioapi.h"

#ifdef __cplusplus
extern "C" {
#endif

int32_t ZCALLBACK mz_stream_zlib_open(voidpf stream, const char* filename, int mode);
int32_t ZCALLBACK mz_stream_zlib_read(voidpf stream, void* buf, uint32_t size);
int32_t ZCALLBACK mz_stream_zlib_write(voidpf stream, const void* buf, uint32_t size);
int64_t ZCALLBACK mz_stream_zlib_tell(voidpf stream);
int32_t ZCALLBACK mz_stream_zlib_seek(voidpf stream, uint64_t offset, int origin);
int32_t ZCALLBACK mz_stream_zlib_close(voidpf stream);
int32_t ZCALLBACK mz_stream_zlib_error(voidpf stream);

void              mz_stream_zlib_set_level(voidpf stream, int16_t level);
void              mz_stream_zlib_set_window_bits(voidpf stream, int16_t window_bits);
void              mz_stream_zlib_set_mem_level(voidpf stream, int16_t mem_level);
void              mz_stream_zlib_set_strategy(voidpf stream, int16_t strategy);
uint64_t          mz_stream_zlib_get_total_in(voidpf stream);
uint64_t          mz_stream_zlib_get_total_out(voidpf stream);

voidpf            mz_stream_zlib_create(voidpf *stream);
void              mz_stream_zlib_delete(voidpf *stream);

int32_t ZCALLBACK mz_stream_crc32_open(voidpf stream, const char* filename, int mode);
int32_t ZCALLBACK mz_stream_crc32_read(voidpf stream, void* buf, uint32_t size);
int32_t ZCALLBACK mz_stream_crc32_write(voidpf stream, const void* buf, uint32_t size);
int64_t ZCALLBACK mz_stream_crc32_tell(voidpf stream);
int32_t ZCALLBACK mz_stream_crc32_seek(voidpf stream, uint64_t offset, int origin);
int32_t ZCALLBACK mz_stream_crc32_close(voidpf stream);
int32_t ZCALLBACK mz_stream_crc32_error(voidpf stream);

uint32_t          mz_stream_crc32_get_value(voidpf stream);

voidpf            mz_stream_crc32_create(voidpf *stream);
void              mz_stream_crc32_delete(voidpf *stream);

#ifdef __cplusplus
}
#endif

#endif
