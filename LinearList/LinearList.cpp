#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <typeinfo>
#include "LinearList.h"

int main(void)
{
	SqList L[10];
	int op = 1, m, num = 0;
	ElemType t, n;
	status flag;
	char filename[30];
	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. IntiaList       9. NextElem\n");
		printf("    	  2. DestroyList     10. ListInsert\n");
		printf("    	  3. ClearList       11. ListDelete\n");
		printf("    	  4. ListEmpty       12. ListTrabverse\n");
		printf("    	  5. ListLength      13. ListDisplay\n");
		printf("    	  6. GetElem         14. LoadFromFile\n");
		printf("    	  7. LocateElem      15. SaveToFile\n");
		printf("    	  8. PriorElem       0. Exit\n");
		printf("          99. ChangeListPlot Current Plot %d\n", num);
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~99]:");
		scanf("%d", &op);
		switch (op)
		{
		case 99:
			printf("当前表栏位为 %d ,请输入你想切换的栏位号[0-9]：\n", num);
			scanf("%d", &num);
			printf("成功切换到栏位 %d !\n", num);
			getchar();
			getchar();
			break;
		case 1:
			if (IntiaList(L[num]) == OK)
				printf("线性表创建成功！\n");
			else
				printf("线性表创建失败！\n");
			getchar();
			getchar();
			break;
		case 2:
			if (!isList(L[num]))
			{
				printf("顺序表不存在！\n");
			}
			else if (DestroyList(L[num]) == OK)
				printf("线性表删除成功！\n");
			else
				printf("线性表删除失败！\n");
			getchar();
			getchar();
			break;
		case 3:
			if (!isList(L[num]))
			{
				printf("顺序表不存在！\n");
			}
			else if (ClearList(L[num]) == OK)
				printf("线性表清空成功！\n");
			else
				printf("线性表清空失败！\n");
			getchar();
			getchar();
			break;
		case 4:
			if (!isList(L[num]))
			{
				printf("顺序表不存在！\n");
			}
			else if (ListEmpty(L[num]) == TRUE)
				printf("线性表是空表！\n");
			else
				printf("线性表不是空表！\n");
			getchar();
			getchar();
			break;
		case 5:
			if (!isList(L[num]))
				printf("顺序表不存在！\n");
			else
				printf("List Length is %d.\n", ListLength(L[num]));
			getchar();
			getchar();
			break;
		case 6:
			if (!isList(L[num]))
				printf("顺序表不存在！\n");
			else
			{
				printf("请输入要获取的元素的序号：\n");
				scanf("%d", &m);
				GetElem(L[num], m, n);
				printf("The No.%d Element is %d.\n", m, n);
			}
			getchar();
			getchar();
			break;
		case 7:
			if (!isList(L[num]))
				printf("顺序表不存在！\n");
			else
			{
				int tmp;
				printf("请选择比较函数功能：\n");
				printf("1.大于输入值   2.小于输入值  3.与输入值相等\n");
				scanf("%d", &tmp);
				switch (tmp)
				{
				case 1:
					printf("请输入用于比较的元素值：\n");
					scanf("%d", &n);
					if ((flag = LocateElem(L[num], n, Greater)))
						printf("Found it, the index is %d.\n", flag);
					else
						printf("Can't find it!\n");
					break;
				case 2:
					printf("请输入用于比较的元素值：\n");
					scanf("%d", &n);
					if ((flag = LocateElem(L[num], n, Less)))
						printf("Found it, the index is %d.\n", flag);
					else
						printf("Can't find it!\n");
					break;
				case 3:
					printf("请输入你要寻找的元素值：\n");
					scanf("%d", &n);
					if ((flag = LocateElem(L[num], n, Equal)))
						printf("Found it, the index is %d.\n", flag);
					else
						printf("Can't find it!\n");
					break;
				default:
					printf("操作码错误！\n");
				}
			}
			getchar();
			getchar();
			break;
		case 8:
			if (!isList(L[num]))
				printf("顺序表不存在！\n");
			else
			{
				printf("\n请输入该元素：\n");
				scanf("%d", &t);
				flag = PriorElem(L[num], t, n);
				if (flag == TRUE)
					printf("The PriorElem of Element %d is %d.\n", t, n);
				else if (flag == OVERFLOW)
					printf("It's the first element!\n");
				else if (flag == INFEASIBLE)
					;
				else
					printf("Can't find the element!\n");
			}
			getchar();
			getchar();
			break;
		case 9:
			if (!isList(L[num]))
				printf("顺序表不存在！\n");
			else
			{
				printf("\n请输入该元素：\n");
				scanf("%d", &t);
				flag = NextElem(L[num], t, n);
				if (flag == TRUE)
					printf("The NextElem of Element %d is %d.\n", t, n);
				else if (flag == OVERFLOW)
					printf("It's the last element!\n");
				else if (flag == INFEASIBLE)
					;
				else
					printf("Can't find the element!\n");
			}
			getchar();
			getchar();
			break;
		case 10:
			if (!isList(L[num]))
				printf("顺序表不存在！\n");
			else
			{
				printf("请输入要插入的元素位置和元素值:\n");
				scanf("%d%d", &m, &n);
				if (ListInsert(L[num], m, n) == OK)
					printf("插入元素成功！\n");
				else
					printf("插入元素失败！\n");
			}
			getchar();
			getchar();
			break;
		case 11:
			if (!isList(L[num]))
				printf("顺序表不存在！\n");
			else
			{
				printf("请输入要删除的元素位置:\n");
				scanf("%d", &m);
				if (ListDelete(L[num], m, n) == OK)
					printf("删除元素成功！删除值为 %d.\n", n);
				else
					printf("删除元素失败！\n");
			}
			getchar();
			getchar();
			break;
		case 12:
			if (!isList(L[num]))
				printf("顺序表不存在！\n");
			else
			{
				int tmp;
				printf("请选择遍历函数功能：\n");
				printf("1.输出每个元素   2.每个元素值增加1\n");
				scanf("%d", &tmp);
				switch (tmp)
				{
				case 1:
					ListTrabverse(L[num], ElemDisplay);
					break;
				case 2:
					ListTrabverse(L[num], ElemPlus);
					break;
				default:
					printf("操作码错误！\n");
				}
			}
			getchar();
			getchar();
			break;
		case 13:
			if (!isList(L[num]))
				printf("顺序表不存在！\n");
			else
				ListDisplay(L[num]);
			getchar();
			getchar();
			break;
		case 14:
			printf("请输入要读取的文件名：\n");
			scanf("%s", &filename);
			if (LoadFromFile(L[num], filename))
				printf("读取成功！\n");
			else
				printf("读取失败！\n");
			getchar();
			getchar();
			break;
		case 15:
			if (!isList(L[num]))
				printf("顺序表不存在！\n");
			else
			{
				printf("请输入要存储的文件名：\n");
				scanf("%s", &filename);
				if (SaveToFile(L[num], filename))
					printf("存储成功！\n");
				else
					printf("存储失败！\n");
			}
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

status isList(SqList L)
{
	if (L.listsize != NULL)
		return TRUE;
	else
		return FALSE;
}

status SaveToFile(SqList L, char *filename)
{
	if (!isList(L))
	{
		printf("顺序表不存在！\n");
		return INFEASIBLE;
	}
	FILE *fp;
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("保存数据出错！\n");
		return ERROR;
	}
	fwrite(&(L.length), sizeof(int), 1, fp);
	fwrite(&(L.listsize), sizeof(int), 1, fp);
	fwrite(L.elem, sizeof(ElemType), L.length, fp);
	fclose(fp);
	return OK;
}

