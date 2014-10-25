/*
 * =====================================================================================
 *
 *       Filename:  kv_test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/25/2014 11:20:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "DbCircleList.h"

#define TEST_NUM 10
char Test_Data[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char *test = "0123456789";
DbCircleListNodeData *data0 = {"hello", (unsigned long) 121314};
DbCircleListNodeData *data1 = {"kvknk", (unsigned long) 248614};
DbCircleListNodeData *data2 = {"mine", (unsigned long) 35684};
DbCircleListNodeData *data3 = {"sknkdo", (unsigned long) 43512};

int
main(int argc, char *argv[])
{
	int index = 0;

	DbCircleList *list= DbCircleList_Create();
	printf(" Length Before Insert = %d\n", DbCircleList_Length(list));

	DbCircleList_Insert(list, Test_Data + 0, data0, 0);
	DbCircleList_Insert(list, Test_Data + 1, data1, 0);
	DbCircleList_Insert(list, Test_Data + 2, data2, 0);
	DbCircleList_Insert(list, Test_Data + 3, data3, 0);
	//DbCircleList_Clear(list); 
	
	DbCircleListNode *node = (DbCircleListNode *)DbCircleList_Get(list, 0);
	DbCircleListNodeData *data = (DbCircleListNodeData *)node->data;
	printf("%s %ld\n", data->key, data->value);
}
