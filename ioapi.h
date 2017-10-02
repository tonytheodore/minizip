/* ioapi.h -- IO base function header for compress/uncompress .zip
   part of the MiniZip project

   Copyright (C) 2012-2017 Nathan Moinvaziri
     https://github.com/nmoinvaz/minizip
   Copyright (C) 2009-2010 Mathias Svensson
     Modifications for Zip64 support
     http://result42.com
   Copyright (C) 1998-2010 Gilles Vollant
     http://www.winimage.com/zLibDll/minizip.html

   This program is distributed under the terms of the same license as zlib.
   See the accompanying LICENSE file for the full text of the license.
*/

#ifndef _MZ_STREAM_H
#define _MZ_STREAM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "zlib.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ZCALLBACK
#  if (defined(WIN32) || defined(_WIN32) || defined (WINDOWS) || \
       defined (_WINDOWS)) && defined(CALLBACK) && defined (USEWINDOWS_CALLBACK)
#    define ZCALLBACK CALLBACK
#  else
#    define ZCALLBACK
#  endif
#endif
    
#define MZ_STREAM_SEEK_CUR             (1)
#define MZ_STREAM_SEEK_END             (2)
#define MZ_STREAM_SEEK_SET             (0)

#define MZ_STREAM_MODE_READ            (1)
#define MZ_STREAM_MODE_WRITE           (2)
#define MZ_STREAM_MODE_READWRITEFILTER (3)
#define MZ_STREAM_MODE_EXISTING        (4)
#define MZ_STREAM_MODE_CREATE          (8)

#define MZ_STREAM_ERR                  (-1)
#define MZ_STREAM_OK                   (0)

typedef int32_t (ZCALLBACK *mz_stream_open_cb)     (voidpf stream, const char *filename, int mode);
typedef int32_t (ZCALLBACK *mz_stream_is_open_cb)  (voidpf stream);
typedef int32_t (ZCALLBACK *mz_stream_read_cb)     (voidpf stream, void* buf, uint32_t size);
typedef int32_t (ZCALLBACK *mz_stream_write_cb)    (voidpf stream, const void *buf, uint32_t size);
typedef int64_t (ZCALLBACK *mz_stream_tell_cb)     (voidpf stream);
typedef int32_t (ZCALLBACK *mz_stream_seek_cb)     (voidpf stream, uint64_t offset, int origin);
typedef int32_t (ZCALLBACK *mz_stream_close_cb)    (voidpf stream);
typedef int32_t (ZCALLBACK *mz_stream_error_cb)    (voidpf stream);
typedef voidpf  (ZCALLBACK *mz_stream_create_cb)   (voidpf *stream);
typedef void    (ZCALLBACK *mz_stream_delete_cb)   (voidpf *stream);

typedef struct mz_stream_s
{
    mz_stream_open_cb      open;
    mz_stream_is_open_cb   is_open;
    mz_stream_read_cb      read;
    mz_stream_write_cb     write;
    mz_stream_tell_cb      tell;
    mz_stream_seek_cb      seek;
    mz_stream_close_cb     close;
    mz_stream_error_cb     error;
    mz_stream_create_cb    create;
    mz_stream_delete_cb    delete;
    struct mz_stream_s     *base;
} mz_stream;

int32_t mz_stream_open(voidpf stream, const char *filename, int mode);
int32_t mz_stream_is_open(voidpf stream);
int32_t mz_stream_read(voidpf stream, void* buf, uint32_t size);
int32_t mz_stream_write(voidpf stream, const void *buf, uint32_t size);
int64_t mz_stream_tell(voidpf stream);
int32_t mz_stream_seek(voidpf stream, uint64_t offset, int origin);
int32_t mz_stream_close(voidpf stream);
int32_t mz_stream_error(voidpf stream);

int32_t mz_stream_set_base(voidpf stream, voidpf base);

#ifndef _WIN32
#include "ioapi_posix.h"

#define mz_stream_os_open    mz_stream_posix_open
#define mz_stream_os_is_open mz_stream_posix_is_open
#define mz_stream_os_read    mz_stream_posix_read
#define mz_stream_os_write   mz_stream_posix_write
#define mz_stream_os_tell    mz_stream_posix_tell
#define mz_stream_os_seek    mz_stream_posix_seek
#define mz_stream_os_close   mz_stream_posix_close
#define mz_stream_os_error   mz_stream_posix_error

#define mz_stream_os_create  mz_stream_posix_create
#define mz_stream_os_delete  mz_stream_posix_delete

#define mz_os_rand           mz_posix_rand
#else
#include "iowin32.h"

#define mz_stream_os_open    mz_stream_win32_open
#define mz_stream_os_is_open mz_stream_win32_is_open
#define mz_stream_os_read    mz_stream_win32_read
#define mz_stream_os_write   mz_stream_win32_write
#define mz_stream_os_tell    mz_stream_win32_tell
#define mz_stream_os_seek    mz_stream_win32_seek
#define mz_stream_os_close   mz_stream_win32_close
#define mz_stream_os_error   mz_stream_win32_error

#define mz_stream_os_create  mz_stream_win32_create
#define mz_stream_os_delete  mz_stream_win32_delete

#define mz_os_rand           mz_win32_rand
#endif

#ifdef __cplusplus
}
#endif

#endif
