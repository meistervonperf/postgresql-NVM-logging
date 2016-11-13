/*-------------------------------------------------------------------------
 *
 * pram.h
 *	  pram support functions for PostgreSQL
 *
 * Copyright (C) 2016, Takashi Horikawa (meistervonperf@gmail.com)
 *
 * IDENTIFICATION
 *    src/include/pram.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef PRAM_H
#define PRAM_H

#include <sys/mman.h>
#include "access/xlog.h"

static inline int
pram_open(char *fileName)
{
	return BasicOpenFile(fileName, O_RDWR | PG_BINARY,
						 S_IRUSR | S_IWUSR);
}

static inline void *
pram_mmap(Size size, int fd)
{
	return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
}

#endif   /* PRAM_H */
