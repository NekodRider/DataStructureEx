#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <cstring>
#include "BinaryTree.h"

int main(void)
{
	BinaryTree T[10],p,q,tmp;
	Node NodeList[10][128];
	int op = 1, m, num = 0,LR;
	ElemType t, n,val;
	status flag;
	char filename[30],ch;
	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("                 Menu for BinaryTree   \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitBiTree      11. LeftChild\n");
		printf("    	  2. CreateBiTree    12. RightChild\n");
		printf("    	  3. DestroryBiTree  13. LeftSibling\n");
		printf("    	  4. ClearBiTree     14. RightSibling\n");
		printf("    	  5. BiTreeEmpty     15. InsertChild\n");
		printf("    	  6. BiTreeDepth     16. DeleteChild\n");
		printf("    	  7. Root            17. PreOrderTraverse\n");
		printf("    	  8. Value           18. InOrderTraverse\n");
		printf("    	  9. Assign          19. PostOrderTraverse\n");
		printf("    	  10.Parent          20. LevelOrderTraverse\n");
		printf("          21.SaveToFile      22. LoadFromFile\n");
		printf("    	  0. Exit\n");
		printf("          99. ChangePlot     Current Plot %d\n", num);
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~99]:");
		scanf("%d", &op);
		switch (op)
		{
		case 99:
			printf("当前栏位为 %d ,请输入你想切换的栏位号[0-9]：\n", num);
			scanf("%d", &num);
			printf("成功切换到栏位 %d !\n", num);
			getchar();
			getchar();
			break;
		case 1:
			if (InitBiTree(T[num]) == OK)
				printf("二叉树创建成功！\n");
			else
				printf("二叉树创建失败！\n");
			getchar();
			getchar();
			break;
		case 2:
			printf("请输入创建二叉树的definition:\n");
			flag = CreateBiTree(T[num]);
			if (flag == INFEASIBLE)
			{
				printf("二叉树未建立！\n");
			}
			getchar();
			getchar();
			break;
		case 3:
			if (DestroyBiTree(T[num]))
				printf("二叉树销毁成功\n");
			else
				printf("二叉树销毁失败！\n");
			getchar();
			getchar();
			break;
		case 4:
			if (ClearBiTree(T[num]))
				printf("二叉树清空成功!\n");
			getchar();
			getchar();
			break;
		case 5:
			flag = BiTreeEmpty(T[num]);
			if (flag)
			{
				printf("是空表");
			}
			else if (flag == 0)
				printf("不是空表");
			getchar();
			getchar();
			break;
		case 6:
			flag = BiTreeDepth(T[num]);
			if (flag >= 0)
			{
				printf("深度为%d", flag);
			}
			getchar();
			getchar();
			break;
		case 7:
			if (Root(T[num]))
			{
				printf("根节点 %c:%d", Root(T[num])->node_name, Root(T[num])->data);
			}
			getchar();
			getchar();
			break;
		case 8:
			printf("请输入查询结点的key值:\n");
			scanf("%c", &ch);
			tmp = Value(T[num], ch);
			if (tmp)
			{
				printf("节点 %c:%d", tmp->node_name, tmp->data);
			}
			else
			{
				printf("节点未找到！");
			}
			getchar();
			getchar();
			break;
		case 9:
			printf("请输入要赋值的结点key值与data值:\n");
			scanf("%c%d", &ch, &val);
			tmp = Value(T[num], ch);
			if (tmp)
			{
				Assign(T[num], tmp, val);
			}
			else
			{
				printf("节点未找到！");
			}
			getchar();
			getchar();
			break;
		case 10:
			printf("请输入结点key值:\n");
			scanf("%c", &ch);
			tmp = Parent(T[num], ch);
			if (tmp)
			{
				printf("父节点 %c:%d", tmp->node_name, tmp->data);
			}
			else
			{
				printf("节点未找到或不存在父节点！");
			}
			getchar();
			getchar();
			break;
		case 11:
			printf("请输入结点key值:\n");
			scanf("%c", &ch);
			tmp = LeftChild(T[num], ch);
			if (tmp)
			{
				printf("左子节点 %c:%d", tmp->node_name, tmp->data);
			}
			else
			{
				printf("节点未找到或不存在左子节点！");
			}
			getchar();
			getchar();
			break;
		case 12:
			printf("请输入结点key值:\n");
			scanf("%c", &ch);
			tmp = RightChild(T[num], ch);
			if (tmp)
			{
				printf("右子节点 %c:%d", tmp->node_name, tmp->data);
			}
			else
			{
				printf("节点未找到或不存在右子节点！");
			}
			getchar();
			getchar();
			break;
		case 13:
			printf("请输入结点key值:\n");
			scanf("%c", &ch);
			tmp = LeftSibling(T[num], ch);
			if (tmp)
			{
				printf("左兄弟节点 %c:%d", tmp->node_name, tmp->data);
			}
			else
			{
				printf("节点未找到或不存在左兄弟节点！");
			}
			getchar();
			getchar();
			break;
		case 14:
			printf("请输入结点key值:\n");
			scanf("%c", &ch);
			tmp = RightSibling(T[num], ch);
			if (tmp)
			{
				printf("右兄弟节点 %c:%d", tmp->node_name, tmp->data);
			}
			else
			{
				printf("节点未找到或不存在右兄弟节点！");
			}
			getchar();
			getchar();
			break;
		case 15:
			printf("输入key值:");
			scanf("%c", &ch);
			p = Value(T[num], ch);
			if (p == NULL)
			{
				printf("该结点不存在.\n");
				getchar();
				getchar();
				break;
			}
			printf("创建新的二叉树:\n");
			CreateBiTree(q);
			printf("输入插入左右子树(0左1右):");
			scanf("%d", &LR);
			InsertChild(T[num], p, LR, q);
			getchar();
			getchar();
			break;
		case 16:
			printf("输入键值:");
			scanf("%c", &ch);
			p = Value(T[num], ch);
			if (p == NULL)
			{
				printf("该结点不存在.\n");
				getchar();
				getchar();
				break;
			}
			printf("输入删除左右子树(0左1右):");
			scanf("%d", &LR);
			if (LR == 0)
			{
				if (!LeftChild(T[num], ch))
					printf("该结点没有左子树.");
				else
					DeleteChild(T[num], p, LR);
				printf("删除左子树成功.\n");
			}
			else if (LR == 1)
			{
				if (!RightChild(T[num], ch))
					printf("该结点没有右子树.");
				else
					DeleteChild(T[num], p, LR);
				printf("删除右子树成功.\n");
			}
			getchar();
			getchar();
			break;
		case 17:
			if (!T[num])
				printf("二叉树不存在！\n");
			else
			{
				int tmp;
				printf("请选择前序遍历函数功能：\n");
				printf("1.输出每个元素   2.每个元素值增加1\n");
				scanf("%d", &tmp);
				switch (tmp)
				{
				case 1:
					PreOrderTraverse(T[num], ElemDisplay);
					break;
				case 2:
					PreOrderTraverse(T[num], ElemPlus);
					break;
				default:
					printf("操作码错误！\n");
				}
			}
			getchar();
			getchar();
			break;
		case 18:
			if (!T[num])
				printf("二叉树不存在！\n");
			else
			{
				int tmp;
				printf("请选择中序遍历函数功能：\n");
				printf("1.输出每个元素   2.每个元素值增加1\n");
				scanf("%d", &tmp);
				switch (tmp)
				{
				case 1:
					InOrderTraverse(T[num], ElemDisplay);
					break;
				case 2:
					InOrderTraverse(T[num], ElemPlus);
					break;
				default:
					printf("操作码错误！\n");
				}
			}
			getchar();
			getchar();
			break;
		case 19:
			if (!T[num])
				printf("二叉树不存在！\n");
			else
			{
				int tmp;
				printf("请选择前序遍历函数功能：\n");
				printf("1.输出每个元素   2.每个元素值增加1\n");
				scanf("%d", &tmp);
				switch (tmp)
				{
				case 1:
					PostOrderTraverse(T[num], ElemDisplay);
					break;
				case 2:
					PostOrderTraverse(T[num], ElemPlus);
					break;
				default:
					printf("操作码错误！\n");
				}
			}
			getchar();
			getchar();
			break;
		case 20:
			if (!T[num])
				printf("二叉树不存在！\n");
			else
			{
				int tmp;
				printf("请选择层序遍历函数功能：\n");
				printf("1.输出每个元素   2.每个元素值增加1\n");
				scanf("%d", &tmp);
				switch (tmp)
				{
				case 1:
					LevelOrderTraverse(T[num], ElemDisplay);
					break;
				case 2:
					LevelOrderTraverse(T[num], ElemPlus);
					break;
				default:
					printf("操作码错误！\n");
				}
			}
			getchar();
			getchar();
			break;
		case 21:
			//if (!isList(L[num]))
			//	printf("顺序表不存在！\n");

			printf("请输入要存储的文件名：\n");
			scanf("%s", &filename);
			if (SaveToFile(T[num], filename))
				printf("存储成功！\n");
			else
				printf("存储失败！\n");

			getchar();
			getchar();
			break;
		case 22:
			printf("请输入要读取的文件名：\n");
			scanf("%s", &filename);
			if (LoadFromFile(T[num], filename))
				printf("读取成功！\n");
			else
				printf("读取失败！\n");
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

status _Save(BinaryTree T, FILE *fp)
{
	if (T)
	{
		fprintf(fp, "%c", (*T).node_name);
		fprintf(fp, "%d", (*T).data);
		_Save((*T).lchild, fp);
		_Save((*T).rchild, fp);
	}
	else
	{
		char ch = '$';
		fprintf(fp, "%c", ch);
		return NULL;
	}
}

status SaveToFile(BinaryTree T, char *filename)
{
	if (T->data == NULLDATA)
	{
		printf("二叉树不存在！\n");
		return INFEASIBLE;
	}
	FILE *fp;
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("保存数据出错！\n");
		return ERROR;
	}
	_Save(T, fp);
	fclose(fp);
	return OK;
}

