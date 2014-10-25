/*
 * file: platform.h
 * author: vincent.cws2008@gmail.com
 * history:
 * initial @ 2012-01-31
 */

#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#ifndef NULL
#define NULL 0
#endif

#ifndef offsetof
#define offsetof(TYPE,MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

#ifdef WIN32

#	ifndef container_of
#	define container_of(ptr, type, member) ((type *)( (char *)ptr-offsetof(type,member)))
#	endif

#	define inline __inline

#	define __attribute__(x) __declspec(align(4));

#else /* platform: UNIX or Linux */

#	ifndef container_of
#	define container_of(ptr, type, member) ({ \
	const typeof( ((type *)0)->member ) *__mptr = (ptr); \
	(type *)( (char *)__mptr - offsetof(type,member) );})
#	endif

#	include <linux/kernel.h>
#	include <linux/stddef.h>

#endif



#endif
