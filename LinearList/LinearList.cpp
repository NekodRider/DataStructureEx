// ⑴初始化表：函数名称是InitaList(L)；初始条件是线性表L不存在已存在；操作结果是构造一个空的线性表。
// ⑵销毁表：函数名称是DestroyList(L)；初始条件是线性表L已存在；操作结果是销毁线性表L。
// ⑶清空表：函数名称是ClearList(L)；初始条件是线性表L已存在；操作结果是将L重置为空表。
// ⑷判定空表：函数名称是ListEmpty(L)；初始条件是线性表L已存在；操作结果是若L为空表则返回TRUE,否则返回FALSE。
// ⑸求表长：函数名称是ListLength(L)；初始条件是线性表已存在；操作结果是返回L中数据元素的个数。
// ⑹获得元素：函数名称是GetElem(L,i,e)；初始条件是线性表已存在，1≤i≤ListLength(L)；操作结果是用e返回L中第i个数据元素的值。
// ⑺查找元素：函数名称是LocateElem(L,e,compare())；初始条件是线性表已存在；操作结果是返回L中第1个与e满足关系compare（）关系的数据元素的位序，若这样的数据元素不存在，则返回值为0。
// ⑻获得前驱：函数名称是PriorElem(L,cur_e,pre_e)；初始条件是线性表L已存在；操作结果是若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。
// ⑼获得后继：函数名称是NextElem(L,cur_e,next_e)；初始条件是线性表L已存在；操作结果是若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。
// ⑽插入元素：函数名称是ListInsert(L,i,e)；初  始条件是线性表L已存在，1≤i≤ListLength(L)+1；操作结果是在L的第i个位置之前插入新的数据元素e。
// ⑾删除元素：函数名称是ListDelete(L,i,e)；初始条件是线性表L已存在且非空，1≤i≤ListLength(L)；操作结果：删除L的第i个数据元素，用e返回其值。
// ⑿遍历表：函数名称是ListTraverse(L,visit())，初始条件是线性表L已存在；操作结果是依次对L的每个数据元素调用函数visit()。

// 演示系统可选择实现线性表的文件形式保存。其中，①需要设计文件数据记录格式，以高效保存线性表数据逻辑结构(D,{R})的完整信息；
// ②需要设计线性表文件保存和加载操作合理模式。附录B提供了文件存取的方法。
// 演示系统可选择实现多个线性表管理。

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
} SqList;

