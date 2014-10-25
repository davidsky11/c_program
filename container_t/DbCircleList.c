/*
 * =====================================================================================
 *
 *       Filename:  DbCircleList.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/25/2014 08:55:10 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

// 库文件包含
#include <stdio.h>
#include <stdlib.h>

// 本地文件包含
#include "DbCircleList.h"

// 调试开关
#define DEBUG

// 结构体定义
// 封装键-值对结构
typedef struct _tag_TDbCircleListNodeData TDbCircleListNodeData;
struct _tag_TDbCircleListNodeData
{
	char *key;
	unsigned long value;
};

// 封装数据结点定义
typedef struct _tag_TDbCircleListNode TDbCircleListNode;
struct _tag_TDbCircleListNode
{
	TDbCircleListNodeData *data;
	unsigned int addr;		// 数据结点地址保存区
	TDbCircleListNode *prior;	// 链表指针
	TDbCircleListNode *next;	// 链表指针
};

// 封装链表头结点
typedef struct _tag_TDbCircleList
{
	int length;					// 链表长度
	TDbCircleListNode *header;	// 链表头指针
}TDbCircleList;

/* *
 *	函数原型：DbCircleList *DbCircleList_Create()
 *	函数说明：创建循环链表
 *	参数说明：输入参数：无
 *			  输出参数：无
 *	返回值：  DbCircleList * 循环链表指针
 * */
DbCircleList *DbCircleList_Create()
{
	// 申请头结点空间
	TDbCircleList *ret = (TDbCircleList *)malloc(sizeof(TDbCircleList));
#ifdef DEBUG
	printf("DbCircleList_Create...");
#endif
	if (ret != NULL)
	{
		ret->length = 0;		// 循环链表长度初始化
		ret->header = NULL;		// 循环链表头结点指针初始化
	}
#ifdef DEBUG
	(ret == NULL) ? printf(" Failed.\n") : printf(" Successful.\n");
#endif
	return (TDbCircleList *) ret;	// 返回循环链表指针
}


/* *
 *	函数原型：void DbCircleList_Destroy(DbCircleList *list)
 *	函数说明：删除循环链表
 *	参数说明：输入参数：DbCircleList *list    循环链表指针
 *	          输出参数：无
 *	返回值：  无
 * */
void DbCircleList_Destroy(DbCircleList *list)
{
#ifdef DEBUG
	printf("DbCircleList_Destroy...\n");
#endif
	DbCircleList_Clear(list);		// 清空循环链表
	free((TDbCircleList *) list);	// 释放头结点空间
	list = NULL;
#ifdef DEBUG
	printf("DbCircleList_Destroy... Complete.\n");
#endif
}


/* *
 *	函数原型：void DbCircleList_Clear(DbCircleList *list)
 *	函数说明：循环链表清空
 *	参数说明：输入参数：DbCircleList *list 循环链表指针
 *			  输出参数：无
 *	返回值：  无
 * */
void DbCircleList_Clear(DbCircleList *list)
{
	TDbCircleList *sList = (TDbCircleList *) list;
#ifdef DEBUG
	printf("DbCircleList_Clear...\n");
#endif
	// 链表指针非空且链表有数据结点才可清空
	if (sList != NULL && sList->header != NULL)
	{
		// 从编号0（编号从0开始）的结点开始删除
		while (sList->header != sList->header->next)
		{
			TDbCircleListNode *pNode = sList->header;
			sList->header->prior->next = pNode->next;
			sList->header->next->prior = pNode->prior;
			sList->header = sList->header->next;
#ifdef DEBUG
			printf("Clear Node %d .\n", pNode->addr);
#endif
			free(pNode);
			sList->length--;
		}

		// 删除剩余的编号为0的结点
#ifdef DEBUG
		printf("Clear Header Node %d .\n", sList->header->addr);
#endif
		free(sList->header);
		sList->header = NULL;
		sList->length--;
	}

#ifdef DEBUG
	printf("DbCircleList_Clear... Complete.\n");
#endif
}

