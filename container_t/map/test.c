/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/25/2014 03:08:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "map.h"

#ifdef DEBUG
#define dump(a,s) __dump((a),(s))
#else
#define dump(a,s)
#endif

typedef struct kv_info
{
	char key[20];
	unsigned long value;
}kv_info_t;

static void __dump(kv_info_t *array, size_t num)
{
	int i;
	printf("-- DUMP START -- \n");  
	for (i=0; i < num; i++)
	{
		printf("array[%d].key=%03ld, array[%d].val=%s\n",
									i, array[i].value, i, array[i].key);
	}
	printf("-- DUMP END -- \n");
}

#define map_info(pm) {\
	printf("-- dump map start ... --\n"); \
	map_dump(pm); \
    printf("-- dump map end ... --\n"); \
}

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

int main()
{
	int i, j, value;
	map_t map1;
	kv_info_t kvs[12];

	memset(kvs, 0, sizeof(kvs));
	for (i = 0; i < 10; i++)
	{
		value = rand()%12;
		kvs[i].value = value;
		sprintf(kvs[i].key, "i am %d", value);
	}
	dump(kvs, ARRAY_SIZE(kvs));

	map_init(&map1);

	i = 0;
	while (i < 12)
	{
		struct mnode* node;
		node = map_find(&map1, &(kvs[i].key), NULL);
		if (!node)
		{
			printf("insert node: kvs[%d].key = %s \tkvs[%d].value = %d\n", i, kvs[i].key, i, kvs[i].value);
			map_insert_alloc(&map1, &(kvs[i].value), &kvs[i], sizeof(kvs[i]), NULL);
		}
		else
		{
			for (j = 0; j < 12; j++)
			{
				if (kvs[j].value == kvs[i].value && i != j)
				  printf("\t|-- kvs[%d].value=%d\n", j, kvs[j].value);
			}
		}
		map_info(&map1);
		i++;
	}
	map_info(&map1);
}