status _Load(BinaryTree &T, FILE *fp)
{
	char ch;
	ElemType val;
	fscanf(fp, "%c", &ch);
	if (ch != '$')
	{
		(*T).node_name = ch;
		fscanf(fp, "%d", &val);
		(*T).data = val;
		_Load((*T).lchild, fp);
		_Load((*T).rchild, fp);
	}
	else
	{
		T = NULL;
		return NULL;
	}
}

status LoadFromFile(BinaryTree &T, char *filename)
{
	if (T->data == NULLDATA)
	{
		InitBiTree(T);
	}
	FILE *fp;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("读取数据出错！\n");
		DestroyBiTree(T);
		return ERROR;
	}
	_Load(T, fp);
	fclose(fp);
	return OK;
}

status InitBiTree(BinaryTree &T)
{
	if (T)
	{
		return INFEASIBLE;
	}
	T = (BinaryTree)malloc(sizeof(BinaryTree));
	if (!(&T))
		exit(OVERFLOW);
	return OK;
}

status DestroyBiTree(BinaryTree &T)
{
	if (!T)
	{
		printf("请初始化表！");
		return FALSE;
	}
	if (T->lchild)
		DestroyBiTree(T->lchild);
	if (T->rchild)
		DestroyBiTree(T->rchild);
	free(&T);
	return OK;
}