/* *
 * 函数原型：int DbCircleList_Length(DbCircleList *list)
 * 函数说明：获取单链表长度
 * 参数说明：输入参数：DbCircleList *list
 *			 输出参数：无
 * 返回值：	 获取失败返回-1
 *			 获取成功返回非负数（单链表当前长度）
 * */
int DbCircleList_Length(DbCircleList *list)
{
	int ret = -1;
	TDbCircleList *sList = (TDbCircleList *) list;
#ifdef DEBUG
	printf("DbCircleList_Length... \n");
#endif
	if (sList != NULL)
	{
		ret = sList->length;
	}
#ifdef DEBUG
	(ret == -1) ? printf(" list is NULL. \n") : printf(" %d\n", ret);
#endif
	return ret;
}

/* *
 * 函数原型：int DbCircleList_Insert(DbCircleList *list, DbCircleListNode *node, DbCircleListNodeData *data, int pos)
 * 函数说明：向循环链表中哦功能插入结点
 * 参数说明：输入参数： DbCircleList *list 循环链表指针
 *						DbCircleListNode *node 待插入链表数据地址
 *						int pos 插入位置，从0开始
 *			 输出参数： 无
 * 返回值：	 获取失败返回假（0）
 *			 获取成功返回真（1）
 * */
int DbCircleList_Insert(DbCircleList *list, DbCircleListNode *node, DbCircleListNodeData *data, int pos)
{
	TDbCircleList *sList = (TDbCircleList *) list;
	int ret = (sList != NULL) && (node != NULL);		// 检查链表
#ifdef DEBUG
	printf("DbCircleList_Insert... \n");
#endif
	if (ret)
	{
		// 申请数据结点空间
		TDbCircleListNode *pNew = (TDbCircleListNode *) malloc(sizeof(TDbCircleListNode));
		if (pNew != NULL)
		{
			// 保存数据
			pNew->addr = (unsigned int) node;
			pNew->data = data;
#ifdef DEBUG
			printf("Insert Node data %d ", pNew->addr);
#endif

			// 链表为空默认插入0号位置
			if (sList->header == NULL)
			{
				pNew->next = pNew;
				pNew->prior = pNew;
				sList->header = pNew;
				sList->length++;
#ifdef DEBUG
				printf(" In Header Node.\n");
#endif
			}
			else
			{// 链表不为空时
				int index = (pos >= 0) ? (1) : (-1);
				int halfLength = (sList->length + 1) / 2;
				// 修正插入位置
				pos = index * pos;
				pos = pos % (sList->length + 1);
				pos = (pos < halfLength) ? (pos) : (-(sList->length - pos));
				pos = index * pos;

				if (pos == 0)
				{// 插入0位置
					pNew->next = sList->header;
					sList->header->prior->next = pNew;
					pNew->prior = sList->header->prior;
					sList->header->prior = pNew;
					sList->header = pNew;
				}
				else
				{// 插入其他位置：将新结点插入到pos编号结点的前面
					TDbCircleListNode *current = sList->header;
					if (pos > 0)
					{
						for (index = 0; index < pos; index++)
						{
							current = current->next;
						}
					}
					else
					{
						for (index = -1; index > pos; index--)
						{
							current = current->prior;
						}
					}

					// 插入数据结点到pos编号结点的前面
					pNew->next = current->prior->next;
					current->prior->next = pNew;
					pNew->prior = current->prior;
					current->prior = pNew;
				}
				sList->length++;
#ifdef DEBUG
				printf(" In %d Node \n", pos);
#endif		
			}
		}
		else
		{
			ret = 0;
		}
	}
#ifdef DEBUG
	if (ret == 0)
	  printf(" Failed.\n");
#endif
	return ret;
}

