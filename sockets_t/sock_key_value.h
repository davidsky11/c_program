/*
 * =====================================================================================
 *
 *       Filename:  sock_key_value.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/23/2014 02:43:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef SOCK_KEY_VALUE_H
#define SOCK_KEY_VALUE_H

#include <netinet/in.h>
#include <sys/socket.h>
#include <signal.h>
#include "../lib/tlpi_hdr.h"

#define PORT_NUM	"51738"		
					/* Port number for server */

#define NOT_FOUND	-1

struct keyvalue_pair
{
	char *key;
	unsigned long value;
	struct keyvalue_pair *previous;
	struct keyvalue_pair *next;
};

void 
keyvalue_add(struct keyvalue_pair *kv_head, struct keyvalue_pair *kv_new);

void 
keyvalue_delete(struct keyvalue_pair *kv_head, char *key);

void 
keyvalue_modify(struct keyvalue_pair *kv_head, struct keyvalue_pair *kv_mod);

unsigned long 
keyvalue_select(struct keyvalue_pair *kv_head, char *key);

#endif