status LoadFromFile(SqList &L, char *filename)
{
	if (!isList(L))
	{
		IntiaList(L);
	}
	FILE *fp;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("读取数据出错！\n");
		DestroyList(L);
		return ERROR;
	}
	fread(&(L.length), sizeof(int), 1, fp);
	fread(&(L.listsize), sizeof(int), 1, fp);
	fread(L.elem, sizeof(ElemType), L.length, fp);
	fclose(fp);
	return OK;
}

status Equal(ElemType a, ElemType b)
{
	if (a == b)
		return TRUE;
	else
		return FALSE;
}
status Greater(ElemType a, ElemType b)
{
	if (a > b)
		return TRUE;
	else
		return FALSE;
}
status Less(ElemType a, ElemType b)
{
	if (a < b)
		return TRUE;
	else
		return FALSE;
}

status ElemDisplay(ElemType &a)
{
	printf("This element is %d.\n", a);
	return OK;
}
status ElemPlus(ElemType &a)
{
	a++;
	return OK;
}

status ListDisplay(SqList L)
{
	int i;
	if (!isList(L))
	{
		printf("顺序表不存在！\n");
		return INFEASIBLE;
	}
	if (!ListEmpty(L))
	{
		printf("List Length: %d\n", L.length);
		printf("List Size: %d \n", L.listsize);
		printf("List Element(Index Value):\n");
		for (i = 0; i < L.length; i++)
			printf("%d. %d\n", i + 1, L.elem[i]);
	}
	else
	{
		printf("Empty List!\n");
	}
	return OK;
}

