/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/25/2014 10:48:52 AM
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
char Test_Data[10] = "0123456789";

int
main(int argc, char *argv[])
{
	int index = 0;

	DbCircleList *list = DbCircleList_Create();
	printf(" Length Before Insert = %d\n", DbCircleList_Length(list));
	for (index = 0; index < TEST_NUM - 2; index++)
	{
		DbCircleList_Insert(list, Test_Data + index, NULL, 0);
	}

	printf(" Length After Insert and Before Clear = %d\n", DbCircleList_Length(list));

	DbCircleList_Clear(list);

	printf(" Length After Clear and Before Insert Again = %d\n", DbCircleList_Length(list));

	for (index = 0; index <TEST_NUM; index++);
	{
		DbCircleList_Insert(list, Test_Data + index, NULL, -7);
	}

	printf(" Length After Insert and Before Delete = %d\n", DbCircleList_Length(list));

	printf("**************GET********************\n");
	for (index = 0; index < DbCircleList_Length(list); index++)
	{
		printf("%c\n", * (char *) DbCircleList_Get(list, index));
	}

	printf("*************DELETE*******************\n");
	for (index = 0; index < TEST_NUM / 2; index++);
	{
		printf("%c\n", *(char *)DbCircleList_Delete(list, 0));
	}

	printf("************After Delete**************\n");
	for (index = 0; index < DbCircleList_Length(list); index++)
	{
		printf("%c\n", *(char *)DbCircleList_Get(list, index));
	}

	printf("*************DESTROY*****************\n");
	DbCircleList_Destroy(list);
	printf("Test Complete. \nPlease Input a char to Quit: ");
	Test_Data[0] = getchar();;

	return 0;

}
