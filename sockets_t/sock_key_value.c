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
keyvalue_all(struct keyvalue_pair *kv_head)
{
	char *str = kv_head->key;
	struct keyvalue_pair *tmp = NULL;

	printf(">>>>>>>\n");
	for (tmp = kv_head->next; 
				strcmp(tmp->key, str) == 0; tmp = tmp->next)
	{
		printf("%s - %ld // %s %ld\n", tmp->key, tmp->value,
					tmp->next->key, tmp->next->value);
	}
}

void
keyvalue_add(struct keyvalue_pair *kv_head, struct keyvalue_pair *kv_new)
{
	kv_new->previous = kv_head->previous;
	kv_head->previous->next = kv_new;
	
	kv_head->previous = kv_new;
	kv_new->next = kv_head;
}


void
keyvalue_delete(struct keyvalue_pair *kv_head, char *key)
{
	struct keyvalue_pair *tmp = NULL;

	if (kv_head->key != NULL && key != NULL)
	{
		for (tmp = kv_head->next; strcmp(tmp->key, kv_head->key) == 0;
					tmp = tmp->previous)
		{
			printf("----%s - %s\n", tmp->key, kv_head->key);
			if (strcmp(tmp->previous->key, key) == 0)
			{
				tmp->previous->previous->next = tmp;
				tmp->previous = tmp->previous->previous;
				break;
			}

			if (strcmp(tmp->key, key) == 0) 
			{
				printf("////\n");
				tmp->next->previous = tmp->previous;
				tmp->previous->next = tmp->next;
				break;
			}
		}
	}  
}

void
keyvalue_modify(struct keyvalue_pair *kv_head, struct keyvalue_pair *kv_mod)
{
	struct keyvalue_pair *tmp = NULL;
	char *str = NULL;
	str = kv_head->key;

	if (str != NULL && kv_mod->key != NULL)
	{
		tmp = kv_head;
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
keyvalue_select(struct keyvalue_pair *kv_head, char *key)
{
	struct keyvalue_pair *tmp = NULL;
	char *str = NULL;
	str = kv_head->key;
	unsigned long i = 0;

	if (str != NULL && key != NULL)
	{
		tmp = kv_head;
		if (strcmp(tmp->key, key) == 0)
		  return tmp->value;

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
	struct keyvalue_pair *k0, *k1, *k2, *k3, *head;

	k0 = (struct keyvalue_pair *) malloc(sizeof(struct keyvalue_pair));
	k1 = (struct keyvalue_pair *) malloc(sizeof(struct keyvalue_pair));
	k2 = (struct keyvalue_pair *) malloc(sizeof(struct keyvalue_pair));
	k3 = (struct keyvalue_pair *) malloc(sizeof(struct keyvalue_pair));

	k0->key = "hello";
	k0->value = 1;
	k0->next = k1;
	k0->previous = k1;
	head = k0;

	k1->key = "world";
	k1->value = 2;
	k1->next = k0;
	k1->previous = k0;
	
	k2->key = "everyone";
	k2->value = 3;

	k3->key = "test";
	k3->value = 4;

	keyvalue_all(head);

	keyvalue_add(head, k2);
	keyvalue_add(head, k3);

	keyvalue_delete(head, argv[1]);
	printf("%ld \n", head->previous->value);

	char *str = "hello";
	str = argv[1];

	printf("%ld %s\n", keyvalue_select(head, str), str);
	free(k0);
	free(k1);
	free(k2);
}
