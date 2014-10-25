/*
 * file: main.c
 * author: vincent.cws2008@gmail.com
 * history:
 * initial @ 2012-01-31
 */

#define DEBUG

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"

#ifdef DEBUG
#define dump(a,s) __dump((a),(s))
#else
#define dump(a,s)
#endif


typedef struct word_info {
	unsigned long hash_major;
	unsigned long hash_minor;
	char *path;
	unsigned long line;
	unsigned long col;
}word_info_t;

typedef struct priv_info {
	unsigned long key;
	char val[10];
}priv_info_t;


static void __dump(priv_info_t *array, size_t num)
{
	int i;
	printf("-- DUMP START -- \n");  
	for (i=0; i < num; i++)
	{
		printf("array[%d].key=%03d, array[%d].val=%s\n",
			i, array[i].key, i, array[i].val);
	}
	printf("-- DUMP END -- \n");
}

#define map_info(pm) {\
	printf("-- dump map start ... --\n"); \
	map_dump(pm); \
    printf("-- dump map end ... --\n"); \
}

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

#define MAX_NUM 20

int main()
{
	map_t map1;
	int key;
	int i, j;
	priv_info_t priv_info[MAX_NUM];
	
	srand(time(0));
	
	memset(priv_info, 0, sizeof(priv_info));
	for (i=0; i<MAX_NUM; i++)
	{
		key = rand()%MAX_NUM;
		priv_info[i].key = key;
		sprintf(priv_info[i].val, "i am %d", key);
	}
	dump(priv_info, ARRAY_SIZE(priv_info));
	
	map_init(&map1);
	
	i = 0;
	while (i < MAX_NUM)
	{
		struct mnode* node;
		printf("-- %d -- \n", i);
		node = map_find(&map1, &(priv_info[i].key), NULL);
		if (!node) {
			printf("->>> insert node: priv_info[%d].key=%d \n", i, priv_info[i].key);
			map_insert_alloc(&map1, &(priv_info[i].key), 
				&priv_info[i], sizeof(priv_info[i]), NULL);
		} else {
			/* key not matched, so just print out message! */
			printf("priv_info[%d].key=%d is exist!\n", i, priv_info[i].key);
			for (j=0; j < MAX_NUM; j++) {
				if(priv_info[j].key == priv_info[i].key && i!=j)
					printf("\t|-- priv_info[%d].key=%d\n", j, priv_info[j].key);
			}
		}
		map_info(&map1);
		
		i++;
	}
	map_info(&map1);
	
	printf("-----------------------------------\n");
	for (i=0; i < MAX_NUM; i++)
	{
		struct mnode* node;
		node = map_find(&map1,&i, NULL);
		if (node){
			map_remove_free(&map1, &i, NULL);      
			printf("--> key=%03d deleted!\n", i);
			map_info(&map1);
		}else{
			printf("key=%03d not found!\n", i);
		}
	}
	map_info(&map1);
	
	map_exit(&map1);
	return 0;
}
