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

#define KV_MAX		256		
					/* Size of array to hold the key-value pair  */

#define PORT_NUM	"51738"		
					/* Port number for server */

#define KEY_MAX_LEN	21			
					/* Size of key */

#define NOT_FOUND	-1

#define lengthOf(x)	(sizeof(x)/sizeof(struct keyvalue_pair))

struct keyvalue_pair
{
	char *key;
	unsigned long value;
	struct keyvalue_pair *previous;
	struct keyvalue_pair *next;
};

//struct keyvalue_pair kvs[KV_MAX];		
					/* Container(array) to hold keyvalue_pair */

void keyvalue_add(struct keyvalue_pair *kv_curr, struct keyvalue_pair *kv_new);
void keyvalue_delete(struct keyvalue_pair *kv_curr, char *key);
void keyvalue_modify(struct keyvalue_pair *kv_curr, struct keyvalue_pair *kv_mod);
unsigned long keyvalue_select(struct keyvalue_pair *kv_curr, char *key);

#endif
