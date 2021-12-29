/* mynewt_port.c
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * https://www.wolfssl.com
 */

#if defined(WOLFSSL_APACHE_MYNEWT)
#ifndef NO_FILESYSTEM
#include "fs/fs.h"
#define FILE struct fs_file

FILE* mynewt_fopen(const char * restrict path, const char * restrict mode)
{
    FILE *file;
    uint8_t access_flags = 0;
    const char *p = mode;
    while(*p != '\0') {
        switch(*p) {
            case 'r':
            {
                access_flags |= FS_ACCESS_READ;
                if(*(p+1) == '+') {
                    access_flags |= FS_ACCESS_WRITE;
                }
            }
            break;

            case 'w':
            {
                access_flags |= (FS_ACCESS_WRITE | FS_ACCESS_TRUNCATE);
                if(*(p+1) == '+') {
                    access_flags |= FS_ACCESS_READ;
                }
            }
            break;

            case 'a':
            {
                access_flags |= (FS_ACCESS_WRITE | FS_ACCESS_APPEND);
                if(*(p+1) == '+') {
                    access_flags |= FS_ACCESS_READ;
                }
            }
            break;
        }
        p++;
    }

    /* Open the file for reading. */
    int rc = fs_open(path, access_flags, &file);
    if (rc != 0) {
        return NULL;
    }
    return file;
}

int mynewt_fseek(FILE *stream, long offset, int whence)
{
    uint32_t fs_offset;

    switch(whence) {
        case 0: /* SEEK_SET */
        {
            fs_offset += offset;
        }
        break;

        case 1: /* SEEK_CUR */
        {
            fs_offset = fs_getpos(stream);
            fs_offset += offset;
        }
        break;

        case 2: /* SEEK_END */
        {
            fs_filelen(stream, &fs_offset);
            fs_offset += offset;
        }
        break;
    }

    fs_seek(stream, fs_offset);

    return 0;
}

long mynewt_ftell(FILE *stream)
{
    uint32_t fs_offset;
    fs_filelen(stream, &fs_offset);
    fs_seek(stream, fs_offset);
    return (long)fs_offset;
}

void mynewt_rewind(FILE *stream)
{
    fs_seek(stream, 0);
}

size_t mynewt_fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
    size_t to_read = size * nitems;
    uint32_t read_size;
    int rc = fs_read(stream, to_read, ptr, &read_size);
    if(rc != 0) {
        return 0;
    }

    return (size_t)read_size;
}

size_t mynewt_fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream)
{
    size_t to_write = size * nitems;
    int rc = fs_write(stream, ptr, to_write);
    if(rc != 0) {
        return 0;
    }

    return to_write;
}

int mynewt_fclose(FILE *stream)
{
    fs_close(stream);
    return 0;
}

#endif /* NO_FILESYSTEM*/
#endif /* if defined(WOLFSSL_APACHE_MYNEWT) */