status CreateBiTree(BinaryTree &T)
{
	if (!T)
	{
		return INFEASIBLE;
	}
	char define;
	scanf("%c", &define);
	if (define == '\n')
		return OK;
	else if (define == '$')
	{
		T = NULL;
		return OK;
	}
	else
	{
		if ((!T) && !(T = (BinaryTree)malloc(sizeof(BinaryTree))))
			exit(OVERFLOW);
		(*T).node_name = define;
		(*T).data = 0;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

status ClearBiTree(BinaryTree &T)
{
	if (!T)
	{
		printf("请初始化表！");
		return FALSE;
	}
	else if ((*T).data == NULLDATA)
	{
		return INFEASIBLE;
	}
	else if (DestroyBiTree(T) && InitBiTree(T))
	{
		return OK;
	}
	else
		return ERROR;
}

status BiTreeEmpty(BinaryTree T)
{
	if (!T)
	{
		printf("请初始化表！");
		return INFEASIBLE;
	}
	else if ((*T).data == NULLDATA)
	{
		return TRUE;
	}
	return FALSE;
}

int BiTreeDepth(BinaryTree T)
{
	if (!T)
	{
		printf("请初始化表！");
		return INFEASIBLE;
	}
	int res = 0, left = BiTreeDepth(T->lchild), right = BiTreeDepth(T->rchild);
	if (left > right)
		res = left + 1;
	else
		res = right + 1;
	return res;
}

BinaryTree Root(BinaryTree T)
{
	if (!T)
	{
		printf("请先初始化！");
		return NULL;
	}
	else
		return T;
}

BinaryTree Value(BinaryTree T, char e)
{
	if (!T)
		return NULL;
	if ((*T).node_name == e)
		return T;
	else
	{
		Value((*T).lchild, e);
		Value((*T).rchild, e);
	}
}

status Assign(BinaryTree T, BinaryTree &e, ElemType value)
{
	e->data = value;
	return OK;
}

BinaryTree Parent(BinaryTree T, char e)
{
	if (!T || !T->lchild || !T->rchild)
		return NULL;
	else if (T->lchild->node_name == e || T->rchild->node_name == e)
		return T;
	else
	{
		Parent(T->lchild, e);
		Parent(T->rchild, e);
	}
}

BinaryTree LeftChild(BinaryTree T, char e)
{
	BinaryTree n = Value(T, e);
	if (n == NULL)
		return NULL;
	else
	{
		if (n->lchild == NULL)
			return NULL;
		return n->lchild;
	}
}

BinaryTree RightChild(BinaryTree T, char e)
{
	BinaryTree n = Value(T, e);
	if (n == NULL)
		return NULL;
	else
	{
		if (n->rchild == NULL)
			return NULL;
		return n->rchild;
	}
}
BinaryTree LeftSibling(BinaryTree T, char e)
{
	if (!T)
	{
		printf("请先初始化二叉树！");
		return NULL;
	}
	else
	{
		BinaryTree n = Parent(T, e);
		if (n == NULL)
			return NULL;
		if (n->lchild->data == e)
			return NULL;
		else
		{
			if (n->lchild == NULL)
				return NULL;
			return n->lchild;
		}
	}
}

BinaryTree RightSibling(BinaryTree T, ElemType e)
{
	if (!T)
	{
		printf("请先初始化二叉树！");
		return NULL;
	}
	else
	{
		BinaryTree n = Parent(T, e);
		if (n == NULL)
			return NULL;
		if (n->rchild->data == e)
			return NULL;
		else
		{
			if (n->rchild == NULL)
				return NULL;
			return n->rchild;
		}
	}
}

status InsertChild(BinaryTree &T, BinaryTree &p, int LR, BinaryTree &c)
{
	if (LR == 0)
	{
		BinaryTree t = p->lchild;
		p->lchild = c;
		c->rchild = t;
	}
	if (LR == 1)
	{
		BinaryTree t = p->rchild;
		p->rchild = c;
		c->rchild = t;
	}
	return OK;
}
/*删除子树*/
status DeleteChild(BinaryTree &T, BinaryTree &p, int LR)
{
	if (LR == 0)
		p->lchild = NULL;
	if (LR == 1)
		p->rchild = NULL;
	return OK;
}
/*前序遍历*/
status PreOrderTraverse(BinaryTree T, status (*visit)(ElemType &a))
{
	if (!T)
		return NULL;
	else
	{
		visit(T->data);
		PreOrderTraverse(T->lchild, visit); //递归访问左子树
		PreOrderTraverse(T->rchild, visit); //递归访问右子树
	}
	return OK;
}
/*中序遍历*/
status InOrderTraverse(BinaryTree T, status (*visit)(ElemType &a))
{
	if (T)
	{
		InOrderTraverse(T->lchild, visit); //递归访问左子树
		visit(T->data);
		InOrderTraverse(T->rchild, visit); //递归访问右子树
	}
	return OK;
}
/*后序遍历*/
status PostOrderTraverse(BinaryTree T, status (*visit)(ElemType &a))
{
	if (T)
	{
		PostOrderTraverse(T->lchild, visit); //递归访问左子树
		PostOrderTraverse(T->rchild, visit); //递归访问右子树
		visit(T->data);
	}
	return OK;
}

status LevelOrderTraverse(BinaryTree T)
{
	SqQueue *queue;
	queue = (SqQueue*)malloc(sizeof(SqQueue));
	InitQueue(queue);
	EnQueue(queue, T);
	BinaryTree tmp;
	while (!QueueEmpty(queue)) {
		DeQueue(queue, tmp);
		printf("%c:%d\n", tmp->node_name,tmp->data);
		if (tmp->lchild)
			EnQueue(queue, tmp->lchild);
		if (tmp->rchild)
			EnQueue(queue, tmp->rchild);
	}
	return OK;
}

status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

status QueueEmpty(SqQueue *Q)
{
	return (Q->front == Q->rear);
}

status EnQueue(SqQueue *Q, BinaryTree e)
{
	Q->data[Q->rear++] = e;
	return OK;
}

status DeQueue(SqQueue *Q, BinaryTree &e)
{
	if (QueueEmpty(Q))
		return ERROR;
	e = Q->data[Q->front++];
	return OK;
}