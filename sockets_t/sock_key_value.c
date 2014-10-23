/*
 * =====================================================================================
 *
 *       Filename:  sock_key_value.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/23/2014 03:13:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "sock_key_value.h"
#include <string.h>

void
keyvalue_add(struct keyvalue_pair *kv_curr, struct keyvalue_pair *kv_new)
{
	kv_new->previous = kv_curr;
	kv_curr->next = kv_new;
}

void
keyvalue_delete(struct keyvalue_pair *kv_curr, char *key)
{
	struct keyvalue_pair *tmp = NULL;
	char *str = NULL;
	str = kv_curr->key;

	if (str != NULL && key != NULL)
	{
		tmp = kv_curr;
		while (tmp = tmp->previous)
		{
			if (tmp->key != str)
			{
				if (strcmp(tmp->key, key)) {
					tmp->next->previous = tmp->previous;
					tmp->previous->next = tmp->next;
					break;
				}
			}
			else		/* Turn around */
			{
				printf("not found this k-v: %s\n", key);
				break;
			}
		}
	}
	  
}

void
keyvalue_modify(struct keyvalue_pair *kv_curr, struct keyvalue_pair *kv_mod)
{
	struct keyvalue_pair *tmp = NULL;
	char *str = NULL;
	str = kv_curr->key;

	if (str != NULL && kv_mod->key != NULL)
	{
		tmp = kv_curr;
		while (tmp = tmp->previous)
		{
			if (tmp->key != str)
			{
				if (strcmp(tmp->key, kv_mod->key)) {
					tmp->next->previous = kv_mod;
					tmp->previous->next = kv_mod;
					break;
				}
			}
			else		/* Turn around */
			{
				printf("not found this k-v: %s\n", kv_mod->key);
				break;
			}
		}
	}
}

unsigned long
keyvalue_select(struct keyvalue_pair *kv_curr, char *key)
{
	struct keyvalue_pair *tmp = NULL;
	char *str = NULL;
	str = kv_curr->key;
	unsigned long i = 0;

	if (str != NULL && key != NULL)
	{
		tmp = kv_curr;
		while (tmp = tmp->previous)
		{
			if (tmp->key != str)
			{
				if (strcmp(tmp->key, key) == 0)
				{
					i = tmp->value;
					break;
				}
				else		/* Turn around */
				{
					printf("not found this k-v: %s\n", key);
					break;
				}
			}
		}
	}

	return i;
}

int
main(int argc, char *argv[])
{
	struct keyvalue_pair *k0, *k1, *k2;
	k0 = (struct keyvalue_pair *) malloc(sizeof(struct keyvalue_pair));
	k1 = (struct keyvalue_pair *) malloc(sizeof(struct keyvalue_pair));
	k2 = (struct keyvalue_pair *) malloc(sizeof(struct keyvalue_pair));

	k0->key = "hello";
	k0->value = 1;
	k0->next = k1;
	k0->previous = k1;

	k1->key = "world";
	k1->value = 2;
	k1->next = k0;
	k1->previous = k0;
	
	k2->key = "everyone";
	k2->value = 3;

	keyvalue_add(k1, k2);

	char *str = "hello";
	str = argv[1];
	printf("%d %d\n", sizeof(str), sizeof(argv[1]));
	printf("%ld %s\n", keyvalue_select(k1, str), str);

	free(k0);
	free(k1);
	free(k2);
}