status IntiaList(SqList &L);
status DestroyList(SqList &L);
status ClearList(SqList &L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L, int i, ElemType &e);
status LocateElem(SqList L, ElemType e); //简化过
status PriorElem(SqList L, ElemType cur, ElemType &pre_e);
status NextElem(SqList L, ElemType cur, ElemType &next_e);
status ListInsert(SqList &L, int i, ElemType e);
status ListDelete(SqList &L, int i, ElemType &e);
status ListTrabverse(SqList L); //简化过
status ListDisplay(SqList L);
/*--------------------------------------------*/
int main(void)
{
	SqList L;
	int op = 1, m, n;
	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. IntiaList       7. LocateElem\n");
		printf("    	  2. DestroyList     8. PriorElem\n");
		printf("    	  3. ClearList       9. NextElem \n");
		printf("    	  4. ListEmpty       10. ListInsert\n");
		printf("    	  5. ListLength      11. ListDelete\n");
		printf("    	  6. GetElem         12. ListTrabverse\n");
		printf("    	  0. Exit            13. ListDisplay\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~13]:");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			if (IntiaList(L) == OK)
				printf("线性表创建成功！\n");
			else
				printf("线性表创建失败！\n");
			getchar();
			getchar();
			break;
		case 2:
			if (DestroyList(L) == OK)
				printf("线性表删除成功！\n");
			else
				printf("线性表删除失败！\n");
			getchar();
			getchar();
			break;
		case 3:
			if (ClearList(L) == OK)
				printf("线性表清空成功！\n");
			else
				printf("线性表清空失败！\n");
			getchar();
			getchar();
			break;
		case 4:
			if (ListEmpty(L) == TRUE)
				printf("线性表是空表！\n");
			else
				printf("线性表不是空表！\n");
			getchar();
			getchar();
			break;
		case 5:
			printf("List Length is %d.\n", ListLength(L));
			getchar();
			getchar();
			break;
		case 6:
			printf("\n----GetElem功能待实现！\n");
			getchar();
			getchar();
			break;
		case 7:
			printf("\n----LocateElem功能待实现！\n");
			getchar();
			getchar();
			break;
		case 8:
			printf("\n----PriorElem功能待实现！\n");
			getchar();
			getchar();
			break;
		case 9:
			printf("\n----NextElem功能待实现！\n");
			getchar();
			getchar();
			break;
		case 10:
			printf("请输入要插入的元素位置和元素值:\n");
			scanf("%d%d", &m, &n);
			if (ListInsert(L, m, n) == OK)
				printf("插入元素成功！\n");
			else
				printf("插入元素失败！\n");
			getchar();
			getchar();
			break;
		case 11:
			printf("请输入要删除的元素位置:\n");
			scanf("%d", &m);
			if (ListDelete(L, m, n) == OK)
				printf("删除元素成功！删除值为 %d.\n", n);
			else
				printf("删除元素失败！\n");
			getchar();
			getchar();
			break;
		case 12:
			//printf("\n----ListTrabverse功能待实现！\n");
			if (!ListTrabverse(L))
				printf("线性表是空表！\n");
			getchar();
			getchar();
			break;
		case 13:
			ListDisplay(L);
			getchar();
			getchar();
			break;
		case 0:
			break;
		}
	}
	printf("欢迎下次再使用本系统！\n");
	return 0;
}

status ListDisplay(SqList L)
{
	int i;
	if (!ListEmpty(L))
	{
		printf("List Length: %d\n", L.length);
		printf("List Size: %d \n", L.listsize);
		printf("List Element(Index Value):\n");
		for (i = 0; i < L.length; i++)
			printf("%d. %d\n", i, L.elem[i]);
	}
	else
	{
		printf("Empty List!\n");
	}
	return OK;
}

status IntiaList(SqList &L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

status DestroyList(SqList &L)
{
	free(L.elem);
	L.length = NULL;
	L.listsize = NULL;
	return OK;
}

status ClearList(SqList &L)
{
	ElemType *p;
	p = L.elem;
	L.elem = nullptr;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	free(p);
	return OK;
}

status ListEmpty(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

status ListLength(SqList L)
{
	return L.length;
}

status GetElem(SqList L, int i, ElemType &e)
{
	e = L.elem[i - 1];
	return OK;
}

status LocateElem(SqList L, ElemType e); //简化过
status PriorElem(SqList L, ElemType cur, ElemType &pre_e);
status NextElem(SqList L, ElemType cur, ElemType &next_e);

status ListInsert(SqList &L, int i, ElemType e)
{
	int j, k;
	ElemType *node;
	if (L.length == L.listsize)
	{
		L.elem = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!L.elem)
			exit(OVERFLOW);
		L.listsize += LISTINCREMENT;
	}
	for (j = L.length; j >= i; j--)
	{
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

status ListDelete(SqList &L, int i, ElemType &e)
{
	int j;
	e = L.elem[i - 1];
	for (j = i - 1; j < L.length - 1; j++)
	{
		L.elem[j] = L.elem[j + 1];
	}
	L.length--;
	return OK;
}

status ListTrabverse(SqList L)
{
	int i;
	printf("\n-----------all elements -----------------------\n");
	for (i = 0; i < L.length; i++)
		printf("%d ", L.elem[i]);
	printf("\n------------------ end ------------------------\n");
	return L.length;
}