/* *
 * 函数原型：DbCircleListNode *DbCircleList_Get(DbCircleList *list, int pos)
 * 函数说明：获取链表中编号为pos的数据
 * 参数说明：输入参数：DbCircleList *list
 *					   int pos 获取编号，从0开始
 * 返回值：DbCircleListNode * 链表数据地址，为空表示获取失败
 * */
DbCircleListNode * DbCircleList_Get(DbCircleList *list, int pos)
{
	TDbCircleList *sList = (TDbCircleList *) list;
	DbCircleListNode *ret = NULL;
#ifdef DEBUG
	printf("DbCircleList_Get...\n");
#endif
	// 判断链表是否合法，判断获取位置是否合法
	if ((sList != NULL) && (0 <= pos))
	{
		int index = (pos >= 0) ? (1) : (-1);
		int haldLength = (sList->length) / 2;
		TDbCircleListNode *current = sList->header;
		// 修正获取位置编号
		pos = index * pos;
		pos = pos % (sList->length);
		pos = (pos < haldLength) ? (pos) : (-(sList->length - pos));
		pos = index * pos;

		// 查找获取位置
		if (pos >= 0)
		{
			for (index = 0; index < pos; index++)
			{
				current = current->next;
			}
		}
		else
		{
			for (index = -1; index > pos; index--)
			{
				current = current->prior;
			}
		}
#ifdef DEBUG
		printf(" From %d Node", pos);
#endif
		ret = (DbCircleListNode *) (current->addr);
	}
#ifdef DEBUG
	(ret == NULL) ? printf(" Failed.\n") : printf(" %d.\n", (int) ret);
#endif
	return ret;
}

/* *
 * 函数原型：DbCircleListNode * DbCircleList_Delete(DbCircleList *list, int pos)
 * 函数说明：删除链表中哦功能编号为pos的数据，并将其返回
 * 参数说明：输入参数：DbCircleList *list 
 *					   int pos 获取编号，从0开锁
 *			 输出参数：无
 * 返回值：	 DbCircleListNode * 链表数据地址，为空表示删除失败
 * */
DbCircleListNode *DbCircleList_Delete(DbCircleList *list, int pos)
{
	TDbCircleList *sList = (TDbCircleList *) list;
	DbCircleListNode *ret = NULL;
#ifdef DEBUG
	printf(" DbCircleList_Delete...\n");
#endif
	// 判断链表是否合法，判断获取位置是否合法
	if (sList != NULL && (0 <= pos))
	{
		int index = (pos >= 0) ? (1) : (-1);
		int halfLength = (sList->length) / 2;
		TDbCircleListNode *current = sList->header;
		// 修正删除位置编号
		pos = index * pos;
		pos = pos % (sList->length);
		pos = (pos < halfLength) ? (pos) : (-(sList->length - pos));
		pos = index * pos;

		// 查找删除位置
		if (pos >= 0)
		{
			for (index = 0; index < pos; index++)
			{
				current = current->next;
			}
		}
		else
		{
			for (index = -1; index > pos; index--)
			{
				current = current->prior;
			}
		}
		// 保存删除数据
		ret = (DbCircleListNode *) (current->addr);
#ifdef DEBUG
		printf(" From %d Node\n", pos);
#endif
		// 若删除的是编号为0的结点，先修改头指针
		if (pos == 0)
		{
			sList->header = sList->header->next;
		}

		// 删除结点
		current->prior->next = current->next;
		current->next->prior = current->prior;
		free(current);
		sList->length--;

		// 若删除完后，链表长度为0，复位链表
		if (sList->length == 0)
		{
			sList->header = NULL;
		}
	}
#ifdef DEBUG
	(ret == NULL) ? printf(" Failed.\n") : printf(" %d \n", (int) ret);
#endif
	return ret;
}

TDbCircleListNodeData *DbCircleList_GetNodeData(DbCircleListNode *node)
{
	TDbCircleListNode *sNode = (TDbCircleListNode *) node;
	TDbCircleListNodeData *ret = NULL;

	ret = sNode->data;
}