status IntiaList(SqList &L)
{
	if (isList(L))
	{
		printf("顺序表已存在！\n");
		return INFEASIBLE;
	}
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

status DestroyList(SqList &L)
{
	if (!isList(L))
	{
		printf("顺序表不存在！\n");
		return INFEASIBLE;
	}
	free(L.elem);
	L.length = NULL;
	L.listsize = NULL;
	return OK;
}

status ClearList(SqList &L)
{
	if (!isList(L))
	{
		printf("顺序表不存在！\n");
		return INFEASIBLE;
	}
	ElemType *p;
	p = L.elem;
	L.listsize = NULL;
	IntiaList(L);
	free(p);
	return OK;
}

status ListEmpty(SqList L)
{
	if (!isList(L))
	{
		printf("顺序表不存在！\n");
		return INFEASIBLE;
	}
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

int ListLength(SqList L)
{
	if (!isList(L))
	{
		printf("顺序表不存在！\n");
		return INFEASIBLE;
	}
	return L.length;
}

status GetElem(SqList L, int i, ElemType &e)
{
	if (!isList(L))
	{
		printf("顺序表不存在！\n");
		return INFEASIBLE;
	}
	else if (i > L.length)
	{
		printf("超过顺序表长度！\n");
		return OVERFLOW;
	}
	e = L.elem[i - 1];
	return OK;
}

status LocateElem(SqList L, ElemType e, status (*target)(ElemType a, ElemType b))
{
	if (!isList(L))
	{
		printf("顺序表不存在！\n");
		return INFEASIBLE;
	}
	if (!ListEmpty(L))
	{
		int i;
		for (i = 0; i < L.length; i++)
		{
			if (target(L.elem[i], e))
			{
				return i + 1;
			}
		}
	}
	return ERROR;
}

status PriorElem(SqList L, ElemType cur, ElemType &pre_e)
{
	if (!isList(L))
	{
		printf("顺序表不存在！\n");
		return INFEASIBLE;
	}
	int i;
	if (!ListEmpty(L))
	{
		for (i = 0; i < L.length; i++)
		{
			if (L.elem[i] == cur)
			{
				if (i == 0)
					return OVERFLOW;
				pre_e = L.elem[i - 1];
				return TRUE;
			}
		}
		return FALSE;
	}
	return ERROR;
}
status NextElem(SqList L, ElemType cur, ElemType &next_e)
{
	if (!isList(L))
	{
		printf("顺序表不存在！\n");
		return INFEASIBLE;
	}
	int i;
	if (!ListEmpty(L))
	{
		for (i = 0; i < L.length; i++)
		{
			if (L.elem[i] == cur)
			{
				if (i == L.length - 1)
					return OVERFLOW;
				next_e = L.elem[i + 1];
				return TRUE;
			}
		}
		return FALSE;
	}
	return ERROR;
}

status ListInsert(SqList &L, int i, ElemType e)
{
	if (!isList(L))
	{
		printf("顺序表不存在！\n");
		return INFEASIBLE;
	}
	if (i <= 0)
	{
		printf("输入位置有误！\n");
		return OVERFLOW;
	}
	int j, k;
	ElemType *node;
	if (L.length == L.listsize)
	{
		L.elem = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!L.elem)
			exit(OVERFLOW);
		L.listsize += LISTINCREMENT;
	}
	if (i > L.length + 1)
		i = L.length + 1;
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
	if (!isList(L))
	{
		printf("顺序表不存在！\n");
		return INFEASIBLE;
	}
	else if (ListEmpty(L))
	{
		printf("顺序表为空！\n");
		return ERROR;
	}
	else if (i <= 0 || i > L.length + 1)
	{
		printf("输入位置有误！\n");
		return OVERFLOW;
	}
	int j;
	e = L.elem[i - 1];
	for (j = i - 1; j < L.length - 1; j++)
	{
		L.elem[j] = L.elem[j + 1];
	}
	L.length--;
	return OK;
}

status ListTrabverse(SqList L, status (*target)(ElemType &a))
{
	if (!isList(L))
	{
		printf("顺序表不存在！\n");
		return INFEASIBLE;
	}
	int i;
	if (ListEmpty(L))
	{
		printf("该表是空表！\n");
		return ERROR;
	}
	for (i = 0; i < L.length; i++)
		(*target)(L.elem[i]);
	return TRUE;
}
